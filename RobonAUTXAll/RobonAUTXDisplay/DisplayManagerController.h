#ifndef DISPLAYMANAGERCONTROLLER_H
#define DISPLAYMANAGERCONTROLLER_H

#include "CoreController.h"
#include "RemoteCentralController.h"
#include "DisplayManager.h"
#include "RemoteDisplayManager.h"

#include <QHostAddress>

class DisplayManagerController : public CoreController
{
    Q_OBJECT

    std::unique_ptr<DisplayManager> displayManager;
    std::unique_ptr<RemoteDisplayManager> proxiDisplayManager;

    std::shared_ptr<RemoteCentralController> remoteCentralController;

    QTcpSocket socket;

    QHostAddress serverAddress;
    quint16 serverPort;

public:
    explicit DisplayManagerController(QHostAddress serverAddress, quint16 serverPort = 35005);

    void ConnectToServer();
    void DisconnectFromServer();

    void RemoteDeviceDisconnected(RemoteDevice* device, QTcpSocket* socket);


    QHostAddress getServerAddress() const;
    void setServerAddress(const QHostAddress &value);

    quint16 getServerPort() const;
    void setServerPort(const quint16 &value);

    DisplayManager* getDisplayManager() const;

public slots:
    void SocketConnected();
    void SocketDisconnected();
    void SocketError(QAbstractSocket::SocketError error);

    void qmlConnect(QString address);
    void qmlDisconnect();

signals:
    void connected();
    void disconnected();
};

#endif // DISPLAYMANAGERCONTROLLER_H
