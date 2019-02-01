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


void CoreController::connectDevice(ICentralController *controller, IVoteCounter *device)
{

    connect(device, SIGNAL(updateVotesForTeam(quint32, quint32)),controller,SLOT(UpdateVotesForTeam(quint32, quint32)));
    connect(controller,SIGNAL(VotesUpdated(quint32, quint32)),device,SLOT(votesForTeamUpdated(quint32,quint32)));
}

void CoreController::connectDevice(ICentralController *controller, IDisplayManager *device)
{
    //FIXME: Implement
}

void CoreController::connectDevice(ICentralController *controller, IRaceControlUnit *device)
{

    connect(device,SIGNAL(getTeamList()),controller,SLOT(TeamListRequested()));
    connect(device,SIGNAL(InitSkillRace(quint32)),controller,SLOT( InitSkillRace(quint32) ));
    connect(device,SIGNAL(InitSpeedRace(quint32)),controller,SLOT( InitSpeedRace(quint32) ));
    connect(device,SIGNAL(startRace()),controller,SLOT( StartRace() ));
    connect(device,SIGNAL(FinishRace(bool)),controller,SLOT( FinishRace(bool) ));
    connect(device,SIGNAL(manualMeasure()),controller,SLOT( ManualMeasureReceived()));
    connect(device,SIGNAL(SelectTimeSourceForLap(TimeSourceType)),controller,SLOT( TimeSourceForLapSelected(TimeSourceType) ));
    connect(device,SIGNAL(updateCheckpointState(quint32, bool, bool)),controller,SLOT( UpdateCheckpointState(quint32, bool, bool) ));
    connect(device,SIGNAL(VehicleStarted(bool)),controller,SLOT( VechicleStartAchieved(bool) ));
    connect(device,SIGNAL(LaneChanged(bool)),controller,SLOT( LaneChangeAchieved(bool) ));
    connect(device,SIGNAL(SafetyCarFollowed(bool)),controller,SLOT( SafetyCarFollowed(bool) ));
    connect(device,SIGNAL(SafetyCarOvertaken(bool)),controller,SLOT( SafetyCarOvertaken(bool) ));
    connect(device,SIGNAL(ModifyTouchCount(quint32)),controller,SLOT( ModifyTouchCount(quint32) ));
    connect(device,SIGNAL(ShowSpeedResults(bool, quint32)),controller,SLOT( ShowSpeedResults(bool, quint32) ));
    connect(device,SIGNAL(ShowSkillResults(quint32)),controller,SLOT( ShowSkillResults(quint32) ));
    connect(device,SIGNAL(ShowFinalResults(bool, quint32)),controller,SLOT( ShowFinalResults(bool, quint32) ));
    connect(device,SIGNAL(ShowFinalResultAtPosition(bool, quint32)),controller,SLOT( ShowFinalResultAtPosition(bool, quint32) ));
    connect(device,SIGNAL(ShowVotesResults(quint32)),controller,SLOT( ShowVotesResults(quint32) ));
    connect(device,SIGNAL(ShowQualificationResults(quint32)),controller,SLOT( ShowQualificationResults(quint32) ));
    connect(device,SIGNAL(ShowInterRaceScreen()),controller,SLOT( ShowInterRaceScreen() ));
    connect(device,SIGNAL(SkillGateManualStarted()),controller,SLOT(SkillGateStarted()));

    connect(controller,SIGNAL( TeamListUpdated(QList<Team>) ),device, SLOT(TeamListUpdated(QList<Team>)));
    connect(controller,SIGNAL( SkillRaceInitiated(quint32) ),device, SLOT(SkillRaceInitiated(quint32)));
    connect(controller,SIGNAL( SpeedRaceInitiated(quint32) ),device, SLOT(SpeedRaceInitiated(quint32)));
    connect(controller,SIGNAL( RaceStarted() ),device, SLOT(raceStarted()));
    connect(controller,SIGNAL( RaceFinished(bool) ),device, SLOT(RaceFinished(bool)));
    connect(controller,SIGNAL( LaserLapTimeUpdated(quint32) ),device, SLOT(LaserLapTimeUpdated(quint32)));
    connect(controller,SIGNAL( ManualLapTimeUpdated(quint32) ),device, SLOT(ManualLapTimeUpdated(quint32)));
    connect(controller,SIGNAL( SpeedLapCompleted(quint32, quint32) ),device, SLOT(SpeedLapCompleted(quint32, quint32)));
    connect(controller,SIGNAL( CheckpointStateUpdated(quint32, bool) ),device, SLOT(CheckpointStateUpdated(quint32, bool)));
    connect(controller,SIGNAL( VehicleStartConfirmed(bool) ),device, SLOT(VehicleStartConfirmed(bool)));
    connect(controller,SIGNAL( LaneChangeConfirmed(bool) ),device, SLOT(LaneChangeConfirmed(bool)));
    connect(controller,SIGNAL( SkillPointUpdated(quint32) ),device, SLOT(SkillPointUpdated(quint32)));
    connect(controller,SIGNAL( SafetyCarFollowingConfirmed(bool) ),device, SLOT(SafetyCarFollowingConfirmed(bool)));
    connect(controller,SIGNAL( SafetyCarOvertakeConfirmed(bool) ),device, SLOT(SafetyCarOvertakeConfirmed(bool)));
    connect(controller,SIGNAL( TouchCountModified(quint32) ),device, SLOT(TouchCountModified(quint32)));
}

void CoreController::connectDevice(ICentralController *controller, ILaserGate *device)
{
    connect(device,SIGNAL(LaserMeasure(quint32)),controller,SLOT(LaserMeasureReceived(quint32)));
}

void CoreController::connectDevice(ICentralController *controller, ISkillRaceGate *device)
{
    connect(device,SIGNAL(SkillRaceGateStarted()),controller,SLOT(SkillGateStarted()));
    connect(controller,SIGNAL(StartSkillGate()),device,SLOT(StartSkillRaceGate()));
}

void CoreController::connectDevice(ICentralController *controller, ISkillRaceFieldUnit *device)
{
    connect(device,SIGNAL(checkpointUpdated(quint32, bool, bool)),controller,SLOT(UpdateCheckpointState(quint32, bool, bool)));
    connect(controller,SIGNAL(CheckpointStateUpdated(quint32, bool)),device,SLOT(UpdateCheckpointState(quint32, bool)));
}

void CoreController::disconnectDevice(ICentralController *controller, IVoteCounter *device)
{
    disconnect(device, SIGNAL(updateVotesForTeam(quint32, quint32)),controller,SLOT(UpdateVotesForTeam(quint32, quint32)));
    disconnect(controller,SIGNAL(VotesUpdated(quint32, quint32)),device,SLOT(votesForTeamUpdated(quint32,quint32)));
}

void CoreController::disconnectDevice(ICentralController *controller, IDisplayManager *device)
{
//FIXME: Implement
}

void CoreController::disconnectDevice(ICentralController *controller, IRaceControlUnit *device)
{
    disconnect(device,SIGNAL(getTeamList()),controller,SLOT(TeamListRequested()));
    disconnect(device,SIGNAL(InitSkillRace(quint32)),controller,SLOT( InitSkillRace(quint32) ));
    disconnect(device,SIGNAL(InitSpeedRace(quint32)),controller,SLOT( InitSpeedRace(quint32) ));
    disconnect(device,SIGNAL(startRace()),controller,SLOT( StartRace() ));
    disconnect(device,SIGNAL(FinishRace(bool)),controller,SLOT( FinishRace(bool) ));
    disconnect(device,SIGNAL(manualMeasure()),controller,SLOT( ManualMeasureReceived()));
    disconnect(device,SIGNAL(SelectTimeSourceForLap(TimeSourceType)),controller,SLOT( TimeSourceForLapSelected(TimeSourceType) ));
    disconnect(device,SIGNAL(updateCheckpointState(quint32, bool)),controller,SLOT( UpdateCheckpointState() ));
    disconnect(device,SIGNAL(VehicleStarted(bool)),controller,SLOT( VechicleStartAchieved(bool) ));
    disconnect(device,SIGNAL(LaneChanged(bool)),controller,SLOT( LaneChangeAchieved(bool) ));
    disconnect(device,SIGNAL(SafetyCarFollowed(bool)),controller,SLOT( SafetyCarFollowed(bool) ));
    disconnect(device,SIGNAL(SafetyCarOvertaken(bool)),controller,SLOT( SafetyCarOvertaken(bool) ));
    disconnect(device,SIGNAL(ModifyTouchCount(quint32)),controller,SLOT( ModifyTouchCount(quint32) ));
    disconnect(device,SIGNAL(ShowSpeedResults(bool, quint32)),controller,SLOT( ShowSpeedResults(bool, quint32) ));
    disconnect(device,SIGNAL(ShowSkillResults(quint32)),controller,SLOT( ShowSkillResults(quint32) ));
    disconnect(device,SIGNAL(ShowFinalResults(bool, quint32)),controller,SLOT( ShowFinalResults(bool, quint32) ));
    disconnect(device,SIGNAL(ShowFinalResultAtPosition(bool, quint32)),controller,SLOT( ShowFinalResultAtPosition(bool, quint32) ));
    disconnect(device,SIGNAL(ShowVotesResults(quint32)),controller,SLOT( ShowVotesResults(quint32) ));
    disconnect(device,SIGNAL(ShowQualificationResults(quint32)),controller,SLOT( ShowQualificationResults(quint32) ));
    disconnect(device,SIGNAL(ShowInterRaceScreen()),controller,SLOT( ShowInterRaceScreen() ));
    disconnect(device,SIGNAL(SkillGateManualStarted()),controller,SLOT(SkillGateStarted()));

    disconnect(controller,SIGNAL( TeamListUpdated(QList<Team>) ),device, SLOT(TeamListUpdated(QList<Team>)));
    disconnect(controller,SIGNAL( SkillRaceInitiated(quint32) ),device, SLOT(SkillRaceInitiated(quint32)));
    disconnect(controller,SIGNAL( SpeedRaceInitiated(quint32) ),device, SLOT(SpeedRaceInitiated(quint32)));
    disconnect(controller,SIGNAL( RaceStarted() ),device, SLOT(raceStarted()));
    disconnect(controller,SIGNAL( RaceFinished(bool) ),device, SLOT(RaceFinished(bool)));
    disconnect(controller,SIGNAL( LaserLapTimeUpdated(quint32) ),device, SLOT(LaserLapTimeUpdated(quint32)));
    disconnect(controller,SIGNAL( ManualLapTimeUpdated(quint32) ),device, SLOT(ManualLapTimeUpdated(quint32)));
    disconnect(controller,SIGNAL( SpeedLapCompleted(quint32, quint32) ),device, SLOT(SpeedLapCompleted(quint32, quint32)));
    disconnect(controller,SIGNAL( CheckpointStateUpdated(quint32, bool) ),device, SLOT(CheckpointStateUpdated(quint32, bool)));
    disconnect(controller,SIGNAL( VehicleStartConfirmed(bool) ),device, SLOT(VehicleStartConfirmed(bool)));
    disconnect(controller,SIGNAL( LaneChangeConfirmed(bool) ),device, SLOT(LaneChangeConfirmed(bool)));
    disconnect(controller,SIGNAL( SkillPointUpdated(quint32) ),device, SLOT(SkillPointUpdated(quint32)));
    disconnect(controller,SIGNAL( SafetyCarFollowingConfirmed(bool) ),device, SLOT(SafetyCarFollowingConfirmed(bool)));
    disconnect(controller,SIGNAL( SafetyCarOvertakeConfirmed(bool) ),device, SLOT(SafetyCarOvertakeConfirmed(bool)));
    disconnect(controller,SIGNAL( TouchCountModified(quint32) ),device, SLOT(TouchCountModified(quint32)));
}

void CoreController::disconnectDevice(ICentralController *controller, ILaserGate *device)
{
    disconnect(device,SIGNAL(LaserMeasure(quint32)),controller,SLOT(LaserMeasureReceived(quint32)));
}

void CoreController::disconnectDevice(ICentralController *controller, ISkillRaceGate *device)
{
    disconnect(device,SIGNAL(SkillRaceGateStarted()),controller,SLOT(SkillGateStarted()));
    disconnect(controller,SIGNAL(StartSkillGate()),device,SLOT(StartSkillRaceGate()));
}

void CoreController::disconnectDevice(ICentralController *controller, ISkillRaceFieldUnit *device)
{
    disconnect(device,SIGNAL(checkpointUpdated(quint32, bool, bool)),controller,SLOT(UpdateCheckpointState(quint32, bool, bool)));
    disconnect(controller,SIGNAL(CheckpointStateUpdated(quint32, bool)),device,SLOT(UpdateCheckpointState(quint32, bool)));
}


