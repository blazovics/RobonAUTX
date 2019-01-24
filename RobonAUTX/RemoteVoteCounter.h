/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTEVOTECOUNTER_H
#define REMOTEVOTECOUNTER_H

#include "IVoteCounter.h"
#include "RemoteDevice.h"


class RemoteVoteCounter: public IVoteCounter, public RemoteDevice {
};

#endif //_REMOTEVOTECOUNTER_H