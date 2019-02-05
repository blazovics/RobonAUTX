/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "IDisplayManager.h"


class DisplayManager: public IDisplayManager {
    Q_OBJECT

public:
    DisplayManager();

    virtual ~DisplayManager();

public slots:

    void showSpeedResults(QList<SpeedRaceResult> result, bool isJunior, quint32 fromPos);
    void showSkillResults(QList<SkillRaceResult> result, quint32 fromPos);
    void showFinalResults(QList<FinalResult> result, bool isJunior, quint32 fromPos);
    void showFinalResultAtPosition(QList<FinalResult> result, bool isJunior, quint32 position);
    void showVotesResults(QList<VoteResult> result, quint32 fromPos);
    void showQualificationResults(QList<QualificationResult> result, quint32 fromPos);
    void showInterRaceScreen();
    void SkillRaceInitiated(quint32 teamID);
    void SpeedRaceInitiated(quint32 teamID);

    void LaneChangeAchieved(bool success);
    void VehicleStartAchieved(bool success);
    void SafetyCarFollowed(bool success);
    void SafetyCarOvertaken(bool success);
    void CheckpointStateUpdated(quint32 checkpointID, bool state);

    void SpeedLapCompleted(quint32 lapNumber, quint32 lapTime);
    void SkillPointUpdated(quint32 skillPoint, quint32 timeCredit);
    void TeamListUpdated(QList<Team> teams);
};

#endif //_DISPLAYMANAGER_H
