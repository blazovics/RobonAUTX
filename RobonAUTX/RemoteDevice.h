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
    QList<std::shared_ptr<SocketConnection>> socketConnections;

    void sendHeartBeat();
    void sendEvent(Event& event);

public:
    RemoteDevice(CoreController* parentController);

    virtual ~RemoteDevice();

    void EventReceived(const Event& event);
    void SocketError();
    void SocketDisconnected();

    void AddConnection(QTcpSocket *socket);
    void RemoveConnection(QTcpSocket *socket);

};

#endif //_REMOTEDEVICE_H
