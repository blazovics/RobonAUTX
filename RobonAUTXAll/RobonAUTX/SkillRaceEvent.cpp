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
bool SkillRaceEvent::UpdateCheckpoint(quint32 index, bool newState, bool forced) {

    if(remainingTime > 0 || forced == true)
    {
        try{

            bool status = static_cast<SkillRace*>(this->actualRace)->GetCheckpointState(index);

            if(status != newState)
            {
                static_cast<SkillRace*>(this->actualRace)->SetCheckpoint(index,newState);
                return true;
            }
        }
        catch(std::out_of_range e)
        {
            qDebug()<<"Out of range exception when setting checkpoint";
        }
    }
    return  false;
}

quint32 SkillRaceEvent::ModifyWrongGateCount(quint32 wrongGateCount)
{
    static_cast<SkillRace*>(this->actualRace)->setWrongGateCount(wrongGateCount);
    return static_cast<SkillRace*>(this->actualRace)->GetWrongGateCount();
}

bool SkillRaceEvent::IsLastCheckpointReached()
{
    return static_cast<SkillRace*>(this->actualRace)->IsLastCheckpointReached();
}

bool SkillRaceEvent::UpdateTargetCheckpoint(quint32 index)
{
    static_cast<SkillRace*>(this->actualRace)->SetTargetCheckpoint(index);
}

void SkillRaceEvent::SetStartSucceeded(bool value)
{
    static_cast<SkillRace*>(this->actualRace)->SetStartSucceeded(value);
}

void SkillRaceEvent::SetLaneChangeSuccess(bool value)
{
    static_cast<SkillRace*>(this->actualRace)->SetLaneChangeSucceeded(value, remainingTime);
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

quint32 SkillRaceEvent::GetWrongGateCount()
{
    return static_cast<SkillRace*>(this->actualRace)->GetWrongGateCount();
}

quint32 SkillRaceEvent::GetWrongGatePoints()
{
    return quint32(static_cast<SkillRace*>(this->actualRace)->GetWrongGatePoint());
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




