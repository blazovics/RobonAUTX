/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "Team.h"
#include <QDataStream>

/**
 * Team implementation
 */


/**
 * @return QByteArray
 */
Team::Team()
{

}

Team::Team(QByteArray data)
{
    QDataStream memoryStream(&data,QIODevice::ReadOnly);

    memoryStream >> this->name;
    memoryStream >> this->teamID;
    memoryStream >> this->audiencePoint;
    memoryStream >> this->qualificationPoint;
}

QByteArray Team::serialize() {
    QByteArray returnArray;

    QDataStream memoryStream(&returnArray,QIODevice::ReadWrite);

    memoryStream << name;
    memoryStream << teamID;
    memoryStream << audiencePoint;
    memoryStream << qualificationPoint;

    return returnArray;
}
