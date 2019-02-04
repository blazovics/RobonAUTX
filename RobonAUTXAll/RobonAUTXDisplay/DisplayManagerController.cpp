#include "DisplayManagerController.h"

QHostAddress DisplayManagerController::getServerAddress() const
{
    return serverAddress;
}

void DisplayManagerController::setServerAddress(const QHostAddress &value)
{
    serverAddress = value;
}

quint16 DisplayManagerController::getServerPort() const
{
    return serverPort;
}

void DisplayManagerController::setServerPort(const quint16 &value)
{
    serverPort = value;
}

DisplayManager *DisplayManagerController::getDisplayManager() const
{
    return displayManager.get();
}

DisplayManagerController::DisplayManagerController(QHostAddress serverAddress, quint16 serverPort):serverAddress(serverAddress),serverPort(serverPort)
{
    displayManager = std::make_unique<DisplayManager>();
    proxiDisplayManager = std::make_unique<RemoteDisplayManager>(this,nullptr);
    proxiDisplayManager->setLocalManager(displayManager.get());
}

void DisplayManagerController::ConnectToServer()
{
    connect(&socket, SIGNAL(connected()),this,SLOT(SocketConnected()));
    connect(&socket, SIGNAL(disconnected()),this,SLOT(SocketDisconnected()));
    connect(&socket, SIGNAL(SocketError(QAbstractSocket::SocketError)), this, SLOT(SocketError(QAbstractSocket::SocketError)));

    socket.connectToHost(serverAddress,serverPort);

}

void DisplayManagerController::RemoteDeviceDisconnected(RemoteDevice *device, QTcpSocket *socket)
{
    disconnectDevice(this->remoteCentralController.get(),displayManager.get());
    this->remoteCentralController.reset();
    this->proxiDisplayManager->RemoveConnection(socket);
    disconnect(&this->socket, SIGNAL(connected()),this,SLOT(SocketConnected()));
    disconnect(&this->socket, SIGNAL(disconnected()),this,SLOT(SocketDisconnected()));
    disconnect(&this->socket, SIGNAL(SocketError(QAbstractSocket::SocketError)), this, SLOT(SocketError(QAbstractSocket::SocketError)));

}

void DisplayManagerController::SocketConnected()
{
    this->remoteCentralController = std::make_shared<RemoteCentralController>(this,&socket);
    connectDevice(this->remoteCentralController.get(),this->displayManager.get());
    this->proxiDisplayManager->AddConnection(&socket,QIODevice::ReadOnly);

    emit connected();
}

void DisplayManagerController::SocketDisconnected()
{
    this->ConnectToServer();
    emit disconnected();
}

void DisplayManagerController::SocketError(QAbstractSocket::SocketError error)
{
    this->ConnectToServer();
}

void DisplayManagerController::qmlConnect(QString address)
{
    this->setServerAddress(QHostAddress(address));
    this->ConnectToServer();
}

void DisplayManagerController::qmlDisconnect()
{
    disconnectDevice(this->remoteCentralController.get(),displayManager.get());
    this->remoteCentralController.reset();
    this->proxiDisplayManager->RemoveConnection(&socket);
    disconnect(&this->socket, SIGNAL(connected()),this,SLOT(SocketConnected()));
    this->socket.close();
}

