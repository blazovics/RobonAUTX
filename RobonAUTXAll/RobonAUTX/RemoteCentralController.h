/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTECENTRALCONTROLLER_H
#define REMOTECENTRALCONTROLLER_H

#include "ICentralController.h"
#include "RemoteDevice.h"

#include "CentralController.h"

class RemoteCentralController: public ICentralController, public RemoteDevice {

    Q_OBJECT

    CentralController* localController;

public:
    explicit RemoteCentralController(CoreController* parentController, QTcpSocket *socket, QIODevice::OpenMode mode = QIODevice::WriteOnly);
    virtual ~RemoteCentralController();

    CentralController *getLocalController() const;
    void setLocalController(CentralController *value);

public slots:

    void EventReceived(Event& event);

    void InitSkillRace(quint32 teamID);
    void InitSpeedRace(quint32 teamID);
    void UpdateVotesForTeam(quint32 teamID, quint32 voteCount);
    void ManualMeasureReceived();
    void LaserMeasureReceived(quint32 time);
    void TimeSourceForLapSelected(TimeSourceType timeSource);
    void UpdateCheckpointState(quint32 checkpointID, bool checked, bool forced);
    void UpdateTargetCheckpoint(quint32 checkpointID);
    void StartRace();
    void FinishRace(bool aborted);
    void TeamListRequested();
    void VechicleStartAchieved(bool achieved);
    void LaneChangeAchieved(bool achieved);
    void SafetyCarFollowed(bool achieved);
    void SafetyCarOvertaken(quint32 value);
    void ModifyTouchCount(quint32 touchCount);
    void ModifyWrongGateCount(quint32 wrongGateCount);
    void WrongGatePassed();

    void ShowSpeedResults(bool isJunior, quint32 fromPos);
    void ShowSkillResults(quint32 fromPos);
    void ShowFinalResults(bool isJunior, quint32 fromPos);
    void ShowFinalResultAtPosition(bool isJunior, quint32 position);
    void ShowVotesResults(quint32 fromPos);
    void ShowQualificationResults(quint32 fromPos);
    void ShowInterRaceScreen();

    void SkillGateStarted();

    void PauseRaceTimer();
    void ResumeRaceTimer();

    void UpdateBSS(quint32 actionType);
};

#endif //_REMOTECENTRALCONTROLLER_H
