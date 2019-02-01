#ifndef MAINSYSTEMCONTROLLER_H
#define MAINSYSTEMCONTROLLER_H

#include <QTcpServer>
#include "CoreController.h"

#include "RemoteCentralController.h"
#include "RemoteDisplayManager.h"
#include "RemoteLaserGate.h"
#include "RemoteRaceControlUnit.h"
#include "RemoteSafetyCar.h"
#include "RemoteSkillRaceFieldUnit.h"
#include "RemoteSkillRaceGate.h"
#include "RemoteVoteCounter.h"
#include "CentralController.h"
#include "RemoteCentralController.h"

class MainSystemController : public CoreController
{
    Q_OBJECT

    std::unique_ptr<CentralController> centralController;
    std::unique_ptr<RemoteCentralController> proxiCentralController;

    QPair<std::shared_ptr<RemoteLaserGate>,QTcpSocket*> remoteLaserGate;
    QPair<std::shared_ptr<RemoteSkillRaceFieldUnit>,QTcpSocket*> remoteSkillRaceFieldUnit;
    QPair<std::shared_ptr<RemoteVoteCounter>,QTcpSocket*> remoteVoteCounter;
    QPair<std::shared_ptr<RemoteSkillRaceGate>,QTcpSocket*> remoteSkillRaceGate;
    QList<std::shared_ptr<QPair<std::shared_ptr<RemoteRaceControlUnit>,QTcpSocket*>>> remoteRaceControlUnits;
    QList<std::shared_ptr<QPair<std::shared_ptr<RemoteDisplayManager>,QTcpSocket*>>> remoteDisplayManagers;


    QTcpServer laserGateServer;
    QTcpServer skillRaceFieldUnitServer;
    QTcpServer voteCounterServer;
    QTcpServer skillRaceGateServer;
    QTcpServer raceControlUnitServer;
    QTcpServer displayManagerServer;

public:

    MainSystemController();

    void RemoteDeviceDisconnected(RemoteDevice* device, QTcpSocket* socket);

    void StartServers();

    void StopServers();

public slots:
    void newLaserGateConnection();
    void newSkillRaceFieldUnitConnection();
    void newVoteCounterConnection();
    void newSkillRaceGateConnection();
    void newRaceControlUnitConnection();
    void newDisplayManagerConnection();
};

#endif // MAINSYSTEMCONTROLLER_H
