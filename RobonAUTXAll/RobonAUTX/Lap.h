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
    Lap();

    quint32 laserTime;
    quint32 manualTime;
    TimeSourceType choosenLapType;
    bool isWarmUp;

    quint32 GetChoosenLapTime();
};

#endif //_LAP_H
