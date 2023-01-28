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

    Q_OBJECT

private:
     qint64 remainingTime;

public: 
    explicit SkillRaceEvent(std::shared_ptr<DatabaseManager> dbManager, CentralController* centralController, QObject *parent = nullptr);
    /**
 * @param teamID
 */
    void InitRace(quint32 teamID);
    
    /**
 * @param index
 * @param checked
 * @param forced - Enables to alternate the status after the race is over.
 */
    bool UpdateCheckpoint(quint32 index, CheckpointState newState, bool forced);

    CheckpointState GetCheckpointState(quint32 index);

    CheckpointState RevertCheckpoint(quint32 index);

    //bool IsLastCheckpointReached();

    void SetStartSucceeded(bool value);

    void SetLaneChangeSuccess(bool value);

    quint32 UpdateTouchCount(quint32 newValue);
    
    void StartRace();
    
    void SaveRace();
    
    void AbortRace();

    RaceEventType getType();

    quint32 GetActualPoints();
    qint32 GetActualAbsolutePoints();

    quint32 GetTimeCredit();

    quint64 GetLaneChangeTime();
    quint32 GetLaneChangePoint();

    qint64 getRemainingTime();

    qint32 GetTouchPenaltyPoint();

public slots:
    void UpdateTimerFired();

protected:
    void updateRemainingTime();
};

#endif //_SKILLRACEEVENT_H
