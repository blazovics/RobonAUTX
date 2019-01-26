/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SPEEDRACEEVENT_H
#define SPEEDRACEEVENT_H

#include "RaceEvent.h"

class SpeedRaceEvent: public RaceEvent {

    Lap actualLap;
    quint32 raceTimerOffset;

public: 
   explicit SpeedRaceEvent(std::shared_ptr<DatabaseManager> dbManager, QObject *parent = nullptr);

    void InitRace(quint32 teamID);

    quint32 ModifyTouchCount(quint32 touchCount);

    quint32 LaserTimeReceived();

    quint32 ManualTimeReceived();

    quint32 FinishLap(TimeSourceType timeType);

    quint32 GetFinishedLapCount() const;

    void SetSafetyCarFollowed(bool value);

    void SetSafetyCarOvertaken(bool value);
    
    void StartRace();
    
    void SaveRace();
    
    void AbortRace();

public slots:
    void UpdateTimerFired();

private:
    void resetActualLap();

};

#endif //_SPEEDRACEEVENT_H
