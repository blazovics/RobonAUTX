/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "Race.h"

/**
 * Race implementation
 */

/**
 * @param teamID
 */
Race::Race(quint32 teamID) {
    this->teamID = teamID;
}


/**
 * @return quint32
 */
quint32 Race::getTeamID() {
    return teamID;
}

/**
 * @param value
 */
void Race::setTeamID(quint32 value) {
    this->teamID = value;
}

