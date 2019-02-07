/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef ISKILLRACEFIELDUNIT_H
#define ISKILLRACEFIELDUNIT_H

#include <QObject>


#define Event_AISetGate 50
#define Event_AIResetGate 51
#define Event_SetGate 52
#define Event_ResetGate 53
#define Event_ResetAllGates 54
#define Event_ClearAllGates 55
#define Event_HeartBeat 2

class ISkillRaceFieldUnit : public QObject {

    Q_OBJECT

public:

signals:
    void checkpointUpdated(quint32 checkpointID, bool state, bool forced);
    //Fixme: Iterative
    void checkpointsReseted();
    void ConnectionStatusUpdated(quint32 status);

public slots:

    //FIXME: Create a correct implementation
    virtual void UpdateCheckpointState(quint32 checkpointID, bool state) = 0;
    virtual void ResetCheckpoints() = 0;
    virtual void SendHeartBeat() = 0;
    virtual void SendClearAllGates() = 0;

};

#endif //_ISKILLRACEFIELDUNIT_H
