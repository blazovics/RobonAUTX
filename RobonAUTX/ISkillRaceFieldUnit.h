/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef ISKILLRACEFIELDUNIT_H
#define ISKILLRACEFIELDUNIT_H

#include <QObject>


class ISkillRaceFieldUnit : QObject {

    Q_OBJECT

public:

public slots:
    virtual void updateCheckpointState(quint32 checkpointID) = 0;
    virtual void Start() = 0;
    virtual void CheckpointStateUpdated(quint32 checkpointID) = 0;
    virtual void ManualSetCheckpoint(quint32 checkpointID, quint32 state) = 0;
};

#endif //_ISKILLRACEFIELDUNIT_H
