/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SPEEDRACE_H
#define SPEEDRACE_H

#define MaximumProhibitedTouchCount 5

#include "Race.h"
#include "Lap.h"

class SpeedRace: public Race {

private:
    Lap warmUpLap;
    QList<Lap> completedLaps;
    bool safetyCarFollowed;
    quint32 safetyCarOvertaken;
    quint32 touchCount;

    static const quint32 maximumProhibitedTouchCount;

public: 
    
    /**
 * @param teamID
 */
    SpeedRace(quint32 teamID);
    
    quint32 GetPenaltyPoint() const;

    qint32 GetAdditionalPoint() const;
    
    quint32 GetBestLapTime() const;

    QList<quint32> GetLapTimes() const;
    
    quint32 GetLapTime(int lapIndex) const;
    
    void SetProhibitedTouchCount(quint32 touchCount);

    quint32 GetProhibitedTouchTouchCount();

    quint32 GetCompletedLapCount() const;
    
    bool GetSafetyCarFollowed() const;
    
    void SetSafetyCarFollowed(bool value);
    
    quint32 GetSafetyCarOvertaken() const;
    
    void SetSafetyCarOvertaken(quint32 value);
    
    void AddCompletedLap(const Lap &newLap);

    const Lap& GetWarmUpLap() const;

    void SetWarmUpLap(const Lap &value);

    const QList<Lap>& GetCompletedLaps() const;

    quint32 GetTouchCount() const;
};

#endif //_SPEEDRACE_H
