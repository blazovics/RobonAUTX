/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RTimer.h"

/**
 * RTimer implementation
 */


TimerState RTimer::getTimerState() const
{
    return timerState;
}

void RTimer::setTimerState(const TimerState &value)
{
    timerState = value;
}

RTimer::RTimer(QObject *parent):QObject(parent)
{
    timerState = Stopped;
}

void RTimer::StartTimer() {
    if(timerState == Stopped)
    {
        elapsedTimer.start();
        pauseOffset = 0;
    }
    else{
        throw "Failed to Start Timer";
    }

}

void RTimer::StopTimer() {
    if(timerState == Running)
    {
        elapsedTimer.invalidate();
    }
    else if(timerState == Paused)
    {
        elapsedTimer.invalidate();
        pauseTimer.invalidate();
    }
    else{
        throw "Failed to Stop timer";
    }
}

void RTimer::PauseTimer() {
    if(timerState == Running)
    {
        pauseTimer.start();
    }
    else{
        throw "Failed to Pause timer";
    }
}

void RTimer::ResumeTimer() {
    if(timerState == Paused)
    {
        pauseOffset += pauseTimer.elapsed();
        pauseTimer.invalidate();
    }
    else{
        throw "Failed to Resume timer";
    }
}

/**
 * @param elapsed
 */
qint64 RTimer::Elapsed() {
    if(timerState == Running)
    {
        return elapsedTimer.elapsed() - pauseOffset;
    }
    else if(timerState == Paused)
    {
        return  elapsedTimer.elapsed() - pauseOffset - elapsedTimer.elapsed();
    }
    else
    {
        throw "Timer is not running";
    }
}
