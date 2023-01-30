import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: checkpoints_container
    width: 360
    height: 550
    color: "#99ffffff"

    signal checkpointButtonPressed(int checkpointID, int state);

    signal startSucceededButtonPressed(bool state);
    signal laneChangeSucceededButtonPressed(bool state);

    signal decreaseActiveCheckpoint();
    signal increaseActiveCheckpoint();

    signal decreaseTouchCount();
    signal increaseTouchCount();

    property int selectedCheckpoint: -1

    property var idMap: ({0:checkpoint_0,
                         1:checkpoint_1,
                         2:checkpoint_2,
                         3:checkpoint_3,
                         4:checkpoint_4,
                         5:checkpoint_5,
                         6:checkpoint_6,
                         7:checkpoint_7,
                         8:checkpoint_8,
                         9:checkpoint_9,
                         10:checkpoint_10,
                         11:checkpoint_11,
                         12:checkpoint_12,
                         13:checkpoint_13,
                         14:checkpoint_14,
                         15:checkpoint_15,
                         16:checkpoint_16,})

    function findItemById(id){
        return idMap[id];
    }

    function resetContainer(){
        //startSuccededButton.checked = false;
        laneChangeSuccededButton.checked = false;

        for(var i = 0; i< 17; i++ )
        {
            findItemById(i).checkpointState = CheckpointState.State.Checked;
            //checkpointList.model.setProperty(i,"is_checked",false);
        }
    }

    function updateCheckpoint(checkpointID,state)
    {
        console.log(checkpointID)
        console.log(state)

        //checkpointList.model.setProperty(checkpointID,"is_checked",state);
    }

    function updateLaneChangeSucceededButton(state)
    {
        laneChangeSuccededButton.checked = state;
    }

    function updateStartSucceededButton(state)
    {
        startSuccededButton.checked = state;
    }


    ColumnLayout{
        anchors.margins: 1
        spacing: 1
        anchors.fill: parent
        layoutDirection: Qt.RightToLeft
        Layout.alignment: Qt.AlignTop


        RowLayout{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Button {
                text: "Touch -"
                Layout.fillWidth: true
                id: decreaseWrongGateButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onReleased: {
                    checkpoints_container.decreaseWrongGateCount();
                }
            }
            Button {
                text: "Tocuh +"
                Layout.fillWidth: true
                id: increaseWrongGateButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                onReleased: {
                    checkpoints_container.increaseWrongGateCount();
                }
            }
        }
        Button {
            text: "Lane Change Succeeded"
            Layout.fillWidth: true
            id: laneChangeSuccededButton
            checkable: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            onReleased: {
                checkpoints_container.laneChangeSucceededButtonPressed(checked);
            }
        }
        ColumnLayout{
            Layout.fillWidth: true
            spacing: 10
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 40
                CheckpointStateIndicator{
                    id: checkpoint_0
                    title: "A"
                    checkpointID: 0
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_0.checkpointID
                    }


                }
                CheckpointStateIndicator{
                    id: checkpoint_1
                    title: "B"
                    checkpointID: 1
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_1.checkpointID
                    }

                }
            }
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 20
                CheckpointStateIndicator{
                    id: checkpoint_2
                    title: "C"
                    checkpointID: 2
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_2.checkpointID
                    }

                }
                CheckpointStateIndicator{
                    id: checkpoint_3
                    title: "D"
                    checkpointID: 3
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_3.checkpointID
                    }
                }
                CheckpointStateIndicator{
                    id: checkpoint_4
                    title: "E"
                    checkpointID: 4
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_4.checkpointID
                        resetContainer();
                    }
                }
            }
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 40
                CheckpointStateIndicator{
                    id: checkpoint_5
                    title: "F"
                    checkpointID: 5
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_5.checkpointID
                    }
                }
                CheckpointStateIndicator{
                    id: checkpoint_6
                    title: "G"
                    checkpointID: 6
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_6.checkpointID
                    }
                }
            }
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 20
                CheckpointStateIndicator{
                    id: checkpoint_7
                    title: "H"
                    checkpointID: 7
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_7.checkpointID
                    }
                }
                CheckpointStateIndicator{
                    id: checkpoint_8
                    title: "I"
                    checkpointID: 8
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_8.checkpointID
                    }
                }
                CheckpointStateIndicator{
                    id: checkpoint_9
                    title: "J"
                    checkpointID: 9
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_9.checkpointID
                    }
                }
            }
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 40
                CheckpointStateIndicator{
                    id: checkpoint_10
                    title: "K"
                    checkpointID: 10
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_10.checkpointID
                    }
                }
                CheckpointStateIndicator{
                    id: checkpoint_11
                    title: "L"
                    checkpointID: 11
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_11.checkpointID
                    }
                }
            }
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 20
                CheckpointStateIndicator{
                    id: checkpoint_12
                    title: "M"
                    checkpointID: 12
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_12.checkpointID
                    }
                }
                CheckpointStateIndicator{
                    id: checkpoint_13
                    title: "N"
                    checkpointID: 13
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_13.checkpointID
                    }
                }
                CheckpointStateIndicator{
                    id: checkpoint_14
                    title: "O"
                    checkpointID: 14
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_14.checkpointID
                    }
                }
            }
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 40
                CheckpointStateIndicator{
                    id: checkpoint_15
                    title: "P"
                    checkpointID: 15
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_15.checkpointID
                    }
                }
                CheckpointStateIndicator{
                    id: checkpoint_16
                    title: "Q"
                    checkpointID: 16
                    selectedCheckpointID: selectedCheckpoint
                    mouseArea.onClicked: {
                        selectedCheckpoint = checkpoint_16.checkpointID
                    }
                }
            }
        } 

    }
}


