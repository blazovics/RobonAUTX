/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RemoteRaceControlUnit.h"

/**
 * RemoteRemoteRaceControlUnit implementation
 */
RaceControlUnit *RemoteRaceControlUnit::getLocalUnit() const
{
    return localUnit;
}

void RemoteRaceControlUnit::setLocalUnit(RaceControlUnit *value)
{
    localUnit = value;
}

RemoteRaceControlUnit::RemoteRaceControlUnit(CoreController *parentController, QTcpSocket *socket, QIODevice::OpenMode mode):RemoteDevice (parentController,socket, mode)
{
    
    
}

RemoteRaceControlUnit::~RemoteRaceControlUnit()
{

}

//FIXME: Implement
void RemoteRaceControlUnit::EventReceived(Event &event)
{
    switch (event.getEventID()) {
    case Device_RaceControlUnit + Event_TeamListUpdated :
        localUnit->TeamListUpdated(event.extractTeamsFromRawData());
        break;
    case Device_RaceControlUnit + Event_SkillRaceInitiated :
        localUnit->SkillRaceInitiated(event.extractQuint32FromRawData());
        break;
    case Device_RaceControlUnit + Event_SpeedRaceInitiated :
        localUnit->SpeedRaceInitiated(event.extractQuint32FromRawData());
        break;
    case Device_RaceControlUnit + Event_raceStarted :
        localUnit->raceStarted();
        break;
    case Device_RaceControlUnit + Event_RaceFinished :
        localUnit->RaceFinished(event.extractBoolFromRawData());
        break;
    case Device_RaceControlUnit + Event_LaserLapTimeUpdated :
        localUnit->LaserLapTimeUpdated(event.extractQuint32FromRawData());
        break;
    case Device_RaceControlUnit + Event_ManualLapTimeUpdated :
        localUnit->ManualLapTimeUpdated(event.extractQuint32FromRawData());
        break;
    case Device_RaceControlUnit + Event_SpeedLapCompleted :
    {
        quint32 first = event.extractQuint32FromRawData();
        quint32 second = event.extractQuint32FromRawData();
        localUnit->SpeedLapCompleted(first,second);
    }
        break;
    case Device_RaceControlUnit + Event_CheckpointStateUpdated :
    {
        quint32 first = event.extractQuint32FromRawData();
        bool second = event.extractBoolFromRawData();
        localUnit->CheckpointStateUpdated(first,second);
    }
        break;
    case Device_RaceControlUnit + Event_VehicleStartConfirmed :
        localUnit->VehicleStartConfirmed(event.extractBoolFromRawData());
        break;
    case Device_RaceControlUnit + Event_LaneChangeConfirmed :
    {
        bool first = event.extractBoolFromRawData();
        quint64 second = event.extractQuint64FromRawData();
        localUnit->LaneChangeConfirmed(first,second);
    }
        break;
    case Device_RaceControlUnit + Event_SkillPointUpdated :
    {
        quint32 first = event.extractQuint32FromRawData();
        quint32 second = event.extractQuint32FromRawData();
        localUnit->SkillPointUpdated(first,second);
    }
        break;
    case Device_RaceControlUnit + Event_SafetyCarFollowingConfirmed :
        localUnit->SafetyCarFollowingConfirmed(event.extractBoolFromRawData());
        break;
    case Device_RaceControlUnit + Event_SafetyCarOvertakeConfirmed :
    {
        quint32 value = event.extractQuint32FromRawData();
        localUnit->SafetyCarOvertakeConfirmed(value);
    }
        break;
    case Device_RaceControlUnit + Event_TouchCountModified :
        localUnit->TouchCountModified(event.extractQuint32FromRawData());
        break;
    case Device_RaceControlUnit + Event_RaceTimerPaused :
        localUnit->RaceTimerPaused();
        break;
    case Device_RaceControlUnit + Event_RaceTimerResumed :
        localUnit->RaceTimerResumed();
        break;
    case Device_RaceControlUnit + Event_TargetCheckpointUpdated:
        localUnit->TargetCheckpointUpdated(event.extractQuint32FromRawData());
    }
}

void RemoteRaceControlUnit::TeamListUpdated(QList<Team> teams)
{
    Event event(Device_RaceControlUnit + Event_TeamListUpdated);
    event.insertTeams(teams);
    sendEvent(event);
}

void RemoteRaceControlUnit::SkillRaceInitiated(quint32 teamID)
{
    Event event(Device_RaceControlUnit + Event_SkillRaceInitiated);
    event.insertQuint32(teamID);
    sendEvent(event);
}

void RemoteRaceControlUnit::SpeedRaceInitiated(quint32 teamID)
{
    Event event(Device_RaceControlUnit + Event_SpeedRaceInitiated);
    event.insertQuint32(teamID);
    sendEvent(event);
}

void RemoteRaceControlUnit::raceStarted()
{
    Event event(Device_RaceControlUnit + Event_raceStarted);
    sendEvent(event);
}

void RemoteRaceControlUnit::RaceFinished(bool aborted)
{
    Event event(Device_RaceControlUnit + Event_RaceFinished);
    event.insertBool(aborted);
    sendEvent(event);
}

void RemoteRaceControlUnit::LaserLapTimeUpdated(quint32 time)
{
    Event event(Device_RaceControlUnit + Event_LaserLapTimeUpdated);
    event.insertQuint32(time);
    sendEvent(event);
}

void RemoteRaceControlUnit::ManualLapTimeUpdated(quint32 time)
{
    Event event(Device_RaceControlUnit + Event_ManualLapTimeUpdated);
    event.insertQuint32(time);
    sendEvent(event);
}

void RemoteRaceControlUnit::SpeedLapCompleted(quint32 lapNumber, quint32 lapTime)
{
    Event event(Device_RaceControlUnit + Event_SpeedLapCompleted);
    event.insertQuint32(lapNumber);
    event.insertQuint32(lapTime);
    sendEvent(event);
}

void RemoteRaceControlUnit::CheckpointStateUpdated(quint32 checkpointID, bool checked)
{
    Event event(Device_RaceControlUnit + Event_CheckpointStateUpdated);
    event.insertQuint32(checkpointID);
    event.insertBool(checked);
    sendEvent(event);
}

void RemoteRaceControlUnit::TargetCheckpointUpdated(quint32 checkpointID)
{
    Event event(Device_RaceControlUnit + Event_TargetCheckpointUpdated);
    event.insertQuint32(checkpointID);
    sendEvent(event);
}

void RemoteRaceControlUnit::VehicleStartConfirmed(bool achieved)
{
    Event event(Device_RaceControlUnit + Event_VehicleStartConfirmed);
    event.insertBool(achieved);
    sendEvent(event);
}

void RemoteRaceControlUnit::LaneChangeConfirmed(bool achieved, quint64 laneChangeTime)
{
    Event event(Device_RaceControlUnit + Event_LaneChangeConfirmed);
    event.insertBool(achieved);
    event.insertQuint64(laneChangeTime);
    sendEvent(event);
}

void RemoteRaceControlUnit::SkillPointUpdated(quint32 skillPoint, quint32 timeCredit)
{
    Event event(Device_RaceControlUnit + Event_SkillPointUpdated);
    event.insertQuint32(skillPoint);
    event.insertQuint32(timeCredit);
    sendEvent(event);
}

void RemoteRaceControlUnit::SafetyCarFollowingConfirmed(bool achieved)
{
    Event event(Device_RaceControlUnit + Event_SafetyCarFollowingConfirmed);
    event.insertBool(achieved);
    sendEvent(event);
}

void RemoteRaceControlUnit::SafetyCarOvertakeConfirmed(quint32 value)
{
    Event event(Device_RaceControlUnit + Event_SafetyCarOvertakeConfirmed);
    event.insertQuint32(value);
    sendEvent(event);
}

void RemoteRaceControlUnit::TouchCountModified(quint32 numberOfTouches)
{
    Event event(Device_RaceControlUnit + Event_TouchCountModified);
    event.insertQuint32(numberOfTouches);
    sendEvent(event);
}

void RemoteRaceControlUnit::RaceTimerPaused()
{
    Event event(Device_RaceControlUnit + Event_RaceTimerPaused);
    sendEvent(event);
}

void RemoteRaceControlUnit::RaceTimerResumed()
{
    Event event(Device_RaceControlUnit + Event_RaceTimerResumed);
    sendEvent(event);
}
