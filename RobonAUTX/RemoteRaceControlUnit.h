/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTERACECONTROLUNIT_H
#define REMOTERACECONTROLUNIT_H

#include "IRaceControlUnit.h"
#include "RemoteDevice.h"


class RemoteRaceControlUnit: public IRaceControlUnit, public RemoteDevice {
};

#endif //_REMOTERACECONTROLUNIT_H