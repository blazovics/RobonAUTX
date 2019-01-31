/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTESKILLRACEFIELDUNIT_H
#define REMOTESKILLRACEFIELDUNIT_H

#include "ISkillRaceFieldUnit.h"
#include "RemoteDevice.h"

class RemoteSkillRaceFieldUnit: public ISkillRaceFieldUnit, public RemoteDevice {

public:
    explicit RemoteSkillRaceFieldUnit(CoreController* parentController, QTcpSocket *socket);
    void EventReceived(Event& event);

public slots:
    void UpdateCheckpointState(quint32 checkpointID, bool state);
    void ResetCheckpoints();
    void SendHeartBeat();

private:
    void sendReset(quint32 checkpointID);
    void sendSet(quint32 checkpointID);

};

#endif //_REMOTESKILLRACEFIELDUNIT_H
