#ifndef CONTROLUNITCONTROLLER_H
#define CONTROLUNITCONTROLLER_H

#include "CoreController.h"
#include "RemoteCentralController.h"
#include "RaceControlUnit.h"
#include "RemoteRaceControlUnit.h"

class ControlUnitController : public CoreController
{
    Q_OBJECT

    std::unique_ptr<RaceControlUnit> raceControlUnit;
    std::unique_ptr<RemoteRaceControlUnit> proxiRaceControlUnit;

    std::shared_ptr<RemoteCentralController> remoteCentralController;

    QTcpSocket socket;

public:
    explicit ControlUnitController();

    void ConnectToServer();

    void RemoteDeviceDisconnected(RemoteDevice* device, QTcpSocket* socket);

public slots:
    void SocketConnected();
    void SocketDisconnected();
    void SocketError(QAbstractSocket::SocketError error);
};

#endif // CONTROLUNITCONTROLLER_H
