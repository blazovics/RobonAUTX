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

class SocketConnection : public QObject {

    Q_OBJECT

private:
    std::unique_ptr<QTcpSocket> activeSocket;
    QByteArray inputBuffer;
    QByteArray outputBuffer;

    quint32 pendingMessageSize;

public: 
    explicit SocketConnection(QTcpSocket* socket, QObject *parent = nullptr);
    ~SocketConnection();
    /**
 * @param event
 */


public slots:
    void sendEvent(Event event);
    void dataReceived();
    /**
 * @param event
 */
signals:
    void eventReceived(Event event);

private:
    void processInputBuffer();
    void extractEventFromBuffer();
};

#endif //_SOCKETCONNECTION_H
