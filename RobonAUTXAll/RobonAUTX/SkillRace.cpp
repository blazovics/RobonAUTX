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
const quint32 SkillRace::touchPenaltyPoint = SkillTouchPenaltyPoint;

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



quint32 SkillRace::GetTouchCount() const
{
    return touchCount;
}

qint32 SkillRace::GetTouchPenaltyPoint() const
{
    return  - touchCount * touchPenaltyPoint;
}

quint32 SkillRace::UpdateTouchCount(quint32 newTouchCount)
{
    if(newTouchCount < 9){
        touchCount = newTouchCount;
    }
    return touchCount;
}

bool SkillRace::IsAllCheckpointReached()
{
    for(unsigned i = 0; i<checkpointCount; i++)
    {
        if(!(checkpointStates[i] == Checked || checkpointStates[i] == PirateFirstChecked || checkpointStates[i] == PirateSecond)){
            return false;
        }
    }
    return true;
}

SkillRace::SkillRace(quint32 teamID):Race(teamID) {
    
    for(unsigned i = 0; i<checkpointCount; i++)
    {
        checkpointStates.push_back(Clear);
        prevCheckpointStates.push_back(vector<CheckpointState>());
    }
    startSucceeded = false;
    laneChangeSucceeded = false;
    laneChangeTime = 0;
    allCheckpointsReachedTime = 0;
    allCheckpointsReached = false;
    touchCount = 0;
}

quint32 SkillRace::GetRacePoint() const {
    return CalculateSkillRacePoints(this->checkpointStates,this->touchCount, this->startSucceeded, this->laneChangeSucceeded, this->laneChangeTime);
}

quint32 SkillRace::GetAbsoluteRacePoint() const
{
    return CalculateAbsoluteSkillRacePoints(this->checkpointStates,this->touchCount, this->startSucceeded, this->laneChangeSucceeded, this->laneChangeTime);
}

CheckpointState SkillRace::GetCheckpointState(quint32 index) const
{
    if(index < this->checkpointStates.size() )
    {
        return this->checkpointStates[index];
    }
    else
    {
        return Clear;
        //throw std::out_of_range("Bad checkpoint index");
    }
}
/**
 * @param index
 * @param checked
 */
void SkillRace::SetCheckpoint(quint32 index, CheckpointState newState, qint64 updateTime) {
    if(index < this->checkpointStates.size() )
    {
        this->prevCheckpointStates[index].push_back(this->checkpointStates[index]);
        this->checkpointStates[index] = newState;

        if (this->IsAllCheckpointReached() == true){
            this->allCheckpointsReached = true;
            this->allCheckpointsReachedTime = updateTime;
        }
        else {
            this->allCheckpointsReached = false;
        }
    }


}

CheckpointState SkillRace::RevertCheckpoint(quint32 index)
{
    if(!this->prevCheckpointStates[index].empty()){
        this->checkpointStates[index] = this->prevCheckpointStates[index].back();
        this->prevCheckpointStates[index].pop_back();

        if (this->IsAllCheckpointReached() == true){
            this->allCheckpointsReached = true;
            //Mark that checkpoint reached Time does not infected
        }
        else {
            this->allCheckpointsReached = false;
        }
    }
    return this->checkpointStates[index];
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

qint64 SkillRace::GetTimeCredit() const
{
    if (allCheckpointsReached){
       return allCheckpointsReachedTime < 4*60*1000 ?  allCheckpointsReachedTime + 1*60*1000 : allCheckpointsReachedTime + (5*60*1000 - allCheckpointsReachedTime);
    }
    else {
        return 5*60*1000;
    }
}

quint32 SkillRace::GetLaneChangePoint() const
{
    return laneChangeSucceeded ? laneChangePoint : 0;
}

quint32 SkillRace::GetCheckpointPoint(CheckpointState state)
{
    switch (state) {
    case Clear:
    case PirateSecondChecked:
    case PirateFirst:
    case PirateSecond:
        return 0;
        break;
    case PirateFirstChecked:
        return 1;
        break;
    case Checked:
        return 2;
        break;
    default:
        return 0;
    }
}

quint32 SkillRace::CalculateSkillRacePoints(vector<CheckpointState> checkpointStates, quint32 touchCount, bool startSucceeded, bool laneChangeSucceeded,  quint64 laneChangeTime)
{
    qint32 absoluteResultPoint = CalculateAbsoluteSkillRacePoints(checkpointStates, touchCount, startSucceeded, laneChangeSucceeded, laneChangeTime);

    quint32 resultPoint = absoluteResultPoint > 0 ? absoluteResultPoint : 0;

    return resultPoint;
}

qint32 SkillRace::CalculateAbsoluteSkillRacePoints(vector<CheckpointState> checkpointStates, quint32 touchCount, bool startSucceeded, bool laneChangeSucceeded, quint64 laneChangeTime)
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
    for(unsigned i = 0; i<touchCount; i++)
    {
        resultPoint -= touchPenaltyPoint;
    }

    resultPoint = resultPoint > 40 ? 40 : resultPoint;

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
