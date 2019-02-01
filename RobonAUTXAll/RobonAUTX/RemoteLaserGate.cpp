/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RemoteLaserGate.h"

/**
 * RemoteLaserGate implementation
 */

RemoteLaserGate::RemoteLaserGate(CoreController* parentController, QTcpSocket *socket, QIODevice::OpenMode mode):RemoteDevice (parentController,socket,mode)
{

}

void RemoteLaserGate::EventReceived(Event &event)
{
    if(event.getEventID() == Event_LaserTimeReceived)
    {
        emit LaserMeasure(event.extractQuint32FromRawData());
    }
}
