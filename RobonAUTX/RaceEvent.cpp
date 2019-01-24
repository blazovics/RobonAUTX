/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RaceEvent.h"

/**
 * RaceEvent implementation
 */

RaceEvent::RaceEvent(DatabaseManager& dbManager, QObject *parent):QObject (parent),dbManager(dbManager)
{
    actualRace = nullptr;
    updateTimer = new QTimer();
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(updateTimerFired()));
}

RaceEvent::~RaceEvent()
{
    ReleaseActualRace();
    updateTimer->stop();
    delete updateTimer;
}

void RaceEvent::StartRace()
{
    startRaceTimer();
}

void RaceEvent::AbortRace()
{
    stopRaceTimer();
}

void RaceEvent::SaveRace()
{
    stopRaceTimer();
}

void RaceEvent::PauseRaceTimer()
{
    raceTimer.PauseTimer();
}

void RaceEvent::ResumeRaceTimer()
{
    raceTimer.ResumeTimer();
}

void RaceEvent::startRaceTimer() {
    raceTimer.StartTimer();
}

void RaceEvent::stopRaceTimer() {
    raceTimer.StopTimer();
}

void RaceEvent::ReleaseActualRace()
{
    if(this->actualRace != nullptr)
    {
        delete this->actualRace;
        this->actualRace = nullptr;
    }
}

