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
        localUnit->SpeedLapCompleted(event.extractQuint32FromRawData(),event.extractQuint32FromRawData());
        break;
    case Device_RaceControlUnit + Event_CheckpointStateUpdated :
        localUnit->CheckpointStateUpdated(event.extractQuint32FromRawData(),event.extractBoolFromRawData());
        break;
    case Device_RaceControlUnit + Event_VehicleStartConfirmed :
        localUnit->VehicleStartConfirmed(event.extractBoolFromRawData());
        break;
    case Device_RaceControlUnit + Event_LaneChangeConfirmed :
        localUnit->LaneChangeConfirmed(event.extractBoolFromRawData());
        break;
    case Device_RaceControlUnit + Event_SkillPointUpdated :
        localUnit->SkillPointUpdated(event.extractQuint32FromRawData());
        break;
    case Device_RaceControlUnit + Event_SafetyCarFollowingConfirmed :
        localUnit->SafetyCarFollowingConfirmed(event.extractBoolFromRawData());
        break;
    case Device_RaceControlUnit + Event_SafetyCarOvertakeConfirmed :
        localUnit->SafetyCarOvertakeConfirmed(event.extractBoolFromRawData());
        break;
    case Device_RaceControlUnit + Event_TouchCountModified :
        localUnit->TouchCountModified(event.extractQuint32FromRawData());
        break;
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
    Event event(Device_RaceControlUnit + Event_SpeedLapCompleted);
    event.insertQuint32(checkpointID);
    event.insertBool(checked);
    sendEvent(event);
}

void RemoteRaceControlUnit::VehicleStartConfirmed(bool achieved)
{
    Event event(Device_RaceControlUnit + Event_VehicleStartConfirmed);
    event.insertBool(achieved);
    sendEvent(event);
}

void RemoteRaceControlUnit::LaneChangeConfirmed(bool achieved)
{
    Event event(Device_RaceControlUnit + Event_LaneChangeConfirmed);
    event.insertBool(achieved);
    sendEvent(event);
}

void RemoteRaceControlUnit::SkillPointUpdated(quint32 skillPoint)
{
    Event event(Device_RaceControlUnit + Event_SkillPointUpdated);
    event.insertQuint32(skillPoint);
    sendEvent(event);
}

void RemoteRaceControlUnit::SafetyCarFollowingConfirmed(bool achieved)
{
    Event event(Device_RaceControlUnit + Event_SafetyCarFollowingConfirmed);
    event.insertBool(achieved);
    sendEvent(event);
}

void RemoteRaceControlUnit::SafetyCarOvertakeConfirmed(bool achieved)
{
    Event event(Device_RaceControlUnit + Event_SafetyCarOvertakeConfirmed);
    event.insertBool(achieved);
    sendEvent(event);
}

void RemoteRaceControlUnit::TouchCountModified(quint32 numberOfTouches)
{
    Event event(Device_RaceControlUnit + Event_TouchCountModified);
    event.insertQuint32(numberOfTouches);
    sendEvent(event);
}
