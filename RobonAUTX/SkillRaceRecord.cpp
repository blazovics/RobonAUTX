/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "SkillRaceRecord.h"

/**
 * SkillRaceRecord implementation
 */


/**
 * @param skillRace
 */
void SkillRaceRecord::SkillRaceResult(SkillRace skillRace) {

    this->checkpointsState = skillRace.GetSerializedCheckpointStates();
    this->racePoint = skillRace.GetRacePoint();
    this->laneChangeSucceeded = skillRace.GetLaneChangeSucceeded();
    this->startSucceeded = skillRace.GetStartSucceeded();
}
