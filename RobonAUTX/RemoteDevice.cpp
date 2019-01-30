/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RemoteDevice.h"
#include "QDebug"

/**
 * RemoteDevice implementation
 */


RemoteDevice::RemoteDevice(CoreController *parentController)
{
    parentController = this->parentController;


    if(parentController == nullptr)
    {
        //TODO: EasyLogging
        qDebug()<<"parent controller is not set!";
    }
}

RemoteDevice::~RemoteDevice()
{

}

void RemoteDevice::EventReceived(const Event &event)
{

}

void RemoteDevice::SocketError(QTcpSocket *socket)
{

}

void RemoteDevice::SocketDisconnected(QTcpSocket *socket)
{

}

void RemoteDevice::AddConnection(QTcpSocket *socket)
{
    socketConnections.append(std::shared_ptr<SocketConnection>(new SocketConnection(socket, this)));
}

void RemoteDevice::RemoveConnection(QTcpSocket *socket)
{
    int index = -1;

    for (int i=0; socketConnections.size(); i++) {
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

void RemoteDevice::sendHeartBeat() {

}
