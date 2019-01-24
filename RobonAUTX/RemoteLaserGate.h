/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTELASERGATE_H
#define REMOTELASERGATE_H

#include "ILaserGate.h"
#include "RemoteDevice.h"


class RemoteLaserGate: public ILaserGate, public RemoteDevice {
};

#endif //_REMOTELASERGATE_H