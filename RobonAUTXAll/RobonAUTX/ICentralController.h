/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef ICENTRALCONTROLLER_H
#define ICENTRALCONTROLLER_H

#define Event_InitSkillRace 1
#define Event_InitSpeedRace 2
#define Event_UpdateVotesForTeam 3
#define Event_ManualMeasureReceived 4
#define Event_LaserMeasureReceived 5
#define Event_TimeSourceForLapSelected 6
#define Event_UpdateCheckpointState 7
#define Event_StartRace 8
#define Event_FinishRace 9
#define Event_TeamListRequested 10
#define Event_VechicleStartAchieved 11
#define Event_LaneChangeAchieved 12
#define Event_SafetyCarFollowed 13
#define Event_SafetyCarOvertaken 14
#define Event_ModifyTouchCount 15
#define Event_ShowSpeedResults 16
#define Event_ShowSkillResults 17
#define Event_ShowFinalResults 18
#define Event_ShowFinalResultAtPosition 19
#define Event_ShowVotesResults 20
#define Event_ShowQualificationResults 21
#define Event_ShowInterRaceScreen 22
#define Event_SkillGateStarted 23
#define Event_PauseRaceTimer 24
#define Event_ResumeRaceTimer 25
#define Event_UpdateBSS 26

#define Device_ICentralController 100

#include <QObject>
#include "Team.h"
#include "TimeSourceType.h"

#include "SpeedRaceResult.h"
#include "SkillRaceResult.h"
#include "QualificationResult.h"
#include "VoteResult.h"
#include "FinalResult.h"

class ICentralController : public QObject{

    Q_OBJECT

public:

signals:
    void SkillRaceInitiated(quint32 teamID);
    void SpeedRaceInitiated(quint32 teamID);
    void LaserLapTimeUpdated(quint32 laserLapTime);
    void ManualLapTimeUpdated(quint32 manualLapTime);
    void CheckpointStateUpdated(quint32 checkpointID, bool checked);
    void RaceStarted();
    void RaceFinished(bool aborted);
    void TeamListUpdated(QList<Team> teams);
    void SpeedLapCompleted(quint32 lapNumber, quint32 lapTime);
    void SkillPointUpdated(quint32 skillPoint, quint32 timeCredit);
    void VehicleStartConfirmed(bool achieved);
    void LaneChangeConfirmed(bool achieved);
    void SafetyCarFollowingConfirmed(bool achieved);
    void SafetyCarOvertakeConfirmed(quint32 value);
    void TouchCountModified(quint32 touchCount);
    void VotesUpdated(quint32 teamID, quint32 voteCount);

    void showSpeedResults(QList<SpeedRaceResult> result, bool isJunior, quint32 fromPos);
    void showSkillResults(QList<SkillRaceResult> result, quint32 fromPos);
    void showFinalResults(QList<FinalResult> result, bool isJunior, quint32 fromPos);
    void showFinalResultAtPosition(QList<FinalResult> result, bool isJunior, quint32 position);
    void showVotesResults(QList<VoteResult> result, quint32 fromPos);
    void showQualificationResults(QList<QualificationResult> result, quint32 fromPos);
    void showInterRaceScreen();

    void StartSkillGate();

    void RaceTimerPaused();
    void RaceTimerResumed();

    void updateInRaceSpeedResults(QList<SpeedRaceResult> result);

    void StartSafetyCar();
    void StopSafetyCar();
    void ClearSkillGates();
    void ResetSkillGates();


public slots:

    virtual void InitSkillRace(quint32 teamID) = 0;
    virtual void InitSpeedRace(quint32 teamID) = 0;
    virtual void UpdateVotesForTeam(quint32 teamID, quint32 voteCount) = 0;
    //WARNING Send time along manual measure?
    virtual void ManualMeasureReceived() = 0;
    virtual void LaserMeasureReceived(quint32 time) = 0;
    virtual void TimeSourceForLapSelected(TimeSourceType timeSource) = 0;
    virtual void UpdateCheckpointState(quint32 checkpointID, bool checked, bool forced) = 0;
    virtual void StartRace() = 0;
    virtual void FinishRace(bool aborted) = 0;
    virtual void TeamListRequested() = 0;
    virtual void VechicleStartAchieved(bool achieved) = 0;
    virtual void LaneChangeAchieved(bool achieved) = 0;
    virtual void SafetyCarFollowed(bool achieved) = 0;
    virtual void SafetyCarOvertaken(quint32 value) = 0;
    virtual void ModifyTouchCount(quint32 touchCount) = 0;

    virtual void ShowSpeedResults(bool isJunior, quint32 fromPos) = 0;
    virtual void ShowSkillResults(quint32 fromPos)  = 0;
    virtual void ShowFinalResults(bool isJunior, quint32 fromPos)  = 0;
    virtual void ShowFinalResultAtPosition(bool isJunior, quint32 position)  = 0;
    virtual void ShowVotesResults(quint32 fromPos)  = 0;
    virtual void ShowQualificationResults(quint32 fromPos) = 0;
    virtual void ShowInterRaceScreen() = 0;

    virtual void SkillGateStarted() = 0;

    virtual void PauseRaceTimer() = 0;
    virtual void ResumeRaceTimer() = 0;

    virtual void UpdateBSS() = 0;

};

#endif //_ICENTRALCONTROLLER_H
