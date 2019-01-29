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

    void connectDevice(IVoteCounter *device);
    void connectDevice(IDisplayManager *device);
    void connectDevice(IRaceControlUnit *device);
    void connectDevice(ILaserGate *device);
    void connectDevice(ISkillRaceGate *device);
    void connectDevice(ISkillRaceFieldUnit *device);
    
    void initDevices();
    
    void initializeRemoteDeviceSockets();
    
    void InitNetworkInterface();
};





#endif //_CORECONTROLLER_H
