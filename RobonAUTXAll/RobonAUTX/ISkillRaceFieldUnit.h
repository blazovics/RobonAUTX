/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef ISKILLRACEFIELDUNIT_H
#define ISKILLRACEFIELDUNIT_H

#include <QObject>


#define Event_SetGate 50
//#define Event_GateStopSending 51
#define Event_Timeout 52
#define Event_ResetAllGates 54
#define Event_StartSafetyCar 4
#define Event_StopSafetyCar 5
#define Event_HeartBeat 2
#define Event_StartSkillRaceGate 34
#define Event_WrongGate 53

class ISkillRaceFieldUnit : public QObject {

    Q_OBJECT

public:

signals:
    void TargetCheckpointUpdated(quint32 checkpointID);
    void CheckpointStateUpdated(quint32 checkpointID,bool state, bool forced);
    void checkpointsReseted();
    void ConnectionStatusUpdated(quint32 status);
    void SkillRaceGateStarted();
    void WrongGatePassed();

public slots:

    //FIXME: Create a correct implementation
    virtual void UpdateTargetCheckpoint(quint32 checkpointID) = 0;
    virtual void ResetCheckpoints() = 0;
    virtual void SendHeartBeat() = 0;
    virtual void SendClearAllGates() = 0;
    virtual void StartSafetyCar() = 0;
    virtual void StopSafetyCar() = 0;
    virtual void StartSkillRaceGate() = 0;
    virtual void TimeIsUp() = 0;
    //virtual void SetExitGate() = 0;

};

#endif //_ISKILLRACEFIELDUNIT_H
