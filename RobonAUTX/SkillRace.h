/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SKILLRACE_H
#define SKILLRACE_H

#define SkillCheckpointCount 12
#define SkillCheckpointPoint 2
#define SkillStartPoint 2
#define SkillLaneChangePoint 2

#include "Race.h"
#include <vector>

using namespace std;

class SkillRace: public Race {

private:
    vector<bool> checkpointStates;
    bool startSucceeded;
    bool laneChangeSucceeded;

public: 
    
    static const quint32 checkpointCount;
    static const quint32 checkpointPoint;
    static const quint32 startPoint;
    static const quint32 laneChangePoint;

    /**
    * @param teamID
    */
    SkillRace(quint32 teamID);
    
    quint32 GetRacePoint() const;
    
    bool GetCheckpointState(quint32 index) const;

    void SetCheckpoint(quint32 index, bool checked);
    
    bool GetStartSucceeded() const;
    
    void SetStartSucceeded(bool value);
    
    bool GetLaneChangeSucceeded() const;
    
    void SetLaneChangeSucceeded(bool value);

    qint64 GetTimeCredit() const;

    static quint32 CalculateSkillRacePoints(vector<bool> checkpointStates, bool startSucceeded, bool laneChangeSucceeded);

    quint32 GetSerializedCheckpointStates() const;

};



#endif //_SKILLRACE_H
