/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RemoteSkillRaceFieldUnit.h"

/**
 * RemoteSkillRaceFieldUnit implementation
 */

RemoteSkillRaceFieldUnit::RemoteSkillRaceFieldUnit(CoreController *parentController, QTcpSocket *socket):RemoteDevice (parentController,socket)
{

}

void RemoteSkillRaceFieldUnit::EventReceived(Event &event)
{

    switch (event.getEventID()) {
        case Event_AISetGate:
            emit checkpointUpdated(event.extractQuint32FromRawData(),true,false);
        break;
            case Event_AIResetGate:
            emit checkpointUpdated(event.extractQuint32FromRawData(),false,true);
        break;
            case Event_SetGate:
            emit checkpointUpdated(event.extractQuint32FromRawData(),true,true);
        break;
            case Event_ResetGate:
            emit checkpointUpdated(event.extractQuint32FromRawData(),false,true);
        break;
            case Event_ResetAllGates:
            emit checkpointsReseted();
        break;
            case Event_HeartBeat:
            //FIXME TODO Heartbeat!
        break;
    }
}

void RemoteSkillRaceFieldUnit::UpdateCheckpointState(quint32 checkpointID, bool state)
{
   if(state)
   {
       this->sendSet(checkpointID);
   }
   else
   {
       this->sendReset(checkpointID);
   }

}

void RemoteSkillRaceFieldUnit::ResetCheckpoints()
{
    Event event(Event_ResetAllGates);
    sendEvent(event);
}

void RemoteSkillRaceFieldUnit::SendHeartBeat()
{
    Event event(Event_HeartBeat);
    sendEvent(event);
}

void RemoteSkillRaceFieldUnit::sendReset(quint32 checkpointID)
{
    Event event(Event_ResetGate);
    event.insertQuint32(checkpointID);
    sendEvent(event);
}

void RemoteSkillRaceFieldUnit::sendSet(quint32 checkpointID)
{
    Event event(Event_SetGate);
    event.insertQuint32(checkpointID);
    sendEvent(event);
}

