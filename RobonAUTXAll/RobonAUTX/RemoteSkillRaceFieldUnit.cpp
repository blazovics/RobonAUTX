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

const std::pair<quint32,quint32> RemoteSkillRaceFieldUnit::gateIDs[18] = {
    std::pair<quint32,quint32>(0,14),
    std::pair<quint32,quint32>(1,1),
    std::pair<quint32,quint32>(2,2),
    std::pair<quint32,quint32>(3,3),
    std::pair<quint32,quint32>(4,4),
    std::pair<quint32,quint32>(5,5),
    std::pair<quint32,quint32>(6,6),
    std::pair<quint32,quint32>(7,7),
    std::pair<quint32,quint32>(8,8),
    std::pair<quint32,quint32>(9,9),
    std::pair<quint32,quint32>(10,10),
    std::pair<quint32,quint32>(11,15),
    std::pair<quint32,quint32>(12,12),
    std::pair<quint32,quint32>(13,13),
    std::pair<quint32,quint32>(14,144),
    std::pair<quint32,quint32>(15,155),
    std::pair<quint32,quint32>(16,16),
    std::pair<quint32,quint32>(17,17)};

RemoteSkillRaceFieldUnit::RemoteSkillRaceFieldUnit(CoreController *parentController, QTcpSocket *socket, QIODevice::OpenMode mode):RemoteDevice (parentController,socket, mode)
{

}

void RemoteSkillRaceFieldUnit::EventReceived(Event &event)
{

   switch (event.getEventID()) {
    case Event_SetGate:
        emit checkpointUpdated(event.extractQuint32FromRawData(),true,false);
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

void RemoteSkillRaceFieldUnit::UpdateCheckpointState(quint32 checkpointID, bool state)
{
   if(state)
   {
   this->sendSet(checkpointID);
   }
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

void RemoteSkillRaceFieldUnit::sendSet(quint32 checkpointID)
{
    Event event(Event_SetGate);
    event.insertQuint32(checkpointID);
    sendEvent(event);
}

quint32 RemoteSkillRaceFieldUnit::checkpointIDForGateID(quint32 id)
{
    /*
    for (quint32 i=0; i < 18; i++) {

        std::pair<quint32,quint32> tmp =  gateIDs[i];
        if(tmp.second == id)
        {
            return tmp.first;
        }
    }
    return 0;*/

     Configuration& instance = Configuration::GetInstance();

     std::string str_indexID =  "Gate_" + std::to_string(id);

     if(instance.IsKeyAvailable("GateSettings",str_indexID)){
         return instance.GetLongValue("GateSettings",str_indexID);
     }
     else{
         return 0;
     }
}

quint32 RemoteSkillRaceFieldUnit::gateIDForCheckpointID(quint32 id)
{
    /*
    for (quint32 i=0; i < 12; i++) {
        std::pair<quint32,quint32> tmp = gateIDs[i];
        if(tmp.first == id)
        {
            return tmp.second;
        }
    }
    return 0;
    */

    Configuration& instance = Configuration::GetInstance();

    std::string str_indexID =  "Checkpoint_" + std::to_string(id);

    if(instance.IsKeyAvailable("CheckpointSettings",str_indexID)){
        return instance.GetLongValue("CheckpointSettings",str_indexID);
    }
    else{
        return 0;
    }
}

