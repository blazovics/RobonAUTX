#ifndef CONTROLUNITCONTROLLER_H
#define CONTROLUNITCONTROLLER_H

#include "CoreController.h"
#include "RemoteCentralController.h"
#include "RaceControlUnit.h"
#include "RemoteRaceControlUnit.h"

#include <QHostAddress>

class ControlUnitController : public CoreController
{
    Q_OBJECT

    std::unique_ptr<RaceControlUnit> raceControlUnit;
    std::unique_ptr<RemoteRaceControlUnit> proxiRaceControlUnit;

    std::shared_ptr<RemoteCentralController> remoteCentralController;

    QTcpSocket socket;

    QHostAddress serverAddress;
    quint16 serverPort;

public:
    explicit ControlUnitController(QHostAddress serverAddress, quint16 serverPort = 35000);

    void ConnectToServer();
    void DisconnectFromServer();

    void RemoteDeviceDisconnected(RemoteDevice* device, QTcpSocket* socket);

    QHostAddress getServerAddress() const;
    void setServerAddress(const QHostAddress &value);

    quint16 getServerPort() const;
    void setServerPort(const quint16 &value);

public slots:
    void SocketConnected();
    void SocketDisconnected();
    void SocketError(QAbstractSocket::SocketError error);
};

#endif // CONTROLUNITCONTROLLER_H
