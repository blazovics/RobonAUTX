/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef RACE_H
#define RACE_H

#include "DBRecord.h"


class Race: public DBRecord {
protected:
    quint32 teamID;

public: 

    /**
    * @param teamID
    */
    Race(quint32 teamID);

    quint32 getTeamID();
    
    /**
 * @param value
 */
    void setTeamID(quint32 value);
    
};

#endif //_RACE_H
