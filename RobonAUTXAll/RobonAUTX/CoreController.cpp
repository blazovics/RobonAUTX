/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "CoreController.h"
#include "SkillRace.h"

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
    connect(controller,SIGNAL(  showSpeedResults(QList<SpeedRaceResult>, bool, quint32)), device, SLOT(showSpeedResults(QList<SpeedRaceResult>, bool, quint32)));
    connect(controller,SIGNAL( showSkillResults(QList<SkillRaceResult>, quint32)), device, SLOT(showSkillResults(QList<SkillRaceResult>, quint32)));
    connect(controller,SIGNAL( showFinalResults(QList<FinalResult>, bool, quint32)), device, SLOT(showFinalResults(QList<FinalResult>, bool, quint32)));
    connect(controller,SIGNAL( showFinalResultAtPosition(QList<FinalResult>, bool, quint32)), device, SLOT(showFinalResultAtPosition(QList<FinalResult>, bool, quint32)));
    connect(controller,SIGNAL( showVotesResults(QList<VoteResult>, quint32)), device, SLOT(showVotesResults(QList<VoteResult>, quint32)));
    connect(controller,SIGNAL( showQualificationResults(QList<QualificationResult>, quint32)), device, SLOT(showQualificationResults(QList<QualificationResult>, quint32)));
    connect(controller,SIGNAL( showInterRaceScreen()), device, SLOT(showInterRaceScreen()));
    connect(controller,SIGNAL( SkillRaceInitiated(quint32)), device, SLOT(SkillRaceInitiated(quint32)));
    connect(controller,SIGNAL( SpeedRaceInitiated(quint32)), device, SLOT(SpeedRaceInitiated(quint32)));

    connect(controller,SIGNAL( LaneChangeConfirmed(bool, quint64)), device, SLOT(LaneChangeAchieved(bool, quint64)));
    connect(controller,SIGNAL( VehicleStartConfirmed(bool)), device, SLOT(VehicleStartAchieved(bool)));
    connect(controller,SIGNAL(  SafetyCarFollowingConfirmed(bool)), device, SLOT(SafetyCarFollowed(bool)));
    connect(controller,SIGNAL( SafetyCarOvertakeConfirmed(quint32)), device, SLOT(SafetyCarOvertaken(quint32)));
    connect(controller,SIGNAL( CheckpointStateUpdated(quint32, CheckpointState)), device, SLOT(CheckpointStateUpdated(quint32, CheckpointState)));


    connect(controller,SIGNAL( SpeedLapCompleted(quint32, quint32)), device, SLOT(SpeedLapCompleted(quint32, quint32)));
    connect(controller,SIGNAL( SkillPointUpdated(quint32, quint32)), device, SLOT(SkillPointUpdated(quint32, quint32)));
    connect(controller,SIGNAL( TeamListUpdated(QList<Team>) ), device, SLOT(TeamListUpdated(QList<Team>)));

    connect(controller,SIGNAL( RaceStarted()), device, SLOT(RaceStarted()));
    connect(controller,SIGNAL( RaceFinished(bool)), device, SLOT(RaceFinished(bool)));

    connect(controller,SIGNAL( updateInRaceSpeedResults(QList<SpeedRaceResult>)), device, SLOT(updateInRaceSpeedResults(QList<SpeedRaceResult>)));

    connect(controller,SIGNAL( RaceTimerPaused()), device, SLOT(SkillRacePaused()));
    connect(controller,SIGNAL( RaceTimerResumed()), device, SLOT(SkillRaceResumed()));
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
    connect(device,SIGNAL(updateCheckpointState(quint32, CheckpointState, bool)),controller,SLOT( UpdateCheckpointState(quint32, CheckpointState, bool) ));
    connect(device,SIGNAL(RevertCheckpointState(quint32)),controller,SLOT(RevertCheckpointState(quint32)));
    //connect(device,SIGNAL(UpdateTargetCheckpoint(quint32)),controller,SLOT( UpdateTargetCheckpoint(quint32) ));
    connect(device,SIGNAL(VehicleStarted(bool)),controller,SLOT( VechicleStartAchieved(bool) ));
    connect(device,SIGNAL(LaneChanged(bool)),controller,SLOT( LaneChangeAchieved(bool) ));
    connect(device,SIGNAL(SafetyCarFollowed(bool)),controller,SLOT( SafetyCarFollowed(bool) ));
    connect(device,SIGNAL(SafetyCarOvertaken(quint32)),controller,SLOT( SafetyCarOvertaken(quint32) ));
    connect(device,SIGNAL(ModifyTouchCount(quint32)),controller,SLOT( ModifyTouchCount(quint32) ));
    connect(device,SIGNAL(ShowSpeedResults(bool, quint32)),controller,SLOT( ShowSpeedResults(bool, quint32) ));
    connect(device,SIGNAL(ShowSkillResults(quint32)),controller,SLOT( ShowSkillResults(quint32) ));
    connect(device,SIGNAL(ShowFinalResults(bool, quint32)),controller,SLOT( ShowFinalResults(bool, quint32) ));
    connect(device,SIGNAL(ShowFinalResultAtPosition(bool, quint32)),controller,SLOT( ShowFinalResultAtPosition(bool, quint32) ));
    connect(device,SIGNAL(ShowVotesResults(quint32)),controller,SLOT( ShowVotesResults(quint32) ));
    connect(device,SIGNAL(ShowQualificationResults(quint32)),controller,SLOT( ShowQualificationResults(quint32) ));
    connect(device,SIGNAL(ShowInterRaceScreen()),controller,SLOT( ShowInterRaceScreen() ));
    connect(device,SIGNAL(SkillGateManualStarted()),controller,SLOT(SkillGateStarted()));
    connect(device,SIGNAL(PauseRaceTimer()),controller,SLOT(PauseRaceTimer()));
    connect(device,SIGNAL(ResumeRaceTimer()),controller,SLOT(ResumeRaceTimer()));
    connect(device,SIGNAL(UpdateBSS(quint32)),controller,SLOT(UpdateBSS(quint32)));
    //connect(device,SIGNAL(ModifyWrongGateCount(quint32)),controller,SLOT( ModifyWrongGateCount(quint32) ));

    connect(controller,SIGNAL( TeamListUpdated(QList<Team>) ),device, SLOT(TeamListUpdated(QList<Team>)));
    connect(controller,SIGNAL( SkillRaceInitiated(quint32) ),device, SLOT(SkillRaceInitiated(quint32)));
    connect(controller,SIGNAL( SpeedRaceInitiated(quint32) ),device, SLOT(SpeedRaceInitiated(quint32)));
    connect(controller,SIGNAL( RaceStarted() ),device, SLOT(raceStarted()));
    connect(controller,SIGNAL( RaceFinished(bool) ),device, SLOT(RaceFinished(bool)));
    connect(controller,SIGNAL( LaserLapTimeUpdated(quint32) ),device, SLOT(LaserLapTimeUpdated(quint32)));
    connect(controller,SIGNAL( ManualLapTimeUpdated(quint32) ),device, SLOT(ManualLapTimeUpdated(quint32)));
    connect(controller,SIGNAL( SpeedLapCompleted(quint32,quint32) ),device, SLOT(SpeedLapCompleted(quint32,quint32)));
    connect(controller,SIGNAL( CheckpointStateUpdated(quint32,CheckpointState) ),device, SLOT(CheckpointStateUpdated(quint32,CheckpointState)));
    //connect(controller,SIGNAL( TargetCheckpointUpdated (quint32)), device, SLOT(TargetCheckpointUpdated(quint32)));
    connect(controller,SIGNAL( VehicleStartConfirmed(bool) ),device, SLOT(VehicleStartConfirmed(bool)));
    connect(controller,SIGNAL( LaneChangeConfirmed(bool,quint64) ),device, SLOT(LaneChangeConfirmed(bool, quint64)));
    connect(controller,SIGNAL( SkillPointUpdated(quint32,quint32) ),device, SLOT(SkillPointUpdated(quint32,quint32)));
    connect(controller,SIGNAL( SafetyCarFollowingConfirmed(bool) ),device, SLOT(SafetyCarFollowingConfirmed(bool)));
    connect(controller,SIGNAL( SafetyCarOvertakeConfirmed(quint32) ),device, SLOT(SafetyCarOvertakeConfirmed(quint32)));
    connect(controller,SIGNAL( TouchCountModified(quint32) ),device, SLOT(TouchCountModified(quint32)));
    connect(controller,SIGNAL( RaceTimerPaused() ),device, SLOT(RaceTimerPaused()));
    connect(controller,SIGNAL( RaceTimerResumed() ),device, SLOT(RaceTimerResumed()));
    //connect(controller,SIGNAL( WrongGateCountModified(quint32) ),device, SLOT(WrongGateCountModified(quint32)));

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

    connect(device,SIGNAL(SkillRaceGateStarted()),controller,SLOT(SkillGateStarted()));

    connect(device,SIGNAL(PiratePassed(quint32)),controller,SLOT(PiratePassedGate(quint32)));
    connect(device,SIGNAL(PlayerPassed(quint32)),controller,SLOT(PlayerPassedGate(quint32)));

    connect(controller,SIGNAL(CheckpointStateUpdated(quint32,CheckpointState)),device,SLOT(UpdateCheckpoint(quint32,CheckpointState)));
    connect(controller,SIGNAL( StartSafetyCar()),device, SLOT(StartSafetyCar()));
    connect(controller,SIGNAL( StopSafetyCar()),device, SLOT(StopSafetyCar()));
    connect(controller,SIGNAL( ClearSkillGates()),device, SLOT(SendClearAllGates()));
    connect(controller,SIGNAL( ResetSkillGates()),device, SLOT(ResetCheckpoints()));
    connect(controller,SIGNAL(StartSkillGate()),device,SLOT(StartSkillRaceGate()));
    connect(controller,SIGNAL(SkillRaceTimeIsUp()),device,SLOT(TimeIsUp()));

    connect(controller,SIGNAL( RaceTimerPaused() ),device, SLOT(FreezeOn()));
    connect(controller,SIGNAL( RaceTimerResumed() ),device, SLOT(FreezeOff()));

    //connect(controller,SIGNAL(SkillRaceLastCheckpointReached()),device,SLOT(SetExitGate()));
}

void CoreController::disconnectDevice(ICentralController *controller, IVoteCounter *device)
{
    disconnect(device, SIGNAL(updateVotesForTeam(quint32, quint32)),controller,SLOT(UpdateVotesForTeam(quint32, quint32)));
    disconnect(controller,SIGNAL(VotesUpdated(quint32, quint32)),device,SLOT(votesForTeamUpdated(quint32,quint32)));
}

void CoreController::disconnectDevice(ICentralController *controller, IDisplayManager *device)
{
    disconnect(controller,SIGNAL(  showSpeedResults(QList<SpeedRaceResult>, bool, quint32)), device, SLOT(showSpeedResults(QList<SpeedRaceResult>, bool, quint32)));
    disconnect(controller,SIGNAL( showSkillResults(QList<SkillRaceResult>, quint32)), device, SLOT(showSkillResults(QList<SkillRaceResult>, quint32)));
    disconnect(controller,SIGNAL( showFinalResults(QList<FinalResult>, bool, quint32)), device, SLOT(showFinalResults(QList<FinalResult>, bool, quint32)));
    disconnect(controller,SIGNAL( showFinalResultAtPosition(QList<FinalResult>, bool, quint32)), device, SLOT(showFinalResultAtPosition(QList<FinalResult>, bool, quint32)));
    disconnect(controller,SIGNAL( showVotesResults(QList<VoteResult>, quint32)), device, SLOT(showVotesResults(QList<VoteResult>, quint32)));
    disconnect(controller,SIGNAL( showQualificationResults(QList<QualificationResult>, quint32)), device, SLOT(showQualificationResults(QList<QualificationResult>, quint32)));
    disconnect(controller,SIGNAL( showInterRaceScreen()), device, SLOT(showInterRaceScreen()));
    disconnect(controller,SIGNAL( SkillRaceInitiated(quint32)), device, SLOT(SkillRaceInitiated(quint32)));
    disconnect(controller,SIGNAL( SpeedRaceInitiated(quint32)), device, SLOT(SpeedRaceInitiated(quint32)));

    disconnect(controller,SIGNAL( LaneChangeConfirmed(bool, quint64)), device, SLOT(LaneChangeAchieved(bool, quint64)));
    disconnect(controller,SIGNAL( VehicleStartConfirmed(bool)), device, SLOT(VehicleStartAchieved(bool)));
    disconnect(controller,SIGNAL(  SafetyCarFollowingConfirmed(bool)), device, SLOT(SafetyCarFollowed(bool)));
    disconnect(controller,SIGNAL( SafetyCarOvertakeConfirmed(quint32)), device, SLOT(SafetyCarOvertaken(quint32)));
    disconnect(controller,SIGNAL( CheckpointStateUpdated(quint32, CheckpointState)), device, SLOT(CheckpointStateUpdated(quint32, CheckpointState)));

    disconnect(controller,SIGNAL( SpeedLapCompleted(quint32, quint32)), device, SLOT(SpeedLapCompleted(quint32, quint32)));
    disconnect(controller,SIGNAL( SkillPointUpdated(quint32, quint32)), device, SLOT(SkillPointUpdated(quint32, quint32)));
    disconnect(controller,SIGNAL( TeamListUpdated(QList<Team>) ), device, SLOT(TeamListUpdated(QList<Team>)));

    disconnect(controller,SIGNAL( RaceStarted()), device, SLOT(RaceStarted()));
    disconnect(controller,SIGNAL( RaceFinished(bool)), device, SLOT(RaceFinished(bool)));

    disconnect(controller,SIGNAL( updateInRaceSpeedResults(QList<SpeedRaceResult>)), device, SLOT(updateInRaceSpeedResults(QList<SpeedRaceResult>)));

    disconnect(controller,SIGNAL( RaceTimerPaused()), device, SLOT(SkillRacePaused()));
    disconnect(controller,SIGNAL( RaceTimerResumed()), device, SLOT(SkillRaceResumed()));
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
    disconnect(device,SIGNAL(updateCheckpointState(quint32, CheckpointState, bool)),controller,SLOT( UpdateCheckpointState(quint32, CheckpointState, bool) ));
    disconnect(device,SIGNAL(RevertCheckpointState(quint32)),controller,SLOT(RevertCheckpointState(quint32)));
    //disconnect(device,SIGNAL(UpdateTargetCheckpoint(quint32)),controller,SLOT( UpdateTargetCheckpoint(quint32) ));
    disconnect(device,SIGNAL(VehicleStarted(bool)),controller,SLOT( VechicleStartAchieved(bool) ));
    disconnect(device,SIGNAL(LaneChanged(bool)),controller,SLOT( LaneChangeAchieved(bool) ));
    disconnect(device,SIGNAL(SafetyCarFollowed(bool)),controller,SLOT( SafetyCarFollowed(bool) ));
    disconnect(device,SIGNAL(SafetyCarOvertaken(quint32)),controller,SLOT( SafetyCarOvertaken(quint32) ));
    disconnect(device,SIGNAL(ModifyTouchCount(quint32)),controller,SLOT( ModifyTouchCount(quint32) ));
    disconnect(device,SIGNAL(ShowSpeedResults(bool, quint32)),controller,SLOT( ShowSpeedResults(bool, quint32) ));
    disconnect(device,SIGNAL(ShowSkillResults(quint32)),controller,SLOT( ShowSkillResults(quint32) ));
    disconnect(device,SIGNAL(ShowFinalResults(bool, quint32)),controller,SLOT( ShowFinalResults(bool, quint32) ));
    disconnect(device,SIGNAL(ShowFinalResultAtPosition(bool, quint32)),controller,SLOT( ShowFinalResultAtPosition(bool, quint32) ));
    disconnect(device,SIGNAL(ShowVotesResults(quint32)),controller,SLOT( ShowVotesResults(quint32) ));
    disconnect(device,SIGNAL(ShowQualificationResults(quint32)),controller,SLOT( ShowQualificationResults(quint32) ));
    disconnect(device,SIGNAL(ShowInterRaceScreen()),controller,SLOT( ShowInterRaceScreen() ));
    disconnect(device,SIGNAL(SkillGateManualStarted()),controller,SLOT(SkillGateStarted()));
    disconnect(device,SIGNAL(PauseRaceTimer()),controller,SLOT(PauseRaceTimer()));
    disconnect(device,SIGNAL(ResumeRaceTimer()),controller,SLOT(ResumeRaceTimer()));
    disconnect(device,SIGNAL(UpdateBSS(quint32)),controller,SLOT(UpdateBSS(quint32)));

    disconnect(controller,SIGNAL( TeamListUpdated(QList<Team>) ),device, SLOT(TeamListUpdated(QList<Team>)));
    disconnect(controller,SIGNAL( SkillRaceInitiated(quint32) ),device, SLOT(SkillRaceInitiated(quint32)));
    disconnect(controller,SIGNAL( SpeedRaceInitiated(quint32) ),device, SLOT(SpeedRaceInitiated(quint32)));
    disconnect(controller,SIGNAL( RaceStarted() ),device, SLOT(raceStarted()));
    disconnect(controller,SIGNAL( RaceFinished(bool) ),device, SLOT(RaceFinished(bool)));
    disconnect(controller,SIGNAL( LaserLapTimeUpdated(quint32) ),device, SLOT(LaserLapTimeUpdated(quint32)));
    disconnect(controller,SIGNAL( ManualLapTimeUpdated(quint32) ),device, SLOT(ManualLapTimeUpdated(quint32)));
    disconnect(controller,SIGNAL( SpeedLapCompleted(quint32, quint32) ),device, SLOT(SpeedLapCompleted(quint32, quint32)));
    disconnect(controller,SIGNAL( CheckpointStateUpdated(quint32, CheckpointState) ),device, SLOT(CheckpointStateUpdated(quint32, CheckpointState)));
    //disconnect(controller,SIGNAL( TargetCheckpointUpdated (quint32)), device, SLOT(TargetCheckpointUpdated(quint32)));
    disconnect(controller,SIGNAL( VehicleStartConfirmed(bool) ),device, SLOT(VehicleStartConfirmed(bool)));
    disconnect(controller,SIGNAL( LaneChangeConfirmed(bool, quint64) ),device, SLOT(LaneChangeConfirmed(bool, quint64)));
    disconnect(controller,SIGNAL( SkillPointUpdated(quint32, quint32) ),device, SLOT(SkillPointUpdated(quint32, quint32)));
    disconnect(controller,SIGNAL( SafetyCarFollowingConfirmed(bool) ),device, SLOT(SafetyCarFollowingConfirmed(bool)));
    disconnect(controller,SIGNAL( SafetyCarOvertakeConfirmed(quint32) ),device, SLOT(SafetyCarOvertakeConfirmed(quint32)));
    disconnect(controller,SIGNAL( TouchCountModified(quint32) ),device, SLOT(TouchCountModified(quint32)));
    disconnect(controller,SIGNAL( RaceTimerPaused() ),device, SLOT(RaceTimerPaused()));
    disconnect(controller,SIGNAL( RaceTimerResumed() ),device, SLOT(RaceTimerResumed()));
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
    //disconnect(device,SIGNAL(TargetCheckpointUpdated(quint32)),controller,SLOT(UpdateTargetCheckpoint(quint32)));
    disconnect(device,SIGNAL(SkillRaceGateStarted()),controller,SLOT(SkillGateStarted()));
    //disconnect(device,SIGNAL(WrongGatePassed()),controller,SLOT(WrongGatePassed()));

    disconnect(device,SIGNAL(PiratePassed(quint32)),controller,SLOT(PiratePassedGate(quint32)));
    disconnect(device,SIGNAL(PlayerPassed(quint32)),controller,SLOT(PlayerPassedGate(quint32)));

    disconnect(controller,SIGNAL(CheckpointStateUpdated(quint32,CheckpointState)),device,SLOT(UpdateCheckpoint(quint32,CheckpointState)));
    disconnect(controller,SIGNAL(TargetCheckpointUpdated(quint32)),device,SLOT(UpdateTargetCheckpoint(quint32)));
    disconnect(controller,SIGNAL( StartSafetyCar()),device, SLOT(StartSafetyCar()));
    disconnect(controller,SIGNAL( StopSafetyCar()),device, SLOT(StopSafetyCar()));
    disconnect(controller,SIGNAL( ClearSkillGates()),device, SLOT(SendClearAllGates()));
    disconnect(controller,SIGNAL( ResetSkillGates()),device, SLOT(ResetCheckpoints())); 
    disconnect(controller,SIGNAL(StartSkillGate()),device,SLOT(StartSkillRaceGate()));
    disconnect(controller,SIGNAL(SkillRaceTimeIsUp()),device,SLOT(TimeIsUp()));

    connect(controller,SIGNAL( RaceTimerPaused() ),device, SLOT(FreezeOn()));
    connect(controller,SIGNAL( RaceTimerResumed() ),device, SLOT(FreezeOff()));
    //disconnect(controller,SIGNAL(SkillRaceLastCheckpointReached()),device,SLOT(SetExitGate()));
}


