/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RaceControlUnit.h"

/**
 * RaceControlUnit implementation
 */


/**
 * Should raie exception when the teamID is not valid.
 * @param teamID
 * @return Team
 */
RaceControlUnit::RaceControlUnit(QObject *parent):QObject(parent)
{

}

RaceControlUnit::~RaceControlUnit()
{

}

Team RaceControlUnit::getTeamForID(quint32 teamID) {
    Team returnTeam;
    throw "NL";
    return returnTeam;
}
