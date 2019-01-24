/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTEDISPLAYMANAGER_H
#define REMOTEDISPLAYMANAGER_H

#include "IDisplayManager.h"
#include "RemoteDevice.h"


class RemoteDisplayManager: public IDisplayManager, public RemoteDevice {
};

#endif //_REMOTEDISPLAYMANAGER_H