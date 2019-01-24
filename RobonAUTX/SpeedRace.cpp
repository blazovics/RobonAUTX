/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "SpeedRace.h"

/**
 * SpeedRace implementation
 */


/**
 * @param teamID
 */
SpeedRace::SpeedRace(quint32 teamID):Race(teamID) {

}

/**
 * @return quint32
 */
quint32 SpeedRace::GetPenaltyPoint() {
    return touchCount * 2;
}

/**
 * @return quint32
 */
quint32 SpeedRace::GetBestLapTime() {

    //WHAT ABOUT WARMUP?

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
QList<quint32> SpeedRace::GetLapTimes() {

    QList<quint32> times

    return comp;
}

/**
 * @param lapIndex
 * @return quint32
 */
quint32 SpeedRace::GetLapTime(quint32 lapIndex) {
    return null;
}

/**
 * @param touchCount
 */
void SpeedRace::UpdateProhibitedTouch(quint32 touchCount) {

}

/**
 * @return Lap
 */
Lap SpeedRace::getCompletedLaps() {
    return null;
}

/**
 * @param value
 */
void SpeedRace::setCompletedLaps(Lap value) {

}

/**
 * @return bool
 */
bool SpeedRace::getSafetyCarFollowed() {
    return false;
}

/**
 * @param value
 */
void SpeedRace::setSafetyCarFollowed(bool value) {

}

/**
 * @return bool
 */
bool SpeedRace::getSafetyCarOvertaken() {
    return false;
}

/**
 * @param value
 */
void SpeedRace::setSafetyCarOvertaken(bool value) {

}

/**
 * @return quint32
 */
quint32 SpeedRace::getTouchCount() {
    return null;
}

/**
 * @param value
 */
void SpeedRace::setTouchCount(quint32 value) {

}

/**
 * @param newLap
 */
void SpeedRace::AddCompletedLap(Lap newLap) {

}
