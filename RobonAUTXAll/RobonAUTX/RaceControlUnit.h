/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef RACECONTROLUNIT_H
#define RACECONTROLUNIT_H

#include "IRaceControlUnit.h"
#include <QObject>
#include "TeamModel.h"
#include "RTimer.h"
#include "RaceEvent.h"

class RaceControlUnit: public IRaceControlUnit {

    Q_OBJECT

    QList<Team> teams;

    TeamModel teamModel;

    quint32 timeCredit;

    RTimer raceTimer;
    std::unique_ptr<QTimer> updateTimer;

    QElapsedTimer speedRaceTimer;
    quint32 speedTimeOffset;

    RaceEventType eventType;

    quint32 touchCount;

    qint32 approvedCheckpointIndex;
    
public:
    explicit RaceControlUnit();

    virtual ~RaceControlUnit();

    TeamModel* getTeamModel();


private:
    void calculateApprovedCheckpointIndex(unsigned checkpointIndex, bool newState);

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
    void TargetCheckpointUpdated(quint32 checkpointID);
    void VehicleStartConfirmed(bool achieved);
    void LaneChangeConfirmed(bool achieved, quint64 laneChangeTime);
    void SkillPointUpdated(quint32 skillPoint, quint32 timeCredit);
    void SafetyCarFollowingConfirmed(bool achieved);
    void SafetyCarOvertakeConfirmed(quint32 value);
    void TouchCountModified(quint32 numberOfTouches);
    void RaceTimerPaused();
    void RaceTimerResumed();

//For Timer
    void TimerFired();

//From QML side
public slots:
    void qmlGetTeamList();
    void qmlInitSkillRace(quint32 teamID);
    void qmlInitSpeedRace(quint32 teamID);
    void qmlStartRace();
    void qmlFinishRace(bool aborted);
    void qmlManualMeasure();
    void qmlManualTimeSelected();
    void qmlLaserTimeSelected();
    void qmlUpdateCheckpointState(quint32 checkpointID, bool checked, bool forced);
    void qmlVehicleStarted(bool achieved);
    void qmlLaneChanged(bool achieved);
    void qmlSafetyCarFollowed(bool achieved);
    void qmlSafetyCarOvertaken(quint32 value);
    void qmlIncreaseTouchCount();
    void qmlDecreaseTouchCount();

    void qmlIncreaseCheckpoint();
    void qmlDecreaseCheckpoint();

    void qmlShowSpeedResults(bool isJunior, quint32 fromPos);
    void qmlShowSkillResults(quint32 fromPos);
    void qmlShowFinalResults(bool isJunior, quint32 fromPos);
    void qmlShowFinalResultAtPosition(bool isJunior, quint32 position);
    void qmlShowVotesResults(quint32 fromPos);
    void qmlShowQualificationResults(quint32 fromPos);
    void qmlShowInterRaceScreen();

    void qmlSkillGateManualStarted();

    void qmlPauseRaceTimer();
    void qmlResumeRaceTimer();

    void qmlUpdateBSS();

signals:
    void showMainView();
    void showSkillRaceView(quint32 teamID);
    void showSpeedRaceView(quint32 teamID);
    void updateCheckpointButtons(quint32 checkpointID,bool checked);
    void updateStartSuccessButton(bool status);
    void updateLaneChangeConfirmedButton(bool status);
    void updateSkillPoint(quint32 point);
    void updateRaceTime(QString time);
    void updateRemainingTime(QString time);

    void updateSafetyCarFollowingConfirmedButton(bool status);
    void updateSafetyCarOvertakenConfirmedButton(quint32 value);
    void updateTouchCountModified(quint32 numberOfTouches);
    void updateLaserLapTime(QString time);
    void updateManualLapTime(QString time);
    void updateCompletedSpeedLaps(quint32 lapNumber, quint32 lapTime);


};

#endif //_RACECONTROLUNIT_H
