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

RTimer::RTimer(QObject *parent):QObject(parent),timerState(Stopped),elapsed(0)
{

}

void RTimer::StartTimer() {
    if(timerState == Stopped)
    {
        elapsedTimer.start();
        pauseOffset = 0;
        elapsed = 0;
        timerState = Running;
    }
    else{
        throw std::runtime_error("Failed to Start Timer");
    }

}

void RTimer::StopTimer() {

    if(timerState == Running || timerState == Paused)
    {
        elapsed = Elapsed();

        elapsedTimer.invalidate();
        if(timerState == Paused)
        {
            pauseTimer.invalidate();
        }
        timerState = Stopped;
    }
    else{
        throw std::runtime_error("Failed to Stop timer");
    }
}

void RTimer::PauseTimer() {
    if(timerState == Running)
    {
        pauseTimer.start();
        timerState = Paused;
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
        timerState = Running;
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
        return  elapsedTimer.elapsed() - pauseOffset - pauseTimer.elapsed();
    }
    else
    {
        return elapsed;
    }
}
