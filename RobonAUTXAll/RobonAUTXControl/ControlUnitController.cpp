#include "ControlUnitController.h"
#include "Configuration.h"

#include <QHostAddress>

QHostAddress ControlUnitController::getServerAddress() const
{
    return serverAddress;
}

void ControlUnitController::setServerAddress(const QHostAddress &value)
{
    serverAddress = value;
}

quint16 ControlUnitController::getServerPort() const
{
    return serverPort;
}

void ControlUnitController::setServerPort(const quint16 &value)
{
    serverPort = value;
}

RaceControlUnit *ControlUnitController::getRaceControlUnit() const
{
    return raceControlUnit.get();
}

ControlUnitController::ControlUnitController(QHostAddress serverAddress, quint16 serverPort):serverAddress(serverAddress),serverPort(serverPort)
{
    raceControlUnit = std::make_unique<RaceControlUnit>();
    proxiRaceControlUnit = std::make_unique<RemoteRaceControlUnit>(this,nullptr);
    proxiRaceControlUnit->setLocalUnit(raceControlUnit.get());


}

void ControlUnitController::ConnectToServer()
{
    connect(&socket, SIGNAL(connected()),this,SLOT(SocketConnected()));
    connect(&socket, SIGNAL(disconnected()),this,SLOT(SocketDisconnected()));

    socket.connectToHost(serverAddress,serverPort);

}

void ControlUnitController::RemoteDeviceDisconnected(RemoteDevice *device, QTcpSocket *socket)
{
    disconnectDevice(this->remoteCentralController.get(),raceControlUnit.get());
    this->remoteCentralController.reset();
    this->proxiRaceControlUnit->RemoveConnection(socket);
    disconnect(&this->socket, SIGNAL(connected()),this,SLOT(SocketConnected()));

    this->ConnectToServer();
}

void ControlUnitController::SocketConnected()
{
    this->remoteCentralController = std::make_shared<RemoteCentralController>(this,&socket);
    connectDevice(this->remoteCentralController.get(),this->raceControlUnit.get());
    this->proxiRaceControlUnit->AddConnection(&socket,QIODevice::ReadOnly);

    emit this->raceControlUnit->getTeamList();

    emit connected();
}

void ControlUnitController::SocketDisconnected()
{
    emit disconnected();
}

void ControlUnitController::SocketError(QAbstractSocket::SocketError error)
{

}

void ControlUnitController::qmlConnect(QString address)
{
    this->setServerAddress(QHostAddress(address));
    this->ConnectToServer();
}

void ControlUnitController::qmlDisconnect()
{
    disconnectDevice(this->remoteCentralController.get(),raceControlUnit.get());
    this->remoteCentralController.reset();
    this->proxiRaceControlUnit->RemoveConnection(&socket);
    disconnect(&this->socket, SIGNAL(connected()),this,SLOT(SocketConnected()));
    this->socket.close();
}
