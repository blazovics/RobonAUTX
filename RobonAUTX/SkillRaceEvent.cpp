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
SkillRaceEvent::SkillRaceEvent(DatabaseManager& dbManager, QObject *parent):RaceEvent (dbManager, parent)
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
void SkillRaceEvent::UpdateCheckpoint(quint32 index, bool newState, bool forced) {

    if(remainingTime < 0 || forced == true)
    {
        try{

            bool status = static_cast<SkillRace*>(this->actualRace)->GetCheckpointState(index);

            if(status != newState)
            {
                static_cast<SkillRace*>(this->actualRace)->SetCheckpoint(index,newState);
            }
        }
        catch(std::out_of_range e)
        {
            qDebug()<<"Out of range exception when setting checkpoint";
        }
    }
}

void SkillRaceEvent::SetStartSucceeded(bool value)
{
    static_cast<SkillRace*>(this->actualRace)->setStartSucceeded(value);
}

void SkillRaceEvent::SetLanChangeSuccess(bool value)
{
    static_cast<SkillRace*>(this->actualRace)->setLaneChangeSucceeded(value);
}

void SkillRaceEvent::StartRace() {
    RaceEvent::StartRace();
}

void SkillRaceEvent::SaveRace() {
    this->dbManager.SaveSkillRace(static_cast<SkillRace*>(this->actualRace),false);
    RaceEvent::SaveRace();
}

void SkillRaceEvent::AbortRace() {
    this->dbManager.SaveSkillRace(static_cast<SkillRace*>(this->actualRace),true);
    stopRaceTimer();
    RaceEvent::AbortRace();
}

void SkillRaceEvent::updateTimerFired()
{
    remainingTime = static_cast<SkillRace*>(this->actualRace)->GetTimeCredit() - raceTimer.Elapsed();
    throw "NI";
}




