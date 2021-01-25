/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */



#include "RemoteSkillRaceFieldUnit.h"
#include <QThread>
#include "Configuration.h"

/**
 * RemoteSkillRaceFieldUnit implementation
 */

RemoteSkillRaceFieldUnit::RemoteSkillRaceFieldUnit(CoreController *parentController, QTcpSocket *socket, QIODevice::OpenMode mode):RemoteDevice (parentController,socket, mode)
{

}

void RemoteSkillRaceFieldUnit::EventReceived(Event &event)
{

   switch (event.getEventID()) {
    case Event_SetGate:
        emit TargetCheckpointUpdated(event.extractQuint32FromRawData());
        break;
    case Event_ResetAllGates:
        emit checkpointsReseted();
        break;
    case Event_HeartBeat:
        //FIXME TODO Heartbeat!
        break;
    case Event_StartSkillRaceGate:
       emit SkillRaceGateStarted();
       break;
   }
}

void RemoteSkillRaceFieldUnit::UpdateTargetCheckpoint(quint32 checkpointID)
{
    this->sendSet(checkpointID);
}

void RemoteSkillRaceFieldUnit::ResetCheckpoints()
{
    this->SendClearAllGates();
}

void RemoteSkillRaceFieldUnit::SendHeartBeat()
{
    Event event(Event_HeartBeat);
    sendEvent(event);
}

void RemoteSkillRaceFieldUnit::SendClearAllGates()
{
    Event event(Event_ResetAllGates);
    sendEvent(event);
}

void RemoteSkillRaceFieldUnit::StartSafetyCar()
{
    Event event(Event_StartSafetyCar);
    event.insertQuint32(0);
    sendEvent(event);
}

void RemoteSkillRaceFieldUnit::StopSafetyCar()
{
    Event event(Event_StopSafetyCar);
    event.insertQuint32(0);
    sendEvent(event);
}

void RemoteSkillRaceFieldUnit::StartSkillRaceGate()
{
    Event event(Event_StartSkillRaceGate);
    sendEvent(event);
}

void RemoteSkillRaceFieldUnit::TimeIsUp()
{
    Event event(Event_TimeIsUp);
    sendEvent(event);
}

void RemoteSkillRaceFieldUnit::sendSet(quint32 checkpointID)
{
    Event event(Event_SetGate);
    event.insertQuint32(checkpointID);
    sendEvent(event);
}

void RemoteSkillRaceFieldUnit::sendTimeout()
{
    Event event(Event_Timeout);
    sendEvent(event);
}

