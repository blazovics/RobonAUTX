#ifndef ISOCKETCONNECTIONDELEGATE_H
#define ISOCKETCONNECTIONDELEGATE_H

#include "Event.h"
#include <QTcpSocket>

class ISocketConnectionDelegate{

public:

    virtual void EventReceived(Event& event) =0;
    virtual void SocketError(QTcpSocket* socket) = 0;
    virtual void SocketDisconnected(QTcpSocket* socket) = 0;

};

#endif // ISOCKETCONNECTIONDELEGATE_H
