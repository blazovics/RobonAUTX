/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTEDISPLAYMANAGER_H
#define REMOTEDISPLAYMANAGER_H

#include "IDisplayManager.h"
#include "RemoteDevice.h"


class RemoteDisplayManager: public IDisplayManager, public RemoteDevice {

public slots:
    void showSpeedResults(bool isJunior, quint32 fromPos);
    void showSkillResults(quint32 fromPos);
    void showFinalResults(bool isJunior, quint32 fromPos);
    void showFinalResultAtPosition(bool isJunior, quint32 position);
    void showVotesResults(quint32 fromPos);
    void showInterRaceScreen();
    void SkillRaceInitiated();
    void SpeedRaceInitiated();
    void StartTimer();
    void SetTimerValue(quint32 value);
    void StopTimer();
    void SpeedLapCompleted(quint32 lapNumber, quint32 lapTime);
    void SkillPointUpdated(quint32 skillPoint);
    void TeamListUpdated(QList<Team> teams);
    void TeamSelected(quint32 teamID);

};

#endif //_REMOTEDISPLAYMANAGER_H
