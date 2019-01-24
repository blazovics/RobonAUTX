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
void SpeedRace::SpeedRace(quint32 teamID) {

}

/**
 * @return quint32
 */
quint32 SpeedRace::GetPenaltyPoint() {
    return null;
}

/**
 * @return quint32
 */
quint32 SpeedRace::GetBestLapTime() {
    return null;
}

/**
 * @return vector<quint32>
 */
vector<quint32> SpeedRace::GetLapTimes() {
    return null;
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