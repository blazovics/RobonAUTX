/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SOCKETCONNECTION_H
#define SOCKETCONNECTION_H

#include "Event.h"
#include <QTcpSocket>
#include <QObject>
#include <memory>
#include "ISocketConnectionDelegate.h"

class SocketConnection : public QObject {

    Q_OBJECT

private:
    QTcpSocket* activeSocket;
    QByteArray inputBuffer;
    QByteArray outputBuffer;

    quint32 pendingMessageSize;

    ISocketConnectionDelegate* socketDelegate;

public: 
    explicit SocketConnection(QTcpSocket* socket, ISocketConnectionDelegate* delegate, QIODevice::OpenMode mode,  QObject *parent = nullptr);
    ~SocketConnection();
    /**
 * @param event
 */


    ISocketConnectionDelegate *getSocketDelegate() const;
    void setSocketDelegate(ISocketConnectionDelegate *value);

    QTcpSocket *GetActiveSocket() const;

public slots:
    void SendEvent(const Event& event);
    void DataReceived();

    void SocketDisconnected();
    void SocketErrorOccured(QAbstractSocket::SocketError socketError);

private:
    void processInputBuffer();
    void extractEventFromBuffer();
};

#endif //_SOCKETCONNECTION_H
