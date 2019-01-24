/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SKILLRACE_H
#define SKILLRACE_H

#define SkillCheckpointCount 12

#include "Race.h"
#include <vector>

using namespace std;

class SkillRace: public Race {

private:
    vector<bool> checkpointStates;
    bool startSucceeded;
    bool laneChangeSucceeded;

public: 
    
    static const unsigned checkpointCount;

    /**
    * @param teamID
    */
    SkillRace(quint32 teamID);
    
    quint32 GetRacePoint();
    
    bool GetCheckpointState(quint32 index);

    void SetCheckpoint(quint32 index, bool checked);
    
    bool getStartSucceeded();
    
    void setStartSucceeded(bool value);
    
    bool getLaneChangeSucceeded();
    
    void setLaneChangeSucceeded(bool value);

    qint64 GetTimeCredit();

    static quint32 CalculateSkillRacePoints(vector<bool> checkpointStates, bool startSucceeded, bool laneChangeSucceeded);

    quint32 SerializeCheckpointStates();

};



#endif //_SKILLRACE_H
