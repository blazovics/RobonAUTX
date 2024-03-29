#ifndef REMOTESKILLRACEGATE_H
#define REMOTESKILLRACEGATE_H

#include "ISkillRaceGate.h"
#include "RemoteDevice.h"

class RemoteSkillRaceGate: public ISkillRaceGate, public RemoteDevice
{
    Q_OBJECT

public:
    explicit RemoteSkillRaceGate(CoreController* parentController, QTcpSocket *socket, QIODevice::OpenMode mode = QIODevice::WriteOnly);

    void EventReceived(Event& event);

public slots:

    void StartSkillRaceGate();

};

#endif // REMOTESKILLRACEGATE_H
