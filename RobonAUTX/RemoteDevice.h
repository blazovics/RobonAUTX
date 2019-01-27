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

class RemoteDevice{


private:
    ConnectionState state;
    
    void updateConnectionStatus();

public:
    virtual ~RemoteDevice();

    virtual void EventReceived(Event event) =0;

protected:
    void sendHeartBeat();



};

#endif //_REMOTEDEVICE_H
