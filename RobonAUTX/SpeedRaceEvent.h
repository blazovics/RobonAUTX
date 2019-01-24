/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SPEEDRACEEVENT_H
#define SPEEDRACEEVENT_H

#include "RaceEvent.h"


class SpeedRaceEvent: public RaceEvent {
public: 
    
/**
 * @param teamID
 */
void InitRace(quint32 teamID);
    
/**
 * @param touchCount
 */
void ModifyTouchCount(quint32 touchCount);
    
/**
 * @param timeType
 */
quint32 FinishLap(TimeSourceType timeType);
    
void StartRace();
    
void SaveRace();
    
void AbortRace();
private: 
    Lap actualLap;
    quint32 actualLapNumber;
    quint32 raceTimerOffset;
};

#endif //_SPEEDRACEEVENT_H
