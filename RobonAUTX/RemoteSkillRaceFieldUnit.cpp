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
    //FIXME Implement!
}

void RemoteSkillRaceFieldUnit::updateCheckpointState(quint32 checkpointID, bool state)
{
    //FIXME Implement!
}
