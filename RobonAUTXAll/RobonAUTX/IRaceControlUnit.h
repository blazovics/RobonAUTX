/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef IRACECONTROLUNIT_H
#define IRACECONTROLUNIT_H

#define Event_TeamListUpdated 1
#define Event_SkillRaceInitiated 2
#define Event_SpeedRaceInitiated 3
#define Event_raceStarted 4
#define Event_RaceFinished 5
#define Event_LaserLapTimeUpdated 6
#define Event_ManualLapTimeUpdated 7
#define Event_SpeedLapCompleted 8
#define Event_CheckpointStateUpdated 9
#define Event_VehicleStartConfirmed 10
#define Event_LaneChangeConfirmed 11
#define Event_SkillPointUpdated 12
#define Event_SafetyCarFollowingConfirmed 13
#define Event_SafetyCarOvertakeConfirmed 14
#define Event_TouchCountModified 15
#define Event_RaceTimerPaused 16
#define Event_RaceTimerResumed 17
#define Event_TargetCheckpointUpdated 18
#define Event_WrongGateCountModified 19

#define Device_RaceControlUnit 200

#include <QObject>
#include "TimeSourceType.h"
#include "Team.h"
#include "SkillRace.h"

class IRaceControlUnit : public QObject{

    Q_OBJECT

public: 
    
signals:
    void getTeamList();
    void InitSkillRace(quint32 teamID);
    void InitSpeedRace(quint32 teamID);
    void startRace();
    void FinishRace(bool aborted);
    void manualMeasure();
    void SelectTimeSourceForLap(TimeSourceType timeSource);
    void updateCheckpointState(quint32 checkpointID, CheckpointState newState, bool forced);

    void RevertCheckpointState(quint32 checkpointID);

    void UpdateTargetCheckpoint(quint32 checkpointID);
    void VehicleStarted(bool achieved);
    void LaneChanged(bool achieved);
    void SafetyCarFollowed(bool achieved);
    void SafetyCarOvertaken(quint32 value);
    void ModifyTouchCount(quint32 numberOfTouches);
    void ModifyWrongGateCount(quint32 numberOfWrongGates);

    void ShowSpeedResults(bool isJunior, quint32 fromPos);
    void ShowSkillResults(quint32 fromPos);
    void ShowFinalResults(bool isJunior, quint32 fromPos);
    void ShowFinalResultAtPosition(bool isJunior, quint32 position);
    void ShowVotesResults(quint32 fromPos);
    void ShowQualificationResults(quint32 fromPos);
    void ShowInterRaceScreen();

    void SkillGateManualStarted();

    void PauseRaceTimer();
    void ResumeRaceTimer();

    void UpdateBSS(quint32 actionType);

public slots:

    virtual void TeamListUpdated(QList<Team> teams) = 0;
    virtual void SkillRaceInitiated(quint32 teamID) = 0;
    virtual void SpeedRaceInitiated(quint32 teamID) = 0;
    virtual void raceStarted() = 0;
    virtual void RaceFinished(bool aborted) = 0;
    virtual void LaserLapTimeUpdated(quint32 time) = 0;
    virtual void ManualLapTimeUpdated(quint32 time) = 0;
    virtual void SpeedLapCompleted(quint32 lapNumber, quint32 lapTime) = 0;
    virtual void CheckpointStateUpdated(quint32 checkpointID, CheckpointState newState) = 0;
    virtual void TargetCheckpointUpdated(quint32 checkpointID) = 0;
    virtual void VehicleStartConfirmed(bool achieved) = 0;
    virtual void LaneChangeConfirmed(bool achieved, quint64 laneChangeTime) = 0;
    virtual void SkillPointUpdated(quint32 skillPoint, quint32 timeCredit) = 0;
    virtual void SafetyCarFollowingConfirmed(bool achieved) = 0;
    virtual void SafetyCarOvertakeConfirmed(quint32 value) = 0;
    virtual void TouchCountModified(quint32 numberOfTouches) = 0;
    virtual void WrongGateCountModified(quint32 numberOfWrongGates) = 0;

    virtual void RaceTimerPaused() = 0;
    virtual void RaceTimerResumed() = 0;
};

#endif //_IRACECONTROLUNIT_H
