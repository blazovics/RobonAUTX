import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: checkpoints_container
    width: 200
    height: 800
    color: "#99ffffff"

    signal checkpointButtonPressed(int checkpointID, bool state);
    signal startSucceededButtonPressed(bool state);
    signal laneChangeSucceededButtonPressed(bool state);
    signal decreaseActiveCheckpoint();
    signal increaseActiveCheckpoint();
    signal decreaseWrongGateCount();
    signal increaseWrongGateCount();

    function resetContainer(){
        //startSuccededButton.checked = false;
        laneChangeSuccededButton.checked = false;

        for(var i = 0; i< checkpointList.model.rowCount(); i++ )
        {
            checkpointList.model.setProperty(i,"is_checked",false);
        }
    }

    function updateCheckpoint(checkpointID,state)
    {
        console.log(checkpointID)
        console.log(state)

        checkpointList.model.setProperty(checkpointID,"is_checked",state);
    }

    function updateLaneChangeSucceededButton(state)
    {
        laneChangeSuccededButton.checked = state;
    }

    function updateStartSucceededButton(state)
    {
        startSuccededButton.checked = state;
    }

    Component{
        id: ckeckpointButtonDelegate

        CheckpointStateIndicator {
            checked: is_checked
            checkpointID: checkpoint_ID
        }
    }

    ColumnLayout{
        anchors.bottomMargin: 15
        anchors.topMargin: 15
        anchors.leftMargin: 5
        anchors.rightMargin: 5
        spacing: 5
        anchors.fill: parent



        //ListView{


        RowLayout{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Button {
                text: "Prev"
                id: decreaseAchievedCheckpointButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onReleased: {
                    checkpoints_container.decreaseActiveCheckpoint();
                }
            }
            Button {
                text: "Next"
                id: increaseAchievedCheckpointButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onReleased: {
                    checkpoints_container.increaseActiveCheckpoint();
                }
            }
        }

        GridView{
            id:checkpointList
            height: 520
            flow: GridView.FlowTopToBottom
            cellWidth: 100
            cellHeight: 65
            cacheBuffer: 300
            contentHeight: 520
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillHeight: false
            width: 200
            model: CheckpointListModel {}
            delegate: ckeckpointButtonDelegate

        }
/*
        Button {
            text: "Star Succeeded"
            id: startSuccededButton
            checkable: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onReleased: {
                checkpoints_container.startSucceededButtonPressed(checked);
            }
        }*/

        Button {
            text: "Lane Change Succeeded"
            id: laneChangeSuccededButton
            checkable: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onReleased: {
                checkpoints_container.laneChangeSucceededButtonPressed(checked);
            }
        }

        RowLayout{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Button {
                text: "Error -"
                id: decreaseWrongGateButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onReleased: {
                    checkpoints_container.decreaseWrongGateCount();
                }
            }
            Button {
                text: "Error +"
                id: increaseWrongGateButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onReleased: {
                    checkpoints_container.increaseWrongGateCount();
                }
            }
        }

    }

}
