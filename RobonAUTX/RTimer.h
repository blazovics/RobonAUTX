/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef RTIMER_H
#define RTIMER_H

#include <QObject>
#include <QElapsedTimer>

enum TimerState{
    Stopped,
    Running,
    Paused
};

class RTimer: public QObject {

    Q_OBJECT

    QElapsedTimer elapsedTimer;
    QElapsedTimer pauseTimer;
    qint64 pauseOffset;

    TimerState timerState;

public: 
    explicit RTimer(QObject* parent = nullptr);

    void StartTimer();
    
    void StopTimer();
    
    void PauseTimer();
    
    void ResumeTimer();
    
    /**
 * @param elapsed
 */
    qint64 Elapsed();
    TimerState getTimerState() const;
    void setTimerState(const TimerState &value);
};

#endif //_RTIMER_H
