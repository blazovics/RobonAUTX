/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef RACECONTROLUNIT_H
#define RACECONTROLUNIT_H

#include "IRaceControlUnit.h"
#include <QObject>

#include "MainViewcontroller.h"
#include "SkillRaceViewController.h"
#include "SpeedRaceViewController.h"
#include "ResultViewController.h"

class RaceControlUnit: public IRaceControlUnit {
/*
    MainViewcontroller mainViewController;
    SkillRaceViewController skillRaceViewController;
    SpeedRaceViewController speedRaceViewController;
    ResultViewController resultViewController;*/

    Q_OBJECT

    QList<Team> teams;
    
public:
    explicit RaceControlUnit();

    virtual ~RaceControlUnit();

public slots:

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
    void SkillPointUpdated(quint32 skillPoint);
    void SafetyCarFollowingConfirmed(bool achieved);
    void SafetyCarOvertakeConfirmed(bool achieved);
    void TouchCountModified(quint32 numberOfTouches);
};

#endif //_RACECONTROLUNIT_H
