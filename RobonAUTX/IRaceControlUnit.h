/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef IRACECONTROLUNIT_H
#define IRACECONTROLUNIT_H

#include <QObject>
#include "TimeSourceType.h"
#include "Team.h"

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
    void updateCheckpointState(quint32 checkpointID, bool checked);
    void VehicleStarted(bool achieved);
    void LaneChanged(bool achieved);
    void SelectTeam(quint32 teamID);
    void SafetyCarFollowed(bool achieved);
    void SafetyCarOvertaken(bool achieved);
    void ModifyTouchCount(quint32 numberOfTouches);

    void ShowSpeedResults(bool isJunior, quint32 fromPos);
    void ShowSkillResults(quint32 fromPos);
    void ShowFinalResults(bool isJunior, quint32 fromPos);
    void ShowFinalResultAtPosition(bool isJunior, quint32 position);
    void ShowVotesResults(quint32 fromPos);
    
public slots:

    virtual void TeamListUpdated(QList<Team> teams) = 0;
    virtual void SkillRaceInitiated(quint32 teamID) = 0;
    virtual void SpeedRaceInitiated(quint32 teamID) = 0;
    virtual void raceStarted() = 0;
    virtual void RaceFinished(bool aborted) = 0;
    virtual void LaserLapTimeUpdated(quint32 time) = 0;
    virtual void ManualLapTimeUpdated(quint32 time) = 0;
    virtual void SpeedLapCompleted(quint32 lapNumber, quint32 lapTime) = 0;
    virtual void CheckpointStateUpdated(quint32 checkpointID, bool checked) = 0;
    virtual void VehicleStartConfirmed(bool achieved) = 0;
    virtual void LaneChangeConfirmed(bool achieved) = 0;
    virtual void SkillPointUpdated(quint32 skillPoint) = 0;
    virtual void TeamSelected(quint32 teamID) = 0;
    virtual void SafetyCarFollowingConfirmed(bool achieved) = 0;
    virtual void SafetyCarOvertakeConfirmed(bool achieved) = 0;
    virtual void TouchCountModified(quint32 numberOfTouches) = 0;
};

#endif //_IRACECONTROLUNIT_H
