/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTECENTRALCONTROLLER_H
#define REMOTECENTRALCONTROLLER_H

#include "ICentralController.h"
#include "RemoteDevice.h"


class RemoteCentralController: public ICentralController, public RemoteDevice {

public:
    virtual ~RemoteCentralController();

};

#endif //_REMOTECENTRALCONTROLLER_H
