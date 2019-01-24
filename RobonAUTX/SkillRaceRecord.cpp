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

    this->checkpointsState = skillRace.SerializeCheckpointStates();
    this->racePoint = skillRace.GetRacePoint();
    this->laneChangeSucceeded = skillRace.getLaneChangeSucceeded();
    this->startSucceeded = skillRace.getStartSucceeded();
}
