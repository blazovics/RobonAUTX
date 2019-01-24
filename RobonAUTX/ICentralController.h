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

class ICentralController {
public: 

    virtual ~ICentralController() = 0;
    
/**
 * @param teamID
 */
virtual void SkillRaceInitiated(quint32 teamID) = 0;
    
/**
 * @param teamID
 */
virtual void SpeedRaceInitiated(quint32 teamID) = 0;
    
/**
 * @param laserLapTime
 */
virtual void LaserLapTimeUpdated(quint32 laserLapTime) = 0;
    
/**
 * @param manualLapTime
 */
virtual void ManualLapTimeUpdated(quint32 manualLapTime) = 0;
    
/**
 * @param checkpointID
 * @param checked
 */
virtual void CheckpointStateUpdated(quint32 checkpointID, bool checked) = 0;
    
virtual void RaceStarted() = 0;
    
/**
 * @param aborted
 */
virtual void RaceFinished(bool aborted) = 0;
    
/**
 * @param teams
 */
virtual void TeamListUpdated(QList<Team> teams) = 0;
    
/**
 * @param lapNumber
 * @param lapTime
 */
virtual void SpeedLapCompleted(quint32 lapNumber, quint32 lapTime) = 0;
    
/**
 * @param skillPoint
 */
virtual void SkillPointUpdated(quint32 skillPoint) = 0;
    
/**
 * @param achieved
 */
virtual void VehicleStartConfirmed(bool achieved) = 0;
    
/**
 * @param achieved
 */
virtual void LaneChangeConfirmed(bool achieved) = 0;
    
/**
 * @param teamID
 */
virtual void TeamSelected(quint32 teamID) = 0;
    
/**
 * @param achieved
 */
virtual void SafetyCarFollowingConfirmed(bool achieved) = 0;
    
/**
 * @param achieved
 */
virtual void SafetyCarOvertakeConfirmed(bool achieved) = 0;
    
/**
 * @param touchCount
 */
void TouchCountModified(quint32 touchCount);
    
/**
 * @param teamID
 */
virtual void InitSkillRace(quint32 teamID) = 0;
    
/**
 * @param teamID
 */
virtual void InitSpeedRace(quint32 teamID) = 0;
    
/**
 * @param teamID
 * @param voteCount
 */
virtual void UpdateVotesForTeam(quint32 teamID, int voteCount) = 0;
    
virtual void ManualMeasureReceived() = 0;
    
virtual void LaserMeasureReceived() = 0;
    
/**
 * @param timeSource
 */
virtual void TimeSourceForLapSelected(TimeSourceType timeSource) = 0;
    
/**
 * @param checkpointID
 * @param checked
 */
virtual void UpdateCheckpointState(quint32 checkpointID, bool checked) = 0;
    
virtual void StartRace() = 0;
    
/**
 * @param aborted
 */
virtual void FinishRace(bool aborted) = 0;
    
virtual void TeamListRequested() = 0;
    
/**
 * @param achieved
 */
virtual void VechicleStartAchieved(bool achieved) = 0;
    
/**
 * @param achieved
 */
virtual void LaneChangeAchieved(bool achieved) = 0;
    
/**
 * @param teamID
 */
virtual void SelectTeam(quint32 teamID) = 0;
    
/**
 * @param achieved
 */
virtual void SafetyCarFollowed(bool achieved) = 0;
    
/**
 * @param achieved
 */
virtual void SafetyCarOvertaken(bool achieved) = 0;
    
/**
 * @param touchCount
 */
virtual void ModifyTouchCount(quint32 touchCount) = 0;

};

#endif //_ICENTRALCONTROLLER_H
