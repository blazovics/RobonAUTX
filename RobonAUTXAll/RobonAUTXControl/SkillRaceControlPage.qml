import QtQuick 2.4

SkillRaceControlPageForm {

    function resetPage(){
        checkpoints_container.resetContainer();
        race_time_container.resetContainer();
        raceResultsContainer.resetContainer();
        actions_container.resetContainer();
    }

    checkpoints_container.onCheckpointButtonPressed: {
        console.log(checkpointID);
        console.log(state);
        controlUnit.qmlUpdateCheckpointState(checkpointID,state,true);
    }
    checkpoints_container.onStartSucceededButtonPressed: {
        controlUnit.qmlVehicleStarted(state);
    }
    checkpoints_container.onLaneChangeSucceededButtonPressed: {
        controlUnit.qmlLaneChanged(state);
    }

    checkpoints_container.onDecreaseActiveCheckpoint: {
        controlUnit.qmlDecreaseCheckpoint();
    }

    checkpoints_container.onIncreaseActiveCheckpoint: {
        controlUnit.qmlIncreaseCheckpoint();
    }

    checkpoints_container.onDecreaseWrongGateCount: {
        controlUnit.qmlDecreaseWrongGateCount();
    }

    checkpoints_container.onIncreaseWrongGateCount: {
        controlUnit.qmlIncreaseWrongGateCount();
    }

    Connections{
        target: controlUnit
        onUpdateCheckpointButtons:{
            checkpoints_container.updateCheckpoint(checkpointID,checked);
        }
        onUpdateStartSuccessButton:{
            checkpoints_container.updateStartSucceededButton(status);
        }
        onUpdateLaneChangeConfirmedButton:{
            checkpoints_container.updateLaneChangeSucceededButton(status);
        }
    }
}
