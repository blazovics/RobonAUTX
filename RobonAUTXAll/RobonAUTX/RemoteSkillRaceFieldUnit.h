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

    Q_OBJECT

public:
    explicit RemoteSkillRaceFieldUnit(CoreController* parentController, QTcpSocket *socket, QIODevice::OpenMode mode = QIODevice::WriteOnly);
    void EventReceived(Event& event);

public slots:
    void UpdateCheckpointState(quint32 checkpointID, bool state);
    void ResetCheckpoints();
    void SendHeartBeat();
    void SendClearAllGates();

private:
    void sendReset(quint32 checkpointID);
    void sendSet(quint32 checkpointID);

    static const std::pair<quint32,quint32> gateIDs[12];

    quint32 checkpointIDForGateID(quint32 id);
    quint32 gateIDForCheckpointID(quint32 id);

};



#endif //_REMOTESKILLRACEFIELDUNIT_H
