/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SKILLRACE_H
#define SKILLRACE_H

#define SkillCheckpointCount 17
#define SkillCheckpointPoint 2
#define SkillStartPoint 3
#define SkillLaneChangePoint 6
#define SkillTouchPenaltyPoint 5

#include "Race.h"
#include <vector>

using namespace std;

typedef enum{
    Clear = 0,
    Checked = 1,
    PirateSecond = 2,
    PirateFirst = 3,
    PirateFirstChecked = 4,
    PirateSecondChecked
} CheckpointState;

class SkillRace: public Race {

private:
    vector<vector<CheckpointState>> prevCheckpointStates;
    vector<CheckpointState> checkpointStates;
    bool startSucceeded;
    bool laneChangeSucceeded;
    bool allCheckpointsReached;

    quint64 laneChangeTime;

    quint64 allCheckpointsReachedTime;

    qint64 raceTime;

    quint32 touchCount;

public: 
    
    static const quint32 checkpointCount;
    static const quint32 checkpointPoint;
    static const quint32 startPoint;
    static const quint32 laneChangePoint;

    static const quint32 touchPenaltyPoint;

    /**
    * @param teamID
    */
    SkillRace(quint32 teamID);
    
    quint32 GetRacePoint() const;

    quint32 GetAbsoluteRacePoint() const;
    
    CheckpointState GetCheckpointState(quint32 index) const;

    void SetCheckpoint(quint32 index, CheckpointState newState, qint64 updateTime);

    CheckpointState RevertCheckpoint(quint32 index);


    
    bool GetStartSucceeded() const;
    
    void SetStartSucceeded(bool value);
    
    bool GetLaneChangeSucceeded() const;
    
    void SetLaneChangeSucceeded(bool value, qint64 laneChangeTime);

    qint64 GetTimeCredit() const;

    static quint32 CalculateSkillRacePoints(vector<CheckpointState> checkpointStates, quint32 touchCount, bool startSucceeded, bool laneChangeSucceeded, quint64 laneChangeTime);
    static qint32 CalculateAbsoluteSkillRacePoints(vector<CheckpointState> checkpointStates, quint32 touchCount, bool startSucceeded, bool laneChangeSucceeded, quint64 laneChangeTime);

    QT_DEPRECATED static quint32 CalculateWrongGatePoints(quint32 wrongGateCount);



    quint64 GetSerializedCheckpointStates() const;

    qint64 getRaceTime() const;
    void setRaceTime(const qint64 &value);
    quint32 getLaneChangeTime() const;

    quint32 GetLaneChangePoint() const;

    static quint32 GetCheckpointPoint(CheckpointState state);
    quint32 GetTouchCount() const;
    qint32 GetTouchPenaltyPoint() const;
    quint32 UpdateTouchCount(quint32 newTouchCount);

private:
    bool IsAllCheckpointReached();
};



#endif //_SKILLRACE_H
