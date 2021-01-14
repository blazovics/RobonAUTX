/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTERACECONTROLUNIT_H
#define REMOTERACECONTROLUNIT_H

#include "IRaceControlUnit.h"
#include "RemoteDevice.h"

#include "RaceControlUnit.h"


class RemoteRaceControlUnit: public IRaceControlUnit, public RemoteDevice {

    Q_OBJECT

    RaceControlUnit* localUnit;

public:

    explicit RemoteRaceControlUnit(CoreController* parentController, QTcpSocket *socket, QIODevice::OpenMode mode = QIODevice::WriteOnly);
    virtual ~RemoteRaceControlUnit();

    RaceControlUnit *getLocalUnit() const;
    void setLocalUnit(RaceControlUnit *value);

public slots:

    void EventReceived(Event& event);

    void TeamListUpdated(QList<Team> teams);
    void SkillRaceInitiated(quint32 teamID);
    void SpeedRaceInitiated(quint32 teamID);
    void raceStarted();
    void RaceFinished(bool aborted);
    void LaserLapTimeUpdated(quint32 time);
    void ManualLapTimeUpdated(quint32 time);
    void SpeedLapCompleted(quint32 lapNumber, quint32 lapTime);
    void CheckpointStateUpdated(quint32 checkpointID, bool checked);
    void VehicleStartConfirmed(bool achieved);
    void LaneChangeConfirmed(bool achieved);
    void SkillPointUpdated(quint32 skillPoint, quint32 timeCredit);
    void SafetyCarFollowingConfirmed(bool achieved);
    void SafetyCarOvertakeConfirmed(quint32 value);
    void TouchCountModified(quint32 numberOfTouches);

    void RaceTimerPaused();
    void RaceTimerResumed();
};

#endif //_REMOTERACECONTROLUNIT_H
