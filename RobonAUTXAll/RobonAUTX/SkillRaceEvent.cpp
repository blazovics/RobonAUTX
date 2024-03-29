/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "SkillRaceEvent.h"
#include "SkillRace.h"

#include <QDebug>

/**
 * SkillRaceEvent implementation
 */


/**
 * @param teamID
 */
qint64 SkillRaceEvent::getRemainingTime()
{
    this->updateRemainingTime();
    return remainingTime;
}

qint32 SkillRaceEvent::GetTouchPenaltyPoint()
{
    return static_cast<SkillRace*>(this->actualRace)->GetTouchPenaltyPoint();
}

SkillRaceEvent::SkillRaceEvent(std::shared_ptr<DatabaseManager> dbManager, CentralController* centralController, QObject *parent):RaceEvent (dbManager, centralController, parent)
{

}

void SkillRaceEvent::InitRace(quint32 teamID) {
    ReleaseActualRace();
    this->actualRace = new SkillRace(teamID);
    remainingTime = static_cast<SkillRace*>(this->actualRace)->GetTimeCredit();
}

/**
 * @param index
 * @param checked
 */
bool SkillRaceEvent::UpdateCheckpoint(quint32 index, CheckpointState newState, bool forced) {

    if(remainingTime > 0 || forced == true)
    {
        try{

            static_cast<SkillRace*>(this->actualRace)->SetCheckpoint(index,newState, raceTimer.Elapsed());
            return true;
        }
        catch(std::out_of_range e)
        {
            qDebug()<<"Out of range exception when setting checkpoint";
        }
    }
    return  false;
}

CheckpointState SkillRaceEvent::GetCheckpointState(quint32 index)
{
    return static_cast<SkillRace*>(this->actualRace)->GetCheckpointState(index);
}

CheckpointState SkillRaceEvent::RevertCheckpoint(quint32 index)
{
    return static_cast<SkillRace*>(this->actualRace)->RevertCheckpoint(index);
}

/*
bool SkillRaceEvent::IsLastCheckpointReached()
{
    return static_cast<SkillRace*>(this->actualRace)->IsAllCheckpointReached();
}*/

void SkillRaceEvent::SetStartSucceeded(bool value)
{
    static_cast<SkillRace*>(this->actualRace)->SetStartSucceeded(value);
}

void SkillRaceEvent::SetLaneChangeSuccess(bool value)
{
    static_cast<SkillRace*>(this->actualRace)->SetLaneChangeSucceeded(value, raceTimer.Elapsed());
}

quint32 SkillRaceEvent::UpdateTouchCount(quint32 newValue)
{
    return static_cast<SkillRace*>(this->actualRace)->UpdateTouchCount(newValue);
}

void SkillRaceEvent::StartRace() {
    RaceEvent::StartRace();
}

void SkillRaceEvent::SaveRace() {
    RaceEvent::SaveRace();
    static_cast<SkillRace*>(this->actualRace)->setRaceTime(raceTimer.Elapsed());
    this->dbManager->SaveSkillRace(static_cast<SkillRace*>(this->actualRace),false);

}

void SkillRaceEvent::AbortRace() {
    RaceEvent::AbortRace();
    static_cast<SkillRace*>(this->actualRace)->setRaceTime(raceTimer.Elapsed());
    this->dbManager->SaveSkillRace(static_cast<SkillRace*>(this->actualRace),true);
}

RaceEventType SkillRaceEvent::getType()
{
    return Skill;
}

quint32 SkillRaceEvent::GetActualPoints()
{
    return static_cast<SkillRace*>(this->actualRace)->GetRacePoint();
}

qint32 SkillRaceEvent::GetActualAbsolutePoints()
{
    return static_cast<SkillRace*>(this->actualRace)->GetAbsoluteRacePoint();
}

quint32 SkillRaceEvent::GetTimeCredit()
{
    return quint32(static_cast<SkillRace*>(this->actualRace)->GetTimeCredit());
}


quint64 SkillRaceEvent::GetLaneChangeTime()
{
    return quint64(static_cast<SkillRace*>(this->actualRace)->getLaneChangeTime());
}

quint32 SkillRaceEvent::GetLaneChangePoint()
{
    return quint64(static_cast<SkillRace*>(this->actualRace)->GetLaneChangePoint());
}

void SkillRaceEvent::updateRemainingTime()
{
    remainingTime = static_cast<SkillRace*>(this->actualRace)->GetTimeCredit() - raceTimer.Elapsed();
    if(remainingTime < 0 && remainingTime > -11)
    {
        this->parentController->SkillRaceTimeout();
    }
}

void SkillRaceEvent::UpdateTimerFired()
{
    updateRemainingTime();
}




