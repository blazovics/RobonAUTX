/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTELASERGATE_H
#define REMOTELASERGATE_H

#include "ILaserGate.h"
#include "RemoteDevice.h"

class RemoteLaserGate: public ILaserGate, public RemoteDevice {

    Q_OBJECT

public:
    explicit RemoteLaserGate(CoreController* parentController, QTcpSocket *socket, QIODevice::OpenMode mode = QIODevice::WriteOnly);
    void EventReceived(Event& event);
};

#endif //_REMOTELASERGATE_H
