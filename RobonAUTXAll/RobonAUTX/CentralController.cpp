/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "CentralController.h"
#include "SkillRaceEvent.h"
#include "SpeedRaceEvent.h"
#include <QDebug>

/**
 * CentralController implementation
 */


CentralController::CentralController() {
    //FIXME Consider change to unique
    databaseManager = std::make_shared<DatabaseManager>();

}

CentralController::~CentralController()
{

}

void CentralController::InitSkillRace(quint32 teamID)
{
    this->raceEvent.reset();
    this->raceEvent = std::make_unique<SkillRaceEvent>(databaseManager);
    this->raceEvent->InitRace(teamID);

    emit SkillRaceInitiated(teamID);
}

void CentralController::InitSpeedRace(quint32 teamID)
{
    this->raceEvent.reset();
    this->raceEvent = std::make_unique<SpeedRaceEvent>(databaseManager);
    this->raceEvent->InitRace(teamID);

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
        throw std::bad_cast();
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
        throw std::bad_cast();
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
    }
    else {
        throw std::bad_cast();
    }
}

void CentralController::UpdateCheckpointState(quint32 checkpointID, bool checked, bool forced)
{
    SkillRaceEvent* currentEvent = dynamic_cast<SkillRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        qDebug()<<"Update Checkpoint state";
        currentEvent->UpdateCheckpoint(checkpointID,checked,forced);
        emit CheckpointStateUpdated(checkpointID,checked);
        emit SkillPointUpdated(currentEvent->GetActualPoints(),currentEvent->GetTimeCredit());
    }
    else {

        throw std::bad_cast();
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
    }
}

void CentralController::FinishRace(bool aborted)
{
    //FIXME check if not null
    if(aborted)
    {
        this->raceEvent->AbortRace();
    }
    else {
        this->raceEvent->SaveRace();
    }
    emit RaceFinished(aborted);
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
    }
    else {
        throw std::bad_cast();
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
    }
    else {
        throw std::bad_cast();
    }
}

void CentralController::SafetyCarFollowed(bool achieved)
{
    SpeedRaceEvent* currentEvent = dynamic_cast<SpeedRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        currentEvent->SetSafetyCarFollowed(achieved);
        emit SafetyCarFollowingConfirmed(achieved);
    }
    else {
        throw std::bad_cast();
    }
}

void CentralController::SafetyCarOvertaken(bool achieved)
{
    SpeedRaceEvent* currentEvent = dynamic_cast<SpeedRaceEvent*>(this->raceEvent.get());
    if(currentEvent != nullptr)
    {
        currentEvent->SetSafetyCarOvertaken(achieved);
        emit SafetyCarOvertakeConfirmed(achieved);
    }
    else {
        throw std::bad_cast();
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
        throw std::bad_cast();
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
