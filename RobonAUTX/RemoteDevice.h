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

class RemoteDevice: public QObject {

    Q_OBJECT

private:
    QTimer heartbeatTimer;
    ConnectionState state;
    
    void updateConnectionStatus();

public:
    RemoteDevice(QObject *parent=nullptr);

protected:
    void sendHeartBeat();

public slots:
    /**
    * @param event
    */
    virtual void EventReceived(Event event) =0;

};

#endif //_REMOTEDEVICE_H
