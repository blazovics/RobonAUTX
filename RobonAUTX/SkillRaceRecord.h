/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SKILLRACERECORD_H
#define SKILLRACERECORD_H

#include "RaceRecord.h"
#include "SkillRace.h"


class SkillRaceRecord: public RaceRecord {
public:
    quint32 checkpointsState;
    quint32 racePoint;
    bool laneChangeSucceeded;
    bool startSucceeded;
    
/**
 * @param skillRace
 */
void SkillRaceResult(SkillRace skillRace);
};

#endif //_SKILLRACERECORD_H
