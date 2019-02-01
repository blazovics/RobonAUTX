/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef RACEEVENT_H
#define RACEEVENT_H

#include <QObject>
#include "Race.h"
#include "RTimer.h"
#include "DatabaseManager.h"
#include <memory>

#include <QTimer>

enum RaceEventType{
    Skill,
    Speed
};

class RaceEvent: public QObject {

    Q_OBJECT
protected:
    Race* actualRace;
    RTimer raceTimer;

    QTimer *updateTimer;

    std::shared_ptr<DatabaseManager> dbManager;

    void startRaceTimer();
    void stopRaceTimer();

public: 
    explicit RaceEvent(shared_ptr<DatabaseManager> dbManager, QObject *parent = nullptr);
    ~RaceEvent();
    
    /**
    * @param teamID
    */
    virtual void InitRace(quint32 teamID) = 0;

    virtual RaceEventType getType() = 0;
    
    virtual void StartRace();
    
    virtual void AbortRace();
    
    virtual void SaveRace();

    void PauseRaceTimer();

    void ResumeRaceTimer();

    void ReleaseActualRace();

public slots:
    virtual void UpdateTimerFired() = 0;

};

#endif //_RACEEVENT_H