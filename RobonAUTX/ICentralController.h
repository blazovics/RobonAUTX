/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef ICENTRALCONTROLLER_H
#define ICENTRALCONTROLLER_H

#include <QObject>
#include "Team.h"
#include "TimeSourceType.h"

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
    void SkillPointUpdated(quint32 skillPoint);
    void VehicleStartConfirmed(bool achieved);
    void LaneChangeConfirmed(bool achieved);
    void SafetyCarFollowingConfirmed(bool achieved);
    void SafetyCarOvertakeConfirmed(bool achieved);
    void TouchCountModified(quint32 touchCount);
    void VotesUpdated(quint32 teamID, quint32 voteCount);

public slots:

    virtual void InitSkillRace(quint32 teamID) = 0;
    virtual void InitSpeedRace(quint32 teamID) = 0;
    virtual void UpdateVotesForTeam(quint32 teamID, quint32 voteCount) = 0;
    virtual void ManualMeasureReceived() = 0;
    virtual void LaserMeasureReceived() = 0;
    virtual void TimeSourceForLapSelected(TimeSourceType timeSource) = 0;
    virtual void UpdateCheckpointState(quint32 checkpointID, bool checked, bool forced) = 0;
    virtual void StartRace() = 0;
    virtual void FinishRace(bool aborted) = 0;
    virtual void TeamListRequested() = 0;
    virtual void VechicleStartAchieved(bool achieved) = 0;
    virtual void LaneChangeAchieved(bool achieved) = 0;
    virtual void SafetyCarFollowed(bool achieved) = 0;
    virtual void SafetyCarOvertaken(bool achieved) = 0;
    virtual void ModifyTouchCount(quint32 touchCount) = 0;

};

#endif //_ICENTRALCONTROLLER_H
