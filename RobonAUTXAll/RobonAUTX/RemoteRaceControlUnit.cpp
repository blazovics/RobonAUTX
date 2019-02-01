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

RemoteRaceControlUnit::RemoteRaceControlUnit(CoreController *parentController, QTcpSocket *socket):RemoteDevice (parentController,socket)
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
        break;
    case Device_RaceControlUnit + Event_SkillRaceInitiated :
        break;
    case Device_RaceControlUnit + Event_SpeedRaceInitiated :
        break;
    case Device_RaceControlUnit + Event_raceStarted :
        break;
    case Device_RaceControlUnit + Event_RaceFinished :
        break;
    case Device_RaceControlUnit + Event_LaserLapTimeUpdated :
        break;
    case Device_RaceControlUnit + Event_ManualLapTimeUpdated :
        break;
    case Device_RaceControlUnit + Event_SpeedLapCompleted :
        break;
    case Device_RaceControlUnit + Event_CheckpointStateUpdated :
        break;
    case Device_RaceControlUnit + Event_VehicleStartConfirmed :
        break;
    case Device_RaceControlUnit + Event_LaneChangeConfirmed :
        break;
    case Device_RaceControlUnit + Event_SkillPointUpdated :
        break;
    case Device_RaceControlUnit + Event_SafetyCarFollowingConfirmed :
        break;
    case Device_RaceControlUnit + Event_SafetyCarOvertakeConfirmed :
        break;
    case Device_RaceControlUnit + Event_TouchCountModified :
        break;
    }
}

void RemoteRaceControlUnit::TeamListUpdated(QList<Team> teams)
{

}

void RemoteRaceControlUnit::SkillRaceInitiated(quint32 teamID)
{

}

void RemoteRaceControlUnit::SpeedRaceInitiated(quint32 teamID)
{

}

void RemoteRaceControlUnit::raceStarted()
{

}

void RemoteRaceControlUnit::RaceFinished(bool aborted)
{

}

void RemoteRaceControlUnit::LaserLapTimeUpdated(quint32 time)
{

}

void RemoteRaceControlUnit::ManualLapTimeUpdated(quint32 time)
{

}

void RemoteRaceControlUnit::SpeedLapCompleted(quint32 lapNumber, quint32 lapTime)
{

}

void RemoteRaceControlUnit::CheckpointStateUpdated(quint32 checkpointID, bool checked)
{

}

void RemoteRaceControlUnit::VehicleStartConfirmed(bool achieved)
{

}

void RemoteRaceControlUnit::LaneChangeConfirmed(bool achieved)
{

}

void RemoteRaceControlUnit::SkillPointUpdated(quint32 skillPoint)
{

}

void RemoteRaceControlUnit::SafetyCarFollowingConfirmed(bool achieved)
{

}

void RemoteRaceControlUnit::SafetyCarOvertakeConfirmed(bool achieved)
{

}

void RemoteRaceControlUnit::TouchCountModified(quint32 numberOfTouches)
{

}
