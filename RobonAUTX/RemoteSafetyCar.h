/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTESAFETYCAR_H
#define REMOTESAFETYCAR_H

#include "ISafetyCar.h"
#include "RemoteDevice.h"


class RemoteSafetyCar: public ISafetyCar, public RemoteDevice {
};

#endif //_REMOTESAFETYCAR_H