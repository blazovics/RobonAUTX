/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef IDISPLAYMANAGER_H
#define IDISPLAYMANAGER_H

#define Event_Disp_showSpeedResults 1
#define Event_Disp_showSkillResults 2
#define Event_Disp_showFinalResults 3
#define Event_Disp_showFinalResultAtPosition 4
#define Event_Disp_showVotesResults 5
#define Event_Disp_showQualificationResults 6
#define Event_Disp_showInterRaceScreen 7
#define Event_Disp_SkillRaceInitiated 8
#define Event_Disp_SpeedRaceInitiated 9

#define Event_Disp_LaneChangeAchieved 10
#define Event_Disp_VehicleStartAchieved 11
#define Event_Disp_SafetyCarFollowed 12
#define Event_Disp_SafetyCarOvertaken 13
#define Event_Disp_CheckpointStateUpdated 14

#define Event_Disp_TeamListUpdated 15
#define Event_Disp_SpeedLapCompleted 16
#define Event_Disp_SkillPointUpdated 17

#define Device_IDisplayManager 300

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
    virtual void SkillRaceInitiated(quint32 teamID) = 0;
    virtual void SpeedRaceInitiated(quint32 teamID) = 0;

    virtual void LaneChangeAchieved(bool success) = 0;
    virtual void VehicleStartAchieved(bool success) = 0;
    virtual void SafetyCarFollowed(bool success) = 0;
    virtual void SafetyCarOvertaken(bool success) = 0;
    virtual void CheckpointStateUpdated(quint32 checkpointID, bool state) = 0;

    virtual void SpeedLapCompleted(quint32 lapNumber, quint32 lapTime) = 0;
    virtual void SkillPointUpdated(quint32 skillPoint, quint32 timeCredit) = 0;
    virtual void TeamListUpdated(QList<Team> teams) = 0;

};

#endif //_IDISPLAYMANAGER_H
