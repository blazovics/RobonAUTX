/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef CORECONTROLLER_H
#define CORECONTROLLER_H

#include <QObject>
#include <vector>
#include "RemoteDevice.h"
#include "IVoteCounter.h"
#include "ICentralController.h"
#include "IDisplayManager.h"
#include "ISkillRaceFieldUnit.h"
#include "IRaceControlUnit.h"
#include "ILaserGate.h"
#include "ISkillRaceGate.h"

using namespace std;

class CoreController: public QObject {

    Q_OBJECT

protected:
    QPair<ICentralController*,QTcpSocket*> centralController;

    QList<QPair<IVoteCounter*,QTcpSocket*>> voteCounters;
    QList<QPair<IDisplayManager*,QTcpSocket*>> displayManagers;
    QList<QPair<IRaceControlUnit*,QTcpSocket*>> raceControlUnits;

    QPair<ILaserGate*,QTcpSocket*> laserGate;
    QPair<ISkillRaceGate*,QTcpSocket*> skillRaceGates;
    QPair<ISkillRaceFieldUnit*,QTcpSocket*> skillRaceFieldUnits;

public: 

    explicit CoreController(QObject *parent = nullptr);

    template<class Device>
    void connectDevice(Device *device);
    
    void initDevices();
    
    void initializeRemoteDeviceSockets();
    
    void InitNetworkInterface();
};

template<class Device>
void CoreController::connectDevice(Device *device)
{

}

template<>
void CoreController::connectDevice(IVoteCounter *device)
{
    if(centralController.first != nullptr)
    {
        ICentralController* centralControllerDevice = centralController.first;

        connect(device, SIGNAL(updateVotesForTeam(quint32, quint32)),centralControllerDevice,SLOT(UpdateVotesForTeam(quint32, quint32)));

        connect(centralControllerDevice,SIGNAL(VotesUpdated(quint32, quint32)),device,SLOT(votesForTeamUpdated(quint32,quint32)));
    }
}

template<>
void CoreController::connectDevice(IDisplayManager *device)
{

}

template<>
void CoreController::connectDevice(IRaceControlUnit *device)
{

}

template<>
void CoreController::connectDevice(ILaserGate *device)
{

}

template<>
void CoreController::connectDevice(ISkillRaceGate *device)
{

}

template<>
void CoreController::connectDevice(ISkillRaceFieldUnit *device)
{

}




#endif //_CORECONTROLLER_H
