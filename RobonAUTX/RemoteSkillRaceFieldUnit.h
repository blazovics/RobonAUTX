/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTESKILLRACEFIELDUNIT_H
#define REMOTESKILLRACEFIELDUNIT_H

#include "ISkillRaceFieldUnit.h"
#include "RemoteDevice.h"


class RemoteSkillRaceFieldUnit: public ISkillRaceFieldUnit, public RemoteDevice {
};

#endif //_REMOTESKILLRACEFIELDUNIT_H