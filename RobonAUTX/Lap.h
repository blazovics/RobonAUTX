/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef LAP_H
#define LAP_H

#include "DBRecord.h"
#include "TimeSourceType.h"

class Lap: public DBRecord {
public: 
    quint32 laserTime;
    quint32 manualTime;
    TimeSourceType choosenLapTime;
    bool isWarmUp;
};

#endif //_LAP_H
