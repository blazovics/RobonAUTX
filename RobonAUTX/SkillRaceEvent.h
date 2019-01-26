/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SKILLRACEEVENT_H
#define SKILLRACEEVENT_H

#include "RaceEvent.h"
#include "SkillRace.h"
#include <memory>

class SkillRaceEvent: public RaceEvent {

private:
     qint64 remainingTime;

public: 
    explicit SkillRaceEvent(std::shared_ptr<DatabaseManager> dbManager, QObject *parent = nullptr);
    /**
 * @param teamID
 */
    void InitRace(quint32 teamID);
    
    /**
 * @param index
 * @param checked
 * @param forced - Enables to alternate the status after the race is over.
 */
    void UpdateCheckpoint(quint32 index, bool newState, bool forced);

    void SetStartSucceeded(bool value);

    void SetLanChangeSuccess(bool value);
    
    void StartRace();
    
    void SaveRace();
    
    void AbortRace();

public slots:
    void UpdateTimerFired();

};

#endif //_SKILLRACEEVENT_H
