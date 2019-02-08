/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */



#include "RemoteSkillRaceFieldUnit.h"

/**
 * RemoteSkillRaceFieldUnit implementation
 */

const std::pair<quint32,quint32> RemoteSkillRaceFieldUnit::gateIDs[12] = {
    std::pair<quint32,quint32>(0,1),
    std::pair<quint32,quint32>(1,2),
    std::pair<quint32,quint32>(2,3),
    std::pair<quint32,quint32>(3,4),
    std::pair<quint32,quint32>(4,5),
    std::pair<quint32,quint32>(5,6),
    std::pair<quint32,quint32>(6,7),
    std::pair<quint32,quint32>(7,8),
    std::pair<quint32,quint32>(8,9),
    std::pair<quint32,quint32>(9,10),
    std::pair<quint32,quint32>(10,11),
    std::pair<quint32,quint32>(11,12)};

RemoteSkillRaceFieldUnit::RemoteSkillRaceFieldUnit(CoreController *parentController, QTcpSocket *socket, QIODevice::OpenMode mode):RemoteDevice (parentController,socket, mode)
{

}

void RemoteSkillRaceFieldUnit::EventReceived(Event &event)
{

   switch (event.getEventID()) {
    case Event_AISetGate:
        emit checkpointUpdated(checkpointIDForGateID(event.extractQuint32FromRawData()),true,false);
        break;
    case Event_AIResetGate:
        emit checkpointUpdated(checkpointIDForGateID(event.extractQuint32FromRawData()),false,true);
        break;
    case Event_SetGate:
        emit checkpointUpdated(checkpointIDForGateID(event.extractQuint32FromRawData()),true,true);
        break;
    case Event_ResetGate:
        emit checkpointUpdated(checkpointIDForGateID(event.extractQuint32FromRawData()),false,true);
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
       this->sendSet(gateIDForCheckpointID(checkpointID));
   }
   else
   {
       this->sendReset(gateIDForCheckpointID(checkpointID));
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

void RemoteSkillRaceFieldUnit::SendClearAllGates()
{
    Event event(Event_ClearAllGates);
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

quint32 RemoteSkillRaceFieldUnit::checkpointIDForGateID(quint32 id)
{
    for (quint32 i=0; i < 12; i++) {
        std::pair<quint32,quint32> tmp = gateIDs[i];
        if(tmp.second == id)
        {
            return tmp.first;
        }
    }
    return 0;
}

quint32 RemoteSkillRaceFieldUnit::gateIDForCheckpointID(quint32 id)
{
    for (quint32 i=0; i < 12; i++) {
        std::pair<quint32,quint32> tmp = gateIDs[i];
        if(tmp.first == id)
        {
            return tmp.second;
        }
    }
    return 0;
}

