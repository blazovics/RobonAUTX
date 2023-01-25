/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "CentralController.h"
#include "RaceEvent.h"
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

    bssCommunicator = new BSSCommunicator(bssUrlString);

    connect(&bssManager, SIGNAL(connectionActive(bool)), this,SLOT(bssConnected(bool)));

    //DEBUG


}

CentralController::~CentralController()
{
    delete  bssCommunicator;
}

void CentralController::InitSkillRace(quint32 teamID)
{
    this->raceEvent.reset();
    this->raceEvent = std::make_unique<SkillRaceEvent>(databaseManager, this);
    this->raceEvent->InitRace(teamID);

    emit ResetSkillGates();
    emit SkillRaceInitiated(teamID);
}

void CentralController::InitSpeedRace(quint32 teamID)
{
    this->raceEvent.reset();
    this->raceEvent = std::make_unique<SpeedRaceEvent>(databaseManager, this);
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

        bssCommunicator->SendSpeedLapAchieved(currentEvent->GetTeamID(), currentEvent->getFinishedLapTimes());
        bssCommunicator->SendStartSpeedTimer(currentEvent->GetCurrentTimeWithOffset());
    }
    else {
        //throw std::bad_cast();
    }
}

void CentralController::UpdateCheckpointState(quint32 checkpointID, CheckpointState newState, bool forced)
{
    SkillRaceEvent* currentEvent = dynamic_cast<SkillRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        //TODO: checkpoint update logic!!


        qDebug()<<"Update Checkpoint state for #" << checkpointID <<"to "<< newState;
        if(currentEvent->UpdateCheckpoint(checkpointID,newState,forced))
        {
            emit CheckpointStateUpdated(checkpointID,newState);
        }

        emit SkillPointUpdated(currentEvent->GetActualPoints(),currentEvent->GetTimeCredit());

        if(currentEvent->IsLastCheckpointReached())
        {
            emit SkillRaceLastCheckpointReached();
        }

        #warning "BSS ISSUE - NEED URGENT RESOLVE!"
        int checkpointPoint = 2;
        if(newState == false)
        {
            checkpointPoint = -2;
        }

        bssCommunicator->SendSkillScoreUpdated(currentEvent->GetTeamID(),currentEvent->GetTimeCredit(),currentEvent->getRemainingTime(),checkpointPoint,currentEvent->GetActualAbsolutePoints());
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

        SkillRaceEvent* currentEvent = dynamic_cast<SkillRaceEvent*>(this->raceEvent.get());
        if(currentEvent != nullptr && aborted == false)
        {
            bssCommunicator->SendSkillRaceFinished(currentEvent->GetTeamID(),currentEvent->GetActualPoints());
            bssCommunicator->SendStopSkillTimer(0);
            this->InitSpeedRace(currentEvent->GetTeamID());
        }
        else
        {
            emit ClearSkillGates();
        }
    }
    else{
        emit StartSafetyCar();
        emit ClearSkillGates();

        bssCommunicator->SendStopSpeedimer(0);
    }
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

        //TODO BSS
        bssCommunicator->SendSkillScoreUpdated(currentEvent->GetTeamID(),currentEvent->GetTimeCredit(),currentEvent->getRemainingTime(),0,currentEvent->GetActualAbsolutePoints());
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
        currentEvent->SetLaneChangeSuccess(achieved);

        if(achieved)
        {
            emit SkillRaceTimeIsUp();
        }

        emit LaneChangeConfirmed(achieved,currentEvent->GetLaneChangeTime());
        emit SkillPointUpdated(currentEvent->GetActualPoints(),currentEvent->GetTimeCredit());

        bssCommunicator->SendSkillScoreUpdated(currentEvent->GetTeamID(),currentEvent->GetTimeCredit(),currentEvent->getRemainingTime(),currentEvent->GetLaneChangePoint(),currentEvent->GetActualAbsolutePoints());

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

       bssCommunicator->SendSafetyCarFollowed(currentEvent->GetTeamID(),achieved);
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

        bssCommunicator->SendSafetyCarOvertaken(currentEvent->GetTeamID(),value);
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
            bssCommunicator->SendStartSkillTimer(currentEvent->getRemainingTime());

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
        this->raceEvent->PauseRaceTimer();
        emit RaceTimerPaused();
    }
}

void CentralController::ResumeRaceTimer()
{
    if(this->raceEvent->getType() == Skill)
    {
        this->raceEvent->ResumeRaceTimer();
        emit RaceTimerResumed();
    }
}

void CentralController::UpdateBSS(quint32 actionType)
{
    switch (actionType) {
    case 0:
    {
        bssCommunicator->SendVoteResult(databaseManager->GetVoteResults());
    }
        break;
    case 1:
    {
        bssCommunicator->SendQualificationResult(databaseManager->GetQualificationResults());
    }
        break;
    case 2:
    {
        bssCommunicator->SendJuniorSpeedRaceResults(databaseManager->GetSpeedRaceResults(true));
        bssCommunicator->SendSeniorSpeedRaceResults(databaseManager->GetSpeedRaceResults(false));
    }
        break;
    case 3:
    {
        bssCommunicator->SendJuniorFinalResults(databaseManager->GetFinalResults(true));
        bssCommunicator->SendSeniorFinalResults(databaseManager->GetFinalResults(false));

        saveResultsToFile();
        this->saveResultsToHTML();
    }
        break;
    case 4:
    {
        bssCommunicator->SendTeams(databaseManager->getTeamList());
    }
        break;
    }
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

void CentralController::saveResultsToHTML()
{
    this->SaveVoteResultToHTML();
    this->SaveFinalResultToHTML();
    this->SaveJuniorFinalResultToHTML();
}

void CentralController::bssConnected(bool alive)
{
    if(alive)
    {
        bssManager.sendQualificationPoints(databaseManager->GetQualificationResults());
    }
}

void CentralController::SaveVoteResultToHTML()
{
    QString path = QDir::home().filePath("voteResults.html");
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            qDebug()<<file.errorString();
            return;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");

    out<<QString::fromUtf8("<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"/></head><body><style type=\"text/css\">.tg{border-collapse:collapse;border-spacing:0;} .tg th,td{border-color:black;border-style:solid;border-width:1px;font-family:Arial,sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:10px5px;word-break:normal;} .tg .tg-data{background-color:#D9D9D9;text-align:center;vertical-align:middle} .tg .tg-lefttext{text-align:left} .tg .tg-header{text-align:center;vertical-align:middle} .tg .tg-bold{font-weight:bold;} .tg .tg-members{text-align:left;vertical-align:top}</style><table class=\"tg\"><thead><caption><h1>Közönségszavazat</h1></caption><tr><th class=\"tg-header\">#</th><th class=\"tg-header\">Csapatnév</th><th  class=\"tg-header\">Közönség szavazat</th><th class=\"tg-headertg-bold\">Pontszám</th></tr></thead>");

    QList<VoteResult> voteResults = databaseManager->GetVoteResults();

    for(VoteResult res: voteResults)
    {

        out<<"<td class=\"tg-data  tg-bold\">"<<res.position<<"</td>";
        out<<"<td class=\"tg-data tg-bold tg-lefttext\">"<<res.teamName<<"</td>";
        out<<"<td class=\"tg-data\">"<<res.voteCount<<"</td>";
        out<<"<td class=\"tg-data  tg-bold\">"<<res.votePoint<<"</td>";

        out<<"</tr>";

    }

    out<<QString::fromUtf8("</tbody></table></body></html>");
}

void CentralController::SaveFinalResultToHTML()
{
    QString path = QDir::home().filePath("FinalResults.html");
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            qDebug()<<file.errorString();
            return;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");

    out<<QString::fromUtf8("<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"/></head><body><style type=\"text/css\">.tg{border-collapse:collapse;border-spacing:0;} .tg th,td{border-color:black;border-style:solid;border-width:1px;font-family:Arial,sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:10px5px;word-break:normal;} .tg .tg-data{background-color:#D9D9D9;text-align:center;vertical-align:middle} .tg .tg-lefttext{text-align:left} .tg .tg-header{text-align:center;vertical-align:middle} .tg .tg-bold{font-weight:bold;} .tg .tg-members{text-align:left;vertical-align:top}</style><table class=\"tg\"><thead><caption><h1>Összesített Végeredmény</h1></caption><tr><th class=\"tg-header\">#</th><th class=\"tg-header\">Csapatnév</th><th class=\"tg-header\">Hozott pont</th><th class=\"tg-header\">Ügyességi</th><th class=\"tg-header\">Gyorsasági</th><th class=\"tg-header\">Közönség</th><th class=\"tg-header tg-bold\">Összes</th></tr></thead><tbody>");

    QList<FinalResult> teamResults = databaseManager->GetFinalResults(false);

    for(FinalResult res: teamResults)
    {

        out<<"<td  class=\"tg-data  tg-bold\">"<<res.position<<"</td>";
        out<<"<td  class=\"tg-data tg-bold tg-lefttext\">"<<res.teamName<<"</td>";
        out<<"<td  class=\"tg-data\">"<<res.qualificationPoint<<"</td>";
        out<<"<td  class=\"tg-data\">"<<res.skillPoint<<"</td>";
        out<<"<td  class=\"tg-data\">"<<res.speedPoint<<"</td>";
        out<<"<td  class=\"tg-data\">"<<res.votePoint<<"</td>";
        out<<"<td  class=\"tg-data  tg-bold\">"<<res.finalPoint<<"</td>";

        out<<"</tr></tr><td></td><td  class=\"tg-members\">";

        Team t = databaseManager->getTeam(res.teamID);
        for(QString memberName: t.getTeamMembers())
        {
            out<<memberName<<"<br/>";
        }

        out<<"</td><td></td><td></td><td></td><td></td><td></td></tr>";

    }

    out<<QString::fromUtf8("</tbody></table></body></html>");
}

void CentralController::SaveJuniorFinalResultToHTML()
{
    QString path = QDir::home().filePath("JuniorResults.html");
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            qDebug()<<file.errorString();
            return;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");

    out<<QString::fromUtf8("<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"/></head><body><style type=\"text/css\">.tg{border-collapse:collapse;border-spacing:0;} .tg th,td{border-color:black;border-style:solid;border-width:1px;font-family:Arial,sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:10px5px;word-break:normal;} .tg .tg-data{background-color:#D9D9D9;text-align:center;vertical-align:middle} .tg .tg-lefttext{text-align:left} .tg .tg-header{text-align:center;vertical-align:middle} .tg .tg-bold{font-weight:bold;} .tg .tg-members{text-align:left;vertical-align:top}</style><table class=\"tg\"><thead><caption><h1>Junior Végeredmény</h1></caption><tr><th class=\"tg-header\">#</th><th class=\"tg-header\">Csapatnév</th><th class=\"tg-header\">Hozott pont</th><th class=\"tg-header\">Ügyességi</th><th class=\"tg-header\">Gyorsasági</th><th class=\"tg-header\">Közönség</th><th class=\"tg-headertg-bold\">Összes</th></tr></thead><tbody>");

    QList<FinalResult> teamResults = databaseManager->GetFinalResults(true);

    for(FinalResult res: teamResults)
    {

        out<<"<td  class=\"tg-data  tg-bold\">"<<res.position<<"</td>";
        out<<"<td  class=\"tg-data tg-bold tg-lefttext\">"<<res.teamName<<"</td>";
        out<<"<td  class=\"tg-data\">"<<res.qualificationPoint<<"</td>";
        out<<"<td  class=\"tg-data\">"<<res.skillPoint<<"</td>";
        out<<"<td  class=\"tg-data\">"<<res.speedPoint<<"</td>";
        out<<"<td  class=\"tg-data\">"<<res.votePoint<<"</td>";    
        out<<"<td  class=\"tg-data  tg-bold\">"<<res.finalPoint<<"</td>";

        out<<"</tr></tr><td></td><td  class=\"tg-members\">";

        Team t = databaseManager->getTeam(res.teamID);
        for(QString memberName: t.getTeamMembers())
        {
            out<<memberName<<"<br/>";
        }

        out<<"</td><td></td><td></td><td></td><td></td><td></td></tr>";

    }

    out<<QString::fromUtf8("</tbody></table></body></html>");
}

void CentralController::SkillRaceTimeout()
{
    emit SkillRaceTimeIsUp();
}
