#include "ControlUnitController.h"
#include "Configuration.h"

#include <QHostAddress>

ControlUnitController::ControlUnitController()
{
    raceControlUnit = std::make_unique<RaceControlUnit>();
    proxiRaceControlUnit = std::make_unique<RemoteRaceControlUnit>(this,nullptr);
    proxiRaceControlUnit->setLocalUnit(raceControlUnit.get());


}

void ControlUnitController::ConnectToServer()
{
    connect(&socket, SIGNAL(connected()),this,SLOT(SocketConnected()));

    Configuration& instance = Configuration::GetInstance();

    QHostAddress serverAddress;

    if(instance.IsKeyAvailable("MainSystemSettings","ListenAddress"))
    {
        QString serverAddressString = QString::fromStdString(instance.GetStringValue("MainSystemSettings","ListenAddress"));
        serverAddress.setAddress(serverAddressString);

        if(instance.IsKeyAvailable("MainSystemSettings","RaceControlUnitPort"))
        {
            quint16 port =  quint16(instance.GetLongValue("MainSystemSettings","RaceControlUnitPort"));
            socket.connectToHost(serverAddress,port);
        }
        else {
            socket.connectToHost(serverAddress,35000);
        }
    }
    else {
        throw std::runtime_error("No valid server address");
    }
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
}

void ControlUnitController::SocketDisconnected()
{

}

void ControlUnitController::SocketError(QAbstractSocket::SocketError error)
{

}
