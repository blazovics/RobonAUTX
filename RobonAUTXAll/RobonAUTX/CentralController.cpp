/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "CentralController.h"
#include "SkillRaceEvent.h"
#include "SpeedRaceEvent.h"
#include <QDebug>

#include "Configuration.h"
#include <QDir>

/**
 * CentralController implementation
 */


CentralController::CentralController() {
    //FIXME Consider change to unique
    databaseManager = std::make_shared<DatabaseManager>();

    QString bssUrlString = "";

    const Configuration& config = Configuration::GetInstance();

    if(config.IsKeyAvailable("MainSystemSettings","BSSServerAddress")){
        bssUrlString = QString::fromStdString(config.GetStringValue("MainSystemSettings","BSSServerAddress"));
    }
    bssManager.connectToServer(QUrl(bssUrlString));
    connect(&bssManager, SIGNAL(connectionActive(bool)), this,SLOT(bssConnected(bool)));
}

CentralController::~CentralController()
{

}

void CentralController::InitSkillRace(quint32 teamID)
{
    this->raceEvent.reset();
    this->raceEvent = std::make_unique<SkillRaceEvent>(databaseManager);
    this->raceEvent->InitRace(teamID);

    emit ResetSkillGates();
    emit SkillRaceInitiated(teamID);
}

void CentralController::InitSpeedRace(quint32 teamID)
{
    this->raceEvent.reset();
    this->raceEvent = std::make_unique<SpeedRaceEvent>(databaseManager);
    this->raceEvent->InitRace(teamID);

    QList<SpeedRaceResult> result = databaseManager->GetSpeedRaceResults(false);
    emit updateInRaceSpeedResults(result);

    emit SpeedRaceInitiated(teamID);
}

void CentralController::UpdateVotesForTeam(quint32 teamID, quint32 voteCount)
{
    databaseManager->updateVoteForTeam(teamID,voteCount);

    emit VotesUpdated(teamID, voteCount);
}

void CentralController::ManualMeasureReceived()
{
    SpeedRaceEvent* currentEvent = dynamic_cast<SpeedRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        quint32 time = currentEvent->ManualTimeReceived();
        emit ManualLapTimeUpdated(time);
    }
    else {
        //throw std::bad_cast();
    }
}

void CentralController::LaserMeasureReceived(quint32 time)
{
    SpeedRaceEvent* currentEvent = dynamic_cast<SpeedRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        quint32 time = currentEvent->LaserTimeReceived();
        emit LaserLapTimeUpdated(time);
    }
    else {
        //throw std::bad_cast();
    }
}

void CentralController::TimeSourceForLapSelected(TimeSourceType timeSource)
{
    SpeedRaceEvent* currentEvent = dynamic_cast<SpeedRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        quint32 lapTime = currentEvent->FinishLap(timeSource);
        quint32 finishedLapIndex = currentEvent->GetFinishedLapCount();

        emit SpeedLapCompleted(finishedLapIndex,lapTime);

        bssManager.sendSpeedLapFinished(currentEvent->GetTeamID(),finishedLapIndex,lapTime);
        bssManager.sendStartTimer();
    }
    else {
        //throw std::bad_cast();
    }
}

void CentralController::UpdateCheckpointState(quint32 checkpointID, bool checked, bool forced)
{
    SkillRaceEvent* currentEvent = dynamic_cast<SkillRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        qDebug()<<"Update Checkpoint state for #" << checkpointID <<"to "<< checked;
        if(currentEvent->UpdateCheckpoint(checkpointID,checked,forced))
        {
            emit CheckpointStateUpdated(checkpointID,checked);
        }
        emit SkillPointUpdated(currentEvent->GetActualPoints(),currentEvent->GetTimeCredit());

        int checkpointPoint = 2;
        if(checked == false)
        {
            checkpointPoint = -2;
        }

        bssManager.sendSkillResultChanged(currentEvent->GetTeamID(),qint32(currentEvent->getRemainingTime()),currentEvent->GetTimeCredit(),currentEvent->GetActualPoints(),checkpointPoint);
    }
    else {

        ////throw std::bad_cast();
    }
}

void CentralController::StartRace()
{
    if(this->raceEvent->getType() == Skill)
    {
        emit StartSkillGate();
        qDebug()<<"StartSkillGate";
    }
    else{
        this->raceEvent->StartRace();
        emit RaceStarted();
        emit StartSafetyCar();
        bssManager.sendStartTimer();
    }
}

void CentralController::FinishRace(bool aborted)
{
    if(this->raceEvent == nullptr)
        return;

    emit RaceFinished(aborted);

    if(aborted)
    {
        this->raceEvent->AbortRace();
    }
    else {
        this->raceEvent->SaveRace();
    }

    if(this->raceEvent->getType() == Skill)
    {
        emit ClearSkillGates();
        SkillRaceEvent* currentEvent = dynamic_cast<SkillRaceEvent*>(this->raceEvent.get());
        if(currentEvent != nullptr && aborted == false)
        {
            this->InitSpeedRace(currentEvent->GetTeamID());
        }

        bssManager.sendSkillTimerStopped();
    }
    else{
        emit StartSafetyCar();
        bssManager.sendStopTimer();
    }
    bssManager.sendSpeedResults(databaseManager->GetSpeedRaceResults(false),false);
}

void CentralController::TeamListRequested()
{
    QList<Team> teams = this->databaseManager->getTeamList();
    emit TeamListUpdated(teams);
}

void CentralController::VechicleStartAchieved(bool achieved)
{
    SkillRaceEvent* currentEvent = dynamic_cast<SkillRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        currentEvent->SetStartSucceeded(achieved);
        emit VehicleStartConfirmed(achieved);
        emit SkillPointUpdated(currentEvent->GetActualPoints(),currentEvent->GetTimeCredit());

        bssManager.sendSkillResultChanged(currentEvent->GetTeamID(),qint32(currentEvent->getRemainingTime()),currentEvent->GetTimeCredit(),currentEvent->GetActualPoints(),0);
    }
    else {
        //throw std::bad_cast();
    }
}

void CentralController::LaneChangeAchieved(bool achieved)
{
    SkillRaceEvent* currentEvent = dynamic_cast<SkillRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        currentEvent->SetLanChangeSuccess(achieved);
        emit LaneChangeConfirmed(achieved);
        emit SkillPointUpdated(currentEvent->GetActualPoints(),currentEvent->GetTimeCredit());

        bssManager.sendSkillResultChanged(currentEvent->GetTeamID(),qint32(currentEvent->getRemainingTime()),currentEvent->GetTimeCredit(),currentEvent->GetActualPoints(),0);

    }
    else {
        //throw std::bad_cast();
    }
}

void CentralController::SafetyCarFollowed(bool achieved)
{
    SpeedRaceEvent* currentEvent = dynamic_cast<SpeedRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        currentEvent->SetSafetyCarFollowed(achieved);
        emit SafetyCarFollowingConfirmed(achieved);


        //bssManager.sendSpeedPointChanged(currentEvent->GetTeamID(),currentEvent->get)
    }
    else {
        //throw std::bad_cast();
    }
}

void CentralController::SafetyCarOvertaken(quint32 value)
{
    SpeedRaceEvent* currentEvent = dynamic_cast<SpeedRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        currentEvent->SetSafetyCarOvertaken(value);
        emit SafetyCarOvertakeConfirmed(value);
    }
    else {
        //throw std::bad_cast();
    }
}

void CentralController::ModifyTouchCount(quint32 touchCount)
{
    SpeedRaceEvent* currentEvent = dynamic_cast<SpeedRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        quint32 updatedTouchCount = currentEvent->ModifyTouchCount(touchCount);
        emit TouchCountModified(updatedTouchCount);
    }
    else {
        //throw std::bad_cast();
    }
}

void CentralController::ShowSpeedResults(bool isJunior, quint32 fromPos)
{
    emit showSpeedResults(this->databaseManager->GetSpeedRaceResults(isJunior),isJunior,fromPos);
}

void CentralController::ShowSkillResults(quint32 fromPos)
{
    emit showSkillResults(this->databaseManager->GetSkillRaceResults(),fromPos);
}

void CentralController::ShowFinalResults(bool isJunior, quint32 fromPos)
{
    emit showFinalResults(this->databaseManager->GetFinalResults(isJunior),isJunior,fromPos);
}

void CentralController::ShowFinalResultAtPosition(bool isJunior, quint32 position)
{
    emit showFinalResultAtPosition(this->databaseManager->GetFinalResults(isJunior),isJunior,position);
}

void CentralController::ShowVotesResults(quint32 fromPos)
{
    emit showVotesResults(this->databaseManager->GetVoteResults(),fromPos);
}

void CentralController::ShowQualificationResults(quint32 fromPos)
{
    emit showQualificationResults(this->databaseManager->GetQualificationResults(),fromPos);
}

void CentralController::ShowInterRaceScreen()
{
    emit showInterRaceScreen();
}

void CentralController::SkillGateStarted()
{
    if(this->raceEvent->getType() == Skill)
    {
        SkillRaceEvent* currentEvent = dynamic_cast<SkillRaceEvent*>(this->raceEvent.get());
        if(currentEvent != nullptr)
        {
            bssManager.sendSkillTimerStarted();
            emit SkillPointUpdated(currentEvent->GetActualPoints(),currentEvent->GetTimeCredit());
        }
        this->raceEvent->StartRace();
        emit RaceStarted();
    }
}

void CentralController::PauseRaceTimer()
{
    if(this->raceEvent->getType() == Skill)
    {
        SkillRaceEvent* currentEvent = dynamic_cast<SkillRaceEvent*>(this->raceEvent.get());
        if(currentEvent != nullptr)
        {
            bssManager.sendSkillTimerPaused(qint32(currentEvent->getRemainingTime()));
        }
        this->raceEvent->PauseRaceTimer();
        emit RaceTimerPaused();
    }
}

void CentralController::ResumeRaceTimer()
{
    if(this->raceEvent->getType() == Skill)
    {
        SkillRaceEvent* currentEvent = dynamic_cast<SkillRaceEvent*>(this->raceEvent.get());
        if(currentEvent != nullptr)
        {
            bssManager.sendSkillTimerResumed(qint32(currentEvent->getRemainingTime()));
        }
        this->raceEvent->ResumeRaceTimer();
        emit RaceTimerResumed();
    }
}

void CentralController::UpdateBSS()
{
    bssManager.sendVotePoints(databaseManager->GetVoteResults());
    bssManager.sendJuniorFinalResults(databaseManager->GetFinalResults(true));
    bssManager.sendFinalResults(databaseManager->GetFinalResults(false));

    saveResultsToFile();
}

void CentralController::saveResultsToFile()
{
    QString path = QDir::home().filePath("results.csv");
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            qDebug()<<file.errorString();
            return;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");

    out<<QString::fromUtf8("Helyezés")<<"\t"<<QString::fromUtf8("Csapatnév")<<"\t"<<QString::fromUtf8("Összpontszám")<<"\t"<<QString::fromUtf8("Ügyességi")<<"\t"<<QString::fromUtf8("Gyorsasági")<<"\t"<<QString::fromUtf8("Gyorsasági Idő")<<"\t"<<QString::fromUtf8("Közönség")<<"\t"<<QString::fromUtf8("Kvalifikáció")<<"\n";

    QList<FinalResult> teamResults = databaseManager->GetFinalResults(true);

    QTime time = QTime(0,0);
    QTime t;

    for(int i=0; i < teamResults.size(); i++)
    {
        FinalResult res = teamResults.at(i);

        t = time.addMSecs(int(res.speedTime));

        out<<res.position<<"\t";
        out<<res.teamName<<"\t";
        out<<res.finalPoint<<"\t";
        out<<res.skillPoint<<"\t";
        out<<res.speedPoint<<"\t";
        out<<t.toString("mm:ss.zzz")<<"\t";
        out<<res.votePoint<<"\t";
        out<<res.qualificationPoint<<"\n";
    }

    out<<"\n";

    QList<FinalResult> teamResults2 = databaseManager->GetFinalResults(false);

    for(int i=0; i < teamResults2.size(); i++)
    {
        FinalResult res = teamResults2.at(i);

        t = time.addMSecs(int(res.speedTime));

        out<<res.position<<"\t";
        out<<res.teamName<<"\t";
        out<<res.finalPoint<<"\t";
        out<<res.skillPoint<<"\t";
        out<<res.speedPoint<<"\t";
        out<<t.toString("mm:ss.zzz")<<"\t";
        out<<res.votePoint<<"\t";
        out<<res.qualificationPoint<<"\n";
    }
}

void CentralController::bssConnected(bool alive)
{
    if(alive)
    {
        bssManager.sendQualificationPoints(databaseManager->GetQualificationResults());
    }
}
