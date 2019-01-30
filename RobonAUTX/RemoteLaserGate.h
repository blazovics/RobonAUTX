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

public:
    explicit RemoteLaserGate(CoreController* parentController, QTcpSocket *socket);
    void EventReceived(Event& event);
};

#endif //_REMOTELASERGATE_H
