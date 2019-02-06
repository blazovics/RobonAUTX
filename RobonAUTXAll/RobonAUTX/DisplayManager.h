/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "IDisplayManager.h"
#include <QElapsedTimer>
#include <QTimer>
#include <memory>
#include "RTimer.h"
#include "RaceEvent.h"
#include "QualificationResultModel.h"
#include "SkillRaceResultModel.h"
#include "SpeedRaceResultModel.h"
#include "VoteResultModel.h"
#include "FinalResultModel.h"


class DisplayManager: public IDisplayManager {
    Q_OBJECT

     Q_PROPERTY(quint32 teamID MEMBER m_teamID  NOTIFY teamIDChanged)

    quint32 m_teamID;

    RTimer raceTimer;

    QElapsedTimer speedRaceTimer;
    quint32 speedTimeOffset;
    std::unique_ptr<QTimer> updateTimer;

    RaceEventType eventType;
    quint32 timeCredit;

    QualificationResultModel qualificationResult;
    SkillRaceResultModel skillRaceResult;
    SpeedRaceResultModel speedRaceResult;
    VoteResultModel voteResult;
    FinalResultModel finalResult;

public:
    DisplayManager();

    virtual ~DisplayManager();

    QualificationResultModel *getQualificationResult();

    SkillRaceResultModel *getSkillRaceResult();

    SpeedRaceResultModel *getSpeedRaceResult();

    VoteResultModel* getVoteResult();

    FinalResultModel *getFinalResult();

signals:
    void teamIDChanged(const quint32 newTeamID);

    void sendLaneChangeAchieved(bool success);
    void sendVehicleStartAchieved(bool success);
    void sendSafetyCarFollowed(bool success);
    void sendSafetyCarOvertaken(bool success);
    void sendCheckpointStateUpdated(quint32 checkpointID, bool state);

    void sendSpeedLapCompleted(quint32 lapNumber, quint32 lapTime);
    void sendSkillPointUpdated(quint32 skillPoint);
    void sendTeamListUpdated(QList<Team> teams);

    void sendSkillRaceTime(QString time);
    void sendRemainingTime(QString itme);

    void presentSpeedResults();
    void presentSkillResults();
    void presentFinalResults();
    void presentFinalResultAtPosition();
    void presentVotesResults();
    void presentQualificationResults();

    void presentSkillRace();
    void presentSpeedRace();

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

    void RaceStarted();
    void RaceFinished(bool aborted);

    void TimerFired();
};

#endif //_DISPLAYMANAGER_H
