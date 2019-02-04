/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */

#include "SkillRace.h"
#include <stdexcept>

const quint32 SkillRace::checkpointCount = SkillCheckpointCount;
const quint32 SkillRace::checkpointPoint = SkillCheckpointPoint;
const quint32 SkillRace::startPoint = SkillStartPoint;
const quint32 SkillRace::laneChangePoint = SkillLaneChangePoint;

/**
 * SkillRace implementation
 */

qint64 SkillRace::getRaceTime() const
{
    return raceTime;
}

void SkillRace::setRaceTime(const qint64 &value)
{
    raceTime = value;
}

SkillRace::SkillRace(quint32 teamID):Race(teamID) {
    
    for(unsigned i = 0; i<checkpointCount; i++)
    {
        checkpointStates.push_back(false);
    }
    startSucceeded = false;
    laneChangeSucceeded = false;
}

quint32 SkillRace::GetRacePoint() const {
    return CalculateSkillRacePoints(this->checkpointStates,this->startSucceeded, this->laneChangeSucceeded);
}

bool SkillRace::GetCheckpointState(quint32 index) const
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
bool SkillRace::GetStartSucceeded() const {
    return startSucceeded;
}

/**
 * @param value
 */
void SkillRace::SetStartSucceeded(bool value) {
    this->startSucceeded = value;
}

/**
 * @return bool
 */
bool SkillRace::GetLaneChangeSucceeded() const {
    return laneChangeSucceeded;
}

/**
 * @param value
 */
void SkillRace::SetLaneChangeSucceeded(bool value) {
    this->laneChangeSucceeded = value;
}

qint64 SkillRace::GetTimeCredit() const
{
    //TODO: Change this to be more robust
    qint64 timeCredit = 20*1000;
    for(unsigned i = 1; i < checkpointStates.size(); i++)
    {
        if(checkpointStates[i] == true)
        {
            timeCredit += 10*1000;
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
            resultPoint += checkpointPoint;
        }
    }
    if(startSucceeded == true)
    {
        resultPoint += startPoint;
    }
    if(laneChangeSucceeded == true)
    {
        resultPoint += laneChangePoint;
    }
    return resultPoint;
}

quint32 SkillRace::GetSerializedCheckpointStates() const
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
