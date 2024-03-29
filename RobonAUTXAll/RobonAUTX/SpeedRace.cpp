/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "SpeedRace.h"
#include <stdexcept>

/**
 * SpeedRace implementation
 */

const unsigned SpeedRace::maximumProhibitedTouchCount = MaximumProhibitedTouchCount;

/**
 * @param teamID
 */
const Lap& SpeedRace::GetWarmUpLap() const
{
    return warmUpLap;
}

void SpeedRace::SetWarmUpLap(const Lap &value)
{
    this->warmUpLap = value;
}

const QList<Lap>& SpeedRace::GetCompletedLaps() const
{
    return completedLaps;
}

quint32 SpeedRace::GetTouchCount() const
{
    return touchCount;
}

SpeedRace::SpeedRace(quint32 teamID):Race(teamID) {
    this->touchCount = 0;
    this->safetyCarFollowed = false;
    this->safetyCarOvertaken = 0;
}

/**
 * @return quint32
 */
quint32 SpeedRace::GetPenaltyPoint() const {
    //TODO Make penalty calculation more static a configurable
    return touchCount * 2;
}

qint32 SpeedRace::GetAdditionalPoint() const
{
    qint32 additionalPoint = 0;
    if(this->safetyCarFollowed)
    {
        additionalPoint += 5;
    }
    if(this->safetyCarOvertaken > 0)
    {
        additionalPoint += 5 * this->safetyCarOvertaken;
    }

    additionalPoint -= touchCount * 2;

    return  additionalPoint;
}

/**
 * @return quint32
 */
quint32 SpeedRace::GetBestLapTime() const {

    quint32 fastestTime = 0;
    for(int i=0; i<this->completedLaps.length(); i++)
    {
         Lap actualLap = this->completedLaps[i];
         quint32 candidateTime = actualLap.GetChoosenLapTime();

         if(i == 0)
         {
             fastestTime = candidateTime;
         }
         else if(fastestTime > candidateTime)
         {
             fastestTime = candidateTime;
         }
    }

    return fastestTime;
}

/**
 * @return vector<quint32>
 */
QList<quint32> SpeedRace::GetLapTimes() const{

    QList<quint32> times;
    for(int i=0; i<this->completedLaps.length(); i++)
    {
        Lap actualLap = this->completedLaps[i];
        times.push_back(actualLap.GetChoosenLapTime());
    }

    return times;
}

/**
 * @param lapIndex
 * @return quint32
 */
quint32 SpeedRace::GetLapTime(int lapIndex) const{
    if(lapIndex >= completedLaps.size())
    {
        //throw std::out_of_range("required lap not exists");
    }

    Lap actualLap = this->completedLaps[lapIndex];
    return actualLap.GetChoosenLapTime();
}

quint32 SpeedRace::GetProhibitedTouchTouchCount()
{
    return this->touchCount;
}

quint32 SpeedRace::GetCompletedLapCount() const
{
    return quint32(completedLaps.count());
}

/**
 * @param touchCount
 */
void SpeedRace::SetProhibitedTouchCount(quint32 touchCount) {
    if(touchCount > SpeedRace::maximumProhibitedTouchCount)
    {
        touchCount = SpeedRace::maximumProhibitedTouchCount;
    }
    else {
        this->touchCount = touchCount;
    }
}


bool SpeedRace::GetSafetyCarFollowed() const{
    return this->safetyCarFollowed;
}

void SpeedRace::SetSafetyCarFollowed(bool value) {
    this->safetyCarFollowed = value;
}

quint32 SpeedRace::GetSafetyCarOvertaken() const{
    return this->safetyCarOvertaken;
}

void SpeedRace::SetSafetyCarOvertaken(quint32 value) {
    this->safetyCarOvertaken = value;
}

/**
 * @param newLap
 */
void SpeedRace::AddCompletedLap(const Lap &newLap) {
    this->completedLaps.push_back(newLap);
}
