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
    explicit RemoteDevice(CoreController* parentController, QTcpSocket *socket, QIODevice::OpenMode mode);

    virtual ~RemoteDevice();

    virtual void EventReceived(Event& event) = 0;
    void SocketError(QTcpSocket* socket);
    void SocketDisconnected(QTcpSocket* socket);

    void AddConnection(QTcpSocket *socket, QIODevice::OpenMode mode);
    void RemoveConnection(QTcpSocket *socket);

};

#endif //_REMOTEDEVICE_H
