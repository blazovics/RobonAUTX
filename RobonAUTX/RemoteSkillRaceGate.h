#ifndef REMOTESKILLRACEGATE_H
#define REMOTESKILLRACEGATE_H

#include "ISkillRaceGate.h"
#include "RemoteDevice.h"

class RemoteSkillRaceGate: public ISkillRaceGate, public RemoteDevice
{
public:
    RemoteSkillRaceGate();
};

#endif // REMOTESKILLRACEGATE_H
