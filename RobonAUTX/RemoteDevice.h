/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTEDEVICE_H
#define REMOTEDEVICE_H

#include <QObject>
#include <QTimer>
#include "ConnectionState.h"
#include "Event.h"
#include "SocketConnection.h"
#include <QTcpSocket>
#include "ISocketConnectionDelegate.h"

class CoreController;

class RemoteDevice: public ISocketConnectionDelegate{

protected:

    CoreController* parentController;
    SocketConnection socketConnection;

    ConnectionState state;
    
    void updateConnectionStatus();

public:
    RemoteDevice(CoreController* parentController, QTcpSocket *socket);

    virtual ~RemoteDevice();

protected:

    void sendHeartBeat();
    void sendEvent(Event& event);



};

#endif //_REMOTEDEVICE_H
