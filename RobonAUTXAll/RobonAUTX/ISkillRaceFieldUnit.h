/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef ISKILLRACEFIELDUNIT_H
#define ISKILLRACEFIELDUNIT_H

#include <QObject>
#include "SkillRace.h"


#define Event_SetGate 50
//#define Event_GateStopSending 51
#define Event_Timeout 52
#define Event_ResetAllGates 54
#define Event_StartSafetyCar 4
#define Event_StopSafetyCar 5
#define Event_HeartBeat 2
#define Event_StartSkillRaceGate 34
#define Event_WrongGate 53
#define Event_FreezeOn 55
#define Event_FreezeOff 56

#define Event_PlayerPassed 57
#define Event_PiratePassed 58


class ISkillRaceFieldUnit : public QObject {

    Q_OBJECT

public:

signals:
    void TargetCheckpointUpdated(quint32 checkpointID);

    void CheckpointStateUpdated(quint32 checkpointID,bool state, bool forced);

    void checkpointsReseted();
    void ConnectionStatusUpdated(quint32 status);
    void SkillRaceGateStarted();

    void PiratePassed(quint32 checkpointID);
    void PlayerPassed(quint32 checkpointID);

public slots:

    //FIXME: Create a correct implementation
    virtual void UpdateCheckpoint(quint32 checkpointID, CheckpointState state, bool forced) = 0;
    virtual void ResetCheckpoints() = 0;
    virtual void SendHeartBeat() = 0;
    virtual void SendClearAllGates() = 0;
    virtual void StartSafetyCar() = 0;
    virtual void StopSafetyCar() = 0;
    virtual void StartSkillRaceGate() = 0;
    virtual void TimeIsUp() = 0;

    virtual void FreezeOn() = 0;
    virtual void FreezeOff() = 0;



    //virtual void SetExitGate() = 0;

};

#endif //_ISKILLRACEFIELDUNIT_H
