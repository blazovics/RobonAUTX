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

    Q_OBJECT

public slots:

    void showSpeedResults(QList<SpeedRaceResult> result, bool isJunior, quint32 fromPos);
    void showSkillResults(QList<SkillRaceResult> result, quint32 fromPos);
    void showFinalResults(QList<FinalResult> result, bool isJunior, quint32 fromPos);
    void showFinalResultAtPosition(QList<FinalResult> result, bool isJunior, quint32 position);
    void showVotesResults(QList<VoteResult> result, quint32 fromPos);
    void showQualificationResults(QList<QualificationResult> result, quint32 fromPos);

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
