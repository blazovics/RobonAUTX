/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */

#include "SkillRace.h"
#include <stdexcept>

const unsigned SkillRace::checkpointCount = SkillCheckpointCount;

/**
 * SkillRace implementation
 */

/**
 * @param teamID
 */
SkillRace::SkillRace(quint32 teamID):Race(teamID) {

    for(unsigned i = 0; i<checkpointCount; i++)
    {
        checkpointStates.push_back(false);
    }
    startSucceeded = false;
    laneChangeSucceeded = false;
}

quint32 SkillRace::GetRacePoint() {
    return CalculateSkillRacePoints(this->checkpointStates,this->startSucceeded, this->laneChangeSucceeded);
}

bool SkillRace::GetCheckpointState(quint32 index)
{
    if(index < this->checkpointStates.size() )
    {
        return this->checkpointStates[index];
    }
    else
    {
        throw std::out_of_range("Bad checkpoint index");
    }
}

/**
 * @param index
 * @param checked
 */
void SkillRace::SetCheckpoint(quint32 index, bool checked) {
    this->checkpointStates[index] = checked;
}

/**
 * @return bool
 */
bool SkillRace::getStartSucceeded() {
    return false;
}

/**
 * @param value
 */
void SkillRace::setStartSucceeded(bool value) {
    this->startSucceeded = value;
}

/**
 * @return bool
 */
bool SkillRace::getLaneChangeSucceeded() {
    return false;
}

/**
 * @param value
 */
void SkillRace::setLaneChangeSucceeded(bool value) {
    this->laneChangeSucceeded = value;
}

qint64 SkillRace::GetTimeCredit()
{
    qint64 timeCredit = 20;
    for(unsigned i = 0; i < checkpointStates.size(); i++)
    {
        if(checkpointStates[i] == true)
        {
            timeCredit += 10;
        }
    }

    return  timeCredit;
}

quint32 SkillRace::CalculateSkillRacePoints(vector<bool> checkpointStates, bool startSucceeded, bool laneChangeSucceeded)
{
    quint32 resultPoint = 0;
    for(unsigned i = 0; i < checkpointStates.size(); i++)
    {
        if(checkpointStates[i] == true)
        {
            resultPoint += 2;
        }
    }
    if(startSucceeded == true)
    {
        resultPoint += 2;
    }
    if(laneChangeSucceeded == true)
    {
        resultPoint += 2;
    }
    return resultPoint;
}

quint32 SkillRace::SerializeCheckpointStates()
{
    quint32 checkpointState = 0;
    for(unsigned i = 0; i < checkpointStates.size(); i++)
    {
        if(checkpointStates[i] == true)
        {
            checkpointState |= 1<<i;
        }
        else
        {
            checkpointState &= ~(1<<i);
        }
    }
    return  checkpointState;
}
