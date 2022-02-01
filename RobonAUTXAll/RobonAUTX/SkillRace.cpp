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
const quint32 SkillRace::wrongGatePoint = SkillWrongGatePoint;

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

quint32 SkillRace::getLaneChangeTime() const
{
    return laneChangeTime;
}

void SkillRace::setWrongGateCount(quint32 newWrongGateCount)
{
    wrongGateCount = newWrongGateCount;
}

quint32 SkillRace::GetWrongGateCount() const
{
    return this->wrongGateCount;
}

quint32 SkillRace::GetWrongGatePoint() const
{
    return CalculateWrongGatePoints(this->wrongGateCount);
}

SkillRace::SkillRace(quint32 teamID):Race(teamID) {
    
    for(unsigned i = 0; i<checkpointCount; i++)
    {
        checkpointStates.push_back(false);
    }
    startSucceeded = false;
    laneChangeSucceeded = false;
    laneChangeTime = 0;
    wrongGateCount = 0;
}

quint32 SkillRace::GetRacePoint() const {
    return CalculateSkillRacePoints(this->checkpointStates,this->startSucceeded, this->laneChangeSucceeded, this->wrongGateCount, this->laneChangeTime);
}

bool SkillRace::GetCheckpointState(quint32 index) const
{
    if(index < this->checkpointStates.size() )
    {
        return this->checkpointStates[index];
    }
    else
    {
        //throw std::out_of_range("Bad checkpoint index");
    }
}

/**
 * @param index
 * @param checked
 */
void SkillRace::SetCheckpoint(quint32 index, bool checked) {

    this->checkpointStates[index] = checked;
}

void SkillRace::SetTargetCheckpoint(quint32 index)
{
    for(unsigned i = 0; i<index; i++)
    {
        checkpointStates[i] = true;
    }
    for(unsigned i = index; i<checkpointCount; i++)
    {
        checkpointStates[i] = false;
    }
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
void SkillRace::SetLaneChangeSucceeded(bool value, qint64 laneChangeTime) {
    this->laneChangeSucceeded = value;
    this->laneChangeTime = laneChangeTime > 0 ? laneChangeTime: 0;
}

bool SkillRace::IsLastCheckpointReached()
{
    return checkpointStates[checkpointStates.size()-1];
}

qint64 SkillRace::GetTimeCredit() const
{
    //TODO: Change this to be more robust
    qint64 timeCredit = 20*1000;
    for(unsigned i = 0; i < checkpointStates.size(); i++)
    {
        if(checkpointStates[i] == true)
        {
            timeCredit += 15*1000;
        }
    }

    return  timeCredit;
}

quint32 SkillRace::GetLaneChangePoint() const
{
    quint32 unlimitedPoint = laneChangeTime / 5000;
    return unlimitedPoint > laneChangePoint ? laneChangePoint : unlimitedPoint;
}

quint32 SkillRace::CalculateSkillRacePoints(vector<bool> checkpointStates, bool startSucceeded, bool laneChangeSucceeded, quint32 wrongGateCount, quint64 laneChangeTime)
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
        quint32 unlimitedPoint = laneChangeTime / 5000;
        resultPoint += unlimitedPoint > laneChangePoint ? laneChangePoint : unlimitedPoint;
    }

    quint32 wrongGatePenaltyPoint = CalculateWrongGatePoints(wrongGateCount);

    if(resultPoint > wrongGatePenaltyPoint)
    {
        resultPoint -= wrongGatePenaltyPoint;
    }
    else{
        resultPoint = 0;
    }

    return resultPoint;
}

quint32 SkillRace::CalculateWrongGatePoints(quint32 wrongGateCount)
{
    return wrongGateCount * wrongGatePoint;
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
