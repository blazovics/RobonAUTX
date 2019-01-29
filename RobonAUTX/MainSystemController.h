#ifndef MAINSYSTEMCONTROLLER_H
#define MAINSYSTEMCONTROLLER_H

#include <QTcpServer>
#include "CoreController.h"

class MainSystemController : public CoreController
{
    QTcpServer laserGateServer;
    QTcpServer skillRaceFieldUnitServer;
    QTcpServer voteCounterServer;
    QTcpServer skillRaceGateServer;
    QTcpServer raceControlUnitServer;
    QTcpServer displayManagerServer;

public:

    MainSystemController();


    void StartServers();

    void StopServers();
};

#endif // MAINSYSTEMCONTROLLER_H
