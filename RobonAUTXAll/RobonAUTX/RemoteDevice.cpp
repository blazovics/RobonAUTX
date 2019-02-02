/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RemoteDevice.h"
#include <QDebug>
#include "CoreController.h"

/**
 * RemoteDevice implementation
 */


RemoteDevice::RemoteDevice(CoreController *parentController, QTcpSocket *socket, QIODevice::OpenMode mode):parentController(parentController)
{

    if(parentController == nullptr)
    {
        //TODO: EasyLogging
        qDebug()<<"parent controller is not set!";
    }

    if(socket != nullptr)
    {
        this->AddConnection(socket,mode);
    }
}

RemoteDevice::~RemoteDevice()
{

}

void RemoteDevice::SocketError(QTcpSocket *socket)
{
    parentController->RemoteDeviceDisconnected(this,socket);
}

void RemoteDevice::SocketDisconnected(QTcpSocket *socket)
{
    parentController->RemoteDeviceDisconnected(this,socket);
}

void RemoteDevice::AddConnection(QTcpSocket *socket, QIODevice::OpenMode mode)
{
    socketConnections.append(std::shared_ptr<SocketConnection>(new SocketConnection(socket, this,mode)));
}

void RemoteDevice::RemoveConnection(QTcpSocket *socket)
{
    int index = -1;

    for (int i=0; i < socketConnections.size(); i++) {
        if(socketConnections[i]->GetActiveSocket() == socket)
        {
            index = i;
        }
    }
    if(index > -1)
    {
        socketConnections.removeAt(index);
    }

}

void RemoteDevice::sendEvent(Event &event)
{
    for(int i = 0; i < socketConnections.size(); i++)
    {
        socketConnections[i]->SendEvent(event);
    }
}
