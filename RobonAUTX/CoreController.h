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
    ICentralController* centralController;

    QList<IVoteCounter*> voteCounters;
    QList<IDisplayManager*> displayManagers;
    QList<IRaceControlUnit*> raceControlUnits;

    ILaserGate* laserGates;
    ISkillRaceGate* skillRaceGates;
    ISkillRaceFieldUnit* skillRaceFieldUnits;

public: 

    explicit CoreController(QObject *parent = nullptr);

    vector<RemoteDevice> remoteDevices;
    vector<IVoteCounter*> voteControllers;
    
    void initDevices();
    
    void initializeRemoteDeviceSockets();
    
    void InitNetworkInterface();
};

#endif //_CORECONTROLLER_H
