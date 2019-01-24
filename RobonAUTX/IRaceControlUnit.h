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

class IRaceControlUnit {
public: 
    
virtual void getTeamList() = 0;
    
/**
 * @param teamID
 */
virtual void InitSkillRace(quint32 teamID) = 0;
    
/**
 * @param teamID
 */
virtual void InitSpeedRace(quint32 teamID) = 0;
    
virtual void startRace() = 0;
    
/**
 * @param aborted
 */
virtual void FinishRace(bool aborted) = 0;
    
virtual void manualMeasure() = 0;
    
/**
 * @param timeSource
 */
virtual void SelectTimeSourceForLap(TimeSourceType timeSource) = 0;
    
/**
 * @param checkpointID
 * @param checked
 */
virtual void updateCheckpointState(quint32 checkpointID, bool checked) = 0;
    
/**
 * @param achieved
 */
virtual void VehicleStarted(bool achieved) = 0;
    
/**
 * @param achieved
 */
virtual void LaneChanged(bool achieved) = 0;
    
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
 * @param numberOfTouches
 */
virtual void ModifyTouchCount(quint32 numberOfTouches) = 0;
    
/**
 * @param teams
 */
virtual void TeamListUpdated(QList<Team> teams) = 0;
    
/**
 * @param teamID
 */
virtual void SkillRaceInitiated(quint32 teamID) = 0;
    
/**
 * @param teamID
 */
virtual void SpeedRaceInitiated(quint32 teamID) = 0;
    
virtual void raceStarted() = 0;
    
/**
 * @param aborted
 */
virtual void RaceFinished(bool aborted) = 0;
    
/**
 * @param time
 */
virtual void LaserLapTimeUpdated(quint32 time) = 0;
    
/**
 * @param time
 */
virtual void ManualLapTimeUpdated(quint32 time) = 0;
    
/**
 * @param lapNumber
 * @param lapTime
 */
virtual void SpeedLapCompleted(quint32 lapNumber, quint32 lapTime) = 0;
    
/**
 * @param checkpointID
 * @param checked
 */
virtual void CheckpointStateUpdated(quint32 checkpointID, bool checked) = 0;
    
/**
 * @param achieved
 */
virtual void VehicleStartConfirmed(bool achieved) = 0;
    
/**
 * @param achieved
 */
virtual void LaneChangeConfirmed(bool achieved) = 0;
    
/**
 * @param skillPoint
 */
virtual void SkillPointUpdated(quint32 skillPoint) = 0;
    
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
 * @param numberOfTouches
 */
virtual void TouchCountModified(quint32 numberOfTouches) = 0;
    
/**
 * @param isJunior
 */
virtual void showSpeedResutls(bool isJunior) = 0;
};

#endif //_IRACECONTROLUNIT_H
