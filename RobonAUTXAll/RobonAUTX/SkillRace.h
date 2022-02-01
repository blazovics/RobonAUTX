/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SKILLRACE_H
#define SKILLRACE_H

#define SkillCheckpointCount 15
#define SkillCheckpointPoint 2
#define SkillStartPoint 0
#define SkillLaneChangePoint 10
#define SkillWrongGatePoint 2

#include "Race.h"
#include <vector>

using namespace std;

class SkillRace: public Race {

private:
    vector<bool> checkpointStates;
    bool startSucceeded;
    bool laneChangeSucceeded;

    quint32 wrongGateCount;

    quint64 laneChangeTime;

    qint64 raceTime;

public: 
    
    static const quint32 checkpointCount;
    static const quint32 checkpointPoint;
    static const quint32 startPoint;
    static const quint32 laneChangePoint;
    static const quint32 wrongGatePoint;

    /**
    * @param teamID
    */
    SkillRace(quint32 teamID);
    
    quint32 GetRacePoint() const;

    quint32 GetAbsoluteRacePoint() const;

    quint32 GetWrongGateCount() const;

    quint32 GetWrongGatePoint() const;
    
    bool GetCheckpointState(quint32 index) const;

    void SetCheckpoint(quint32 index, bool checked);

    void SetTargetCheckpoint(quint32 index);
    
    bool GetStartSucceeded() const;
    
    void SetStartSucceeded(bool value);
    
    bool GetLaneChangeSucceeded() const;
    
    void SetLaneChangeSucceeded(bool value, qint64 laneChangeTime);

    bool IsLastCheckpointReached();

    qint64 GetTimeCredit() const;

    static quint32 CalculateSkillRacePoints(vector<bool> checkpointStates, bool startSucceeded, bool laneChangeSucceeded, quint32 wrongGateCount, quint64 laneChangeTime);
    static qint32 CalculateAbsoluteSkillRacePoints(vector<bool> checkpointStates, bool startSucceeded, bool laneChangeSucceeded, quint32 wrongGateCount, quint64 laneChangeTime);

    static quint32 CalculateWrongGatePoints(quint32 wrongGateCount);

    quint32 GetSerializedCheckpointStates() const;

    qint64 getRaceTime() const;
    void setRaceTime(const qint64 &value);
    quint32 getLaneChangeTime() const;

    quint32 GetLaneChangePoint() const;
    void setWrongGateCount(quint32 newWrongGateCount);
};



#endif //_SKILLRACE_H
