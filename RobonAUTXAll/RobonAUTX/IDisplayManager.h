/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef IDISPLAYMANAGER_H
#define IDISPLAYMANAGER_H

#include <QObject>
#include "Team.h"
#include "SpeedRaceResult.h"
#include "SkillRaceResult.h"
#include "VoteResult.h"
#include "QualificationResult.h"
#include "FinalResult.h"

class IDisplayManager : public QObject {

    Q_OBJECT

public slots:

    virtual void showSpeedResults(QList<SpeedRaceResult> result, bool isJunior, quint32 fromPos) = 0;
    virtual void showSkillResults(QList<SkillRaceResult> result, quint32 fromPos) = 0;
    virtual void showFinalResults(QList<FinalResult> result, bool isJunior, quint32 fromPos) = 0;
    virtual void showFinalResultAtPosition(QList<FinalResult> result, bool isJunior, quint32 position) = 0;
    virtual void showVotesResults(QList<VoteResult> result, quint32 fromPos) = 0;
    virtual void showQualificationResults(QList<QualificationResult> result, quint32 fromPos) = 0;
    virtual void showInterRaceScreen() = 0;
    virtual void SkillRaceInitiated() = 0;
    virtual void SpeedRaceInitiated() = 0;  
    virtual void StartTimer() = 0;
    virtual void SetTimerValue(quint32 value) = 0;
    virtual void StopTimer() = 0;
    virtual void SpeedLapCompleted(quint32 lapNumber, quint32 lapTime) = 0;
    virtual void SkillPointUpdated(quint32 skillPoint) = 0;
    virtual void TeamListUpdated(QList<Team> teams) = 0;
    virtual void TeamSelected(quint32 teamID) = 0;

};

#endif //_IDISPLAYMANAGER_H
