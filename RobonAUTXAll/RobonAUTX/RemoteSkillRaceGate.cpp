#include "RemoteSkillRaceGate.h"


RemoteSkillRaceGate::RemoteSkillRaceGate(CoreController *parentController, QTcpSocket *socket, QIODevice::OpenMode mode):RemoteDevice (parentController,socket,mode)
{

}

void RemoteSkillRaceGate::EventReceived(Event &event)
{
    switch (event.getEventID()) {
    case Event_SkillRaceGateStarted:
        emit SkillRaceGateStarted();
        break;
    }
}

void RemoteSkillRaceGate::StartSkillRaceGate()
{
    Event event(Event_StartSkillRaceGate);
    sendEvent(event);
}
