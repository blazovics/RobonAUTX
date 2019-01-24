/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef RACERECORD_H
#define RACERECORD_H

#include "DBRecord.h"


class RaceRecord: public DBRecord {
public: 
    quint32 teamID;
};

#endif //_RACERECORD_H