import QtQuick 2.4

SkillRaceControlPageForm {

    function resetPage(){
        checkpoints_container.resetContainer();
        race_time_container.resetContainerForSkill();
        raceResultsContainer.resetContainer();
        actions_container.resetContainer();
    }

    checkpoints_container.onCheckpointButtonPressed: {
        console.log(checkpointID);
        console.log(state);
        var i = 1;
        i = state;
        controlUnit.qmlUpdateCheckpointState(checkpointID,i,true);
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

    checkpoints_container.onDecreaseTouchCount: {
        controlUnit.qmlDecreaseTouchCount();
    }

    checkpoints_container.onIncreaseTouchCount: {
        controlUnit.qmlIncreaseTouchCount();
    }

    Connections{
        target: controlUnit
        onUpdateCheckpointButtons:{
            console.log(checkpointID)
            console.log(newState)
            console.log("?")
            checkpoints_container.updateCheckpoint(checkpointID,newState);
        }
        onUpdateStartSuccessButton:{
            checkpoints_container.updateStartSucceededButton(status);
        }
        onUpdateLaneChangeConfirmedButton:{
            checkpoints_container.updateLaneChangeSucceededButton(status);
        }
    }
}
