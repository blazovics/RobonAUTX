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
    case Event_ResetAllGates:
        emit checkpointsReseted();
        break;
    case Event_HeartBeat:
        //FIXME TODO Heartbeat!
        break;
    case Event_StartSkillRaceGate:
       emit SkillRaceGateStarted();
       break;
   case Event_PlayerPassed:
   {
       quint32 checkpointID = event.extractQuint32FromRawData();
       emit PlayerPassed(checkpointID);
   }
       break;
   case Event_PiratePassed:
   {
       quint32 checkpointID = event.extractQuint32FromRawData();
       emit PiratePassed(checkpointID);
   }
       break;
   }
}

void RemoteSkillRaceFieldUnit::UpdateCheckpoint(quint32 checkpointID, CheckpointState state)
{
    Event event(Event_SetGate);
    event.insertCheckpointState8bit(state);
    event.insertQuint8(checkpointID);
    event.insertQuint8(0);
    event.insertQuint8(0);
    sendEvent(event);
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
    Event event(Event_Timeout);
    sendEvent(event);
}

void RemoteSkillRaceFieldUnit::FreezeOn()
{
    Event event(Event_FreezeOn);
    sendEvent(event);
}

void RemoteSkillRaceFieldUnit::FreezeOff()
{
    Event event(Event_FreezeOff);
    sendEvent(event);
}

/*
void RemoteSkillRaceFieldUnit::SetExitGate()
{
    Event event(Event_GateStopSending);
    sendEvent(event);
}*/

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

