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


void CoreController::connectDevice(ICentralController *controller, IVoteCounter *voteCounter)
{

    connect(voteCounter, SIGNAL(updateVotesForTeam(quint32, quint32)),controller,SLOT(UpdateVotesForTeam(quint32, quint32)));
    connect(controller,SIGNAL(VotesUpdated(quint32, quint32)),voteCounter,SLOT(votesForTeamUpdated(quint32,quint32)));
}

void CoreController::connectDevice(ICentralController *controller, IDisplayManager *device)
{

}

void CoreController::connectDevice(ICentralController *controller, IRaceControlUnit *device)
{

}

void CoreController::connectDevice(ICentralController *controller, ILaserGate *device)
{

}

void CoreController::connectDevice(ICentralController *controller, ISkillRaceGate *device)
{

}

void CoreController::connectDevice(ICentralController *controller, ISkillRaceFieldUnit *device)
{

}

void CoreController::disconnectDevice(ICentralController *controller, IVoteCounter *voteCounter)
{

}

void CoreController::disconnectDevice(ICentralController *controller, IDisplayManager *device)
{

}

void CoreController::disconnectDevice(ICentralController *controller, IRaceControlUnit *device)
{

}

void CoreController::disconnectDevice(ICentralController *controller, ILaserGate *device)
{

}

void CoreController::disconnectDevice(ICentralController *controller, ISkillRaceGate *device)
{

}

void CoreController::disconnectDevice(ICentralController *controller, ISkillRaceFieldUnit *device)
{

}


