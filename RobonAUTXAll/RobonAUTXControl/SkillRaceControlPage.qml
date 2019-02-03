import QtQuick 2.4

SkillRaceControlPageForm {
    checkpoints_container.onCheckpointButtonPressed: {
        console.log(checkpointID);
        console.log(state);
        controlUnit.qmlUpdateCheckpointState(checkpointID,state,true);
    }

    Connections{
        target: controlUnit
        onUpdateCheckpointButtons:{
            checkpoints_container.updateCheckpoint(checkpointID,state);
        }
    }
}
