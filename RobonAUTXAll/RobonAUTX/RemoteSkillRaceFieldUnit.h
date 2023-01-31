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
    void UpdateCheckpoint(quint32 checkpointID, CheckpointState state, bool forced);
    void ResetCheckpoints();
    void SendHeartBeat();
    void SendClearAllGates();
    void StartSafetyCar();
    void StopSafetyCar();
    void StartSkillRaceGate();
    void TimeIsUp();
    //void SetExitGate();

    void FreezeOn();
    void FreezeOff();

private:
    void sendSet(quint32 checkpointID);
    void sendTimeout();
};



#endif //_REMOTESKILLRACEFIELDUNIT_H
