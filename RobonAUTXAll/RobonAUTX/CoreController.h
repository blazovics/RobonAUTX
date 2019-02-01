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


public: 

    explicit CoreController(QObject *parent = nullptr);

    virtual void RemoteDeviceDisconnected(RemoteDevice* device, QTcpSocket* socket) = 0;

    static void connectDevice(ICentralController* controller, IVoteCounter *voteCounter);
    static void connectDevice(ICentralController* controller, IDisplayManager *device);
    static void connectDevice(ICentralController* controller, IRaceControlUnit *device);
    static void connectDevice(ICentralController* controller, ILaserGate *device);
    static void connectDevice(ICentralController* controller, ISkillRaceGate *device);
    static void connectDevice(ICentralController* controller, ISkillRaceFieldUnit *device);

    static void disconnectDevice(ICentralController* controller, IVoteCounter *voteCounter);
    static void disconnectDevice(ICentralController* controller, IDisplayManager *device);
    static void disconnectDevice(ICentralController* controller, IRaceControlUnit *device);
    static void disconnectDevice(ICentralController* controller, ILaserGate *device);
    static void disconnectDevice(ICentralController* controller, ISkillRaceGate *device);
    static void disconnectDevice(ICentralController* controller, ISkillRaceFieldUnit *device);
    
};





#endif //_CORECONTROLLER_H
