/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SPEEDRACE_H
#define SPEEDRACE_H

#include "Race.h"
#include "Lap.h"

class SpeedRace: public Race {

public: 
    
    /**
 * @param teamID
 */
    SpeedRace(quint32 teamID);
    
    quint32 GetPenaltyPoint();
    
    quint32 GetBestLapTime();
    
    QList<quint32> GetLapTimes();
    
    /**
 * @param lapIndex
 */
    quint32 GetLapTime(quint32 lapIndex);
    
    /**
 * @param touchCount
 */
    void UpdateProhibitedTouch(quint32 touchCount);
    
    Lap getCompletedLaps();
    
    /**
 * @param value
 */
    void setCompletedLaps(Lap value);
    
    bool getSafetyCarFollowed();
    
    /**
 * @param value
 */
    void setSafetyCarFollowed(bool value);
    
    bool getSafetyCarOvertaken();
    
    /**
 * @param value
 */
    void setSafetyCarOvertaken(bool value);
    
    quint32 getTouchCount();
    
    /**
 * @param value
 */
    void setTouchCount(quint32 value);
private: 
    QList<Lap> completedLaps;
    bool safetyCarFollowed;
    bool safetyCarOvertaken;
    quint32 touchCount;
    
    /**
 * @param newLap
 */
    void AddCompletedLap(Lap newLap);
};

#endif //_SPEEDRACE_H
