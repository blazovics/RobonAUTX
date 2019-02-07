/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "SpeedRaceEvent.h"
#include "SpeedRace.h"

/**
 * SpeedRaceEvent implementation
 */


/**
 * @param teamID
 */
SpeedRaceEvent::SpeedRaceEvent(std::shared_ptr<DatabaseManager> dbManager, QObject *parent):RaceEvent (dbManager,parent)
{

}

void SpeedRaceEvent::InitRace(quint32 teamID) {
    ReleaseActualRace();
    this->actualRace = new SpeedRace(teamID);
    this->actualLap.isWarmUp = true;
    this->raceTimerOffset = 0;
}

/**
 * @param touchCount
 */
quint32 SpeedRaceEvent::ModifyTouchCount(quint32 touchCount) {
    static_cast<SpeedRace*>(this->actualRace)->SetProhibitedTouchCount(touchCount);
    return static_cast<SpeedRace*>(this->actualRace)->GetProhibitedTouchTouchCount();
}

quint32 SpeedRaceEvent::LaserTimeReceived()
{
    quint32 time = quint32(this->raceTimer.Elapsed()-raceTimerOffset);
    this->actualLap.laserTime = time;
    return time;
}

quint32 SpeedRaceEvent::ManualTimeReceived()
{
    quint32 time = quint32(this->raceTimer.Elapsed()-raceTimerOffset);
    this->actualLap.manualTime = time;
    return time;
}

/**
 * @param timeType
 */
quint32 SpeedRaceEvent::FinishLap(TimeSourceType timeType) {

    this->actualLap.choosenLapType = timeType;

    quint32 lapTime = actualLap.GetChoosenLapTime();

    this->raceTimerOffset += lapTime;

    if(this->actualLap.isWarmUp)
    {
        static_cast<SpeedRace*>(this->actualRace)->SetWarmUpLap(actualLap);
    }
    else{
        static_cast<SpeedRace*>(this->actualRace)->AddCompletedLap(actualLap);
    }

    resetActualLap();

    return  lapTime;
}

quint32 SpeedRaceEvent::GetFinishedLapCount() const
{
    return static_cast<SpeedRace*>(this->actualRace)->GetCompletedLapCount();
}

void SpeedRaceEvent::SetSafetyCarFollowed(bool value)
{
    static_cast<SpeedRace*>(this->actualRace)->SetSafetyCarFollowed(value);
}

void SpeedRaceEvent::SetSafetyCarOvertaken(bool value)
{
    static_cast<SpeedRace*>(this->actualRace)->SetSafetyCarOvertaken(value);
}

void SpeedRaceEvent::StartRace() {
    RaceEvent::StartRace();
}

void SpeedRaceEvent::SaveRace() {
    this->dbManager->SaveSpeedRace(static_cast<SpeedRace*>(this->actualRace),false);
    RaceEvent::SaveRace();
}

void SpeedRaceEvent::AbortRace() {
    this->dbManager->SaveSpeedRace(static_cast<SpeedRace*>(this->actualRace),true);
    RaceEvent::AbortRace();

}

RaceEventType SpeedRaceEvent::getType()
{
    return Speed;
}

void SpeedRaceEvent::UpdateTimerFired()
{
    ////throw "NI";
}

void SpeedRaceEvent::resetActualLap()
{
    this->actualLap = Lap();
}
