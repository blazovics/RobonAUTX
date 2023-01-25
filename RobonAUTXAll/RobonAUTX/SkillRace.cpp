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



SkillRace::SkillRace(quint32 teamID):Race(teamID) {
    
    for(unsigned i = 0; i<checkpointCount; i++)
    {
        checkpointStates.push_back(Clean);
    }
    startSucceeded = false;
    laneChangeSucceeded = false;
    laneChangeTime = 0;
}

quint32 SkillRace::GetRacePoint() const {
    return CalculateSkillRacePoints(this->checkpointStates,this->startSucceeded, this->laneChangeSucceeded, this->laneChangeTime);
}

quint32 SkillRace::GetAbsoluteRacePoint() const
{
    return CalculateAbsoluteSkillRacePoints(this->checkpointStates,this->startSucceeded, this->laneChangeSucceeded, this->laneChangeTime);
}

CheckpointState SkillRace::GetCheckpointState(quint32 index) const
{
    if(index < this->checkpointStates.size() )
    {
        return this->checkpointStates[index];
    }
    else
    {
        return Clean;
        //throw std::out_of_range("Bad checkpoint index");
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
#warning "DEPRECATED IMPLEMENTATION"
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

quint32 SkillRace::GetCheckpointPoint(CheckpointState state)
{
    switch (state) {
    case Clean:
    case PirateSecondChecked:
    case PirateFirst:
    case PlayerFirst:
        return 0;
        break;
    case PirateFirstChecked:
        return 1;
        break;
    case PirateSecond:
        return 2;
        break;
    default:
        return 0;
    }
}

quint32 SkillRace::CalculateSkillRacePoints(vector<CheckpointState> checkpointStates, bool startSucceeded, bool laneChangeSucceeded,  quint64 laneChangeTime)
{
    qint32 absoluteResultPoint = CalculateAbsoluteSkillRacePoints(checkpointStates, startSucceeded, laneChangeSucceeded, laneChangeTime);

    quint32 resultPoint = absoluteResultPoint > 0 ? absoluteResultPoint : 0;

    return resultPoint;
}

qint32 SkillRace::CalculateAbsoluteSkillRacePoints(vector<CheckpointState> checkpointStates, bool startSucceeded, bool laneChangeSucceeded, quint64 laneChangeTime)
{
    qint32 resultPoint = 0;
    for(unsigned i = 0; i < checkpointStates.size(); i++)
    {
        resultPoint += GetCheckpointPoint(checkpointStates[i]);
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

    return resultPoint;
}



quint64 SkillRace::GetSerializedCheckpointStates() const
{
    quint64 checkpointState = 0;
    for(unsigned i = 0; i < checkpointStates.size(); i++)
    {
        checkpointState |= checkpointStates[i]<<i*4;
    }
    return  checkpointState;
}
