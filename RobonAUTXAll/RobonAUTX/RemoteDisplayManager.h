/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTEDISPLAYMANAGER_H
#define REMOTEDISPLAYMANAGER_H

#include "IDisplayManager.h"
#include "RemoteDevice.h"
#include "DisplayManager.h"

class RemoteDisplayManager: public IDisplayManager, public RemoteDevice {

    Q_OBJECT

    DisplayManager *localManager;

public:

    explicit RemoteDisplayManager(CoreController* parentController, QTcpSocket *socket, QIODevice::OpenMode mode = QIODevice::WriteOnly);
    virtual ~RemoteDisplayManager();

    DisplayManager* getLocalManager() const;
    void setLocalManager(DisplayManager *value);

public slots:

    void EventReceived(Event& event);

    void showSpeedResults(QList<SpeedRaceResult> result, bool isJunior, quint32 fromPos);
    void showSkillResults(QList<SkillRaceResult> result, quint32 fromPos);
    void showFinalResults(QList<FinalResult> result, bool isJunior, quint32 fromPos);
    void showFinalResultAtPosition(QList<FinalResult> result, bool isJunior, quint32 position);
    void showVotesResults(QList<VoteResult> result, quint32 fromPos);
    void showQualificationResults(QList<QualificationResult> result, quint32 fromPos);

    void LaneChangeAchieved(bool success);
    void VehicleStartAchieved(bool success);
    void SafetyCarFollowed(bool success);
    void SafetyCarOvertaken(bool success);
    void CheckpointStateUpdated(quint32 checkpointID, bool state);

    void showInterRaceScreen();
    void SkillRaceInitiated(quint32 teamID);
    void SpeedRaceInitiated(quint32 teamID);
    void SpeedLapCompleted(quint32 lapNumber, quint32 lapTime);
    void SkillPointUpdated(quint32 skillPoint, quint32 timeCredit);
    void TeamListUpdated(QList<Team> teams);

};

#endif //_REMOTEDISPLAYMANAGER_H
