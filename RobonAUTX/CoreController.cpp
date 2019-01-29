/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "CoreController.h"

/**
 * CoreController implementation
 */


CoreController::CoreController(QObject *parent):QObject (parent)
{

}

void CoreController::initDevices() {

}

void CoreController::initializeRemoteDeviceSockets() {

}

void CoreController::InitNetworkInterface() {

}

void CoreController::connectDevice(IVoteCounter *device)
{
    if(centralController.first != nullptr)
    {
        ICentralController* centralControllerDevice = centralController.first;

        connect(device, SIGNAL(updateVotesForTeam(quint32, quint32)),centralControllerDevice,SLOT(UpdateVotesForTeam(quint32, quint32)));

        connect(centralControllerDevice,SIGNAL(VotesUpdated(quint32, quint32)),device,SLOT(votesForTeamUpdated(quint32,quint32)));
    }
}

void CoreController::connectDevice(IDisplayManager *device)
{

}

void CoreController::connectDevice(IRaceControlUnit *device)
{

}

void CoreController::connectDevice(ILaserGate *device)
{

}

void CoreController::connectDevice(ISkillRaceGate *device)
{

}

void CoreController::connectDevice(ISkillRaceFieldUnit *device)
{

}

