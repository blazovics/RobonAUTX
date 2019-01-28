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


void RemoteDevice::updateConnectionStatus() {

}

RemoteDevice::RemoteDevice(CoreController *parentController, QTcpSocket* socket):socketConnection(socket)
{
    parentController = this->parentController;
    this->socketConnection.setSocketDelegate(this);

    if(parentController == nullptr)
    {
        //TODO: EasyLogging
        qDebug()<<"parent controller is not set!";
    }
}

RemoteDevice::~RemoteDevice()
{

}

void RemoteDevice::sendHeartBeat() {

}
