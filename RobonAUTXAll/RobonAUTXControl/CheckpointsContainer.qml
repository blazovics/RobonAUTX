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
        anchors.bottomMargin: 5
        anchors.topMargin: 5
        anchors.leftMargin: 5
        anchors.rightMargin: 5
        spacing: 10
        anchors.fill: parent
        layoutDirection: Qt.RightToLeft


        RowLayout{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Button {
                text: "Prev"
                Layout.fillHeight: false
                Layout.fillWidth: true
                id: decreaseAchievedCheckpointButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onReleased: {
                    checkpoints_container.decreaseActiveCheckpoint();
                }
            }
            Button {
                text: "Next"
                Layout.fillWidth: true
                id: increaseAchievedCheckpointButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onReleased: {
                    checkpoints_container.increaseActiveCheckpoint();
                }
            }
        }
        ColumnLayout{


            Layout.fillWidth: true
            spacing: 10
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 40
                CheckpointStateIndicator{
                    id: checkpoint_0
                    title: "A"
                    mouseArea.onClicked: {
                        console.log("click test")
                    }
                }
                CheckpointStateIndicator{
                    id: checkpoint_1
                    title: "B"
                }
            }
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 20
                CheckpointStateIndicator{
                    id: checkpoint_2
                    title: "C"
                }
                CheckpointStateIndicator{
                    id: checkpoint_3
                    title: "D"
                }
                CheckpointStateIndicator{
                    id: checkpoint_4
                    title: "E"
                }
            }
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 40
                CheckpointStateIndicator{
                    id: checkpoint_5
                    title: "F"
                }
                CheckpointStateIndicator{
                    id: checkpoint_6
                    title: "G"
                }
            }
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 20
                CheckpointStateIndicator{
                    id: checkpoint_7
                    title: "H"
                }
                CheckpointStateIndicator{
                    id: checkpoint_8
                    title: "I"
                }
                CheckpointStateIndicator{
                    id: checkpoint_9
                    title: "J"
                }
            }
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 40
                CheckpointStateIndicator{
                    id: checkpoint_10
                    title: "K"
                }
                CheckpointStateIndicator{
                    id: checkpoint_11
                    title: "L"
                }
            }
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 20
                CheckpointStateIndicator{
                    id: checkpoint_12
                    title: "M"
                }
                CheckpointStateIndicator{
                    id: checkpoint_13
                    title: "N"
                }
                CheckpointStateIndicator{
                    id: checkpoint_14
                    title: "O"
                }
            }
            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 40
                CheckpointStateIndicator{
                    id: checkpoint_15
                    title: "P"
                }
                CheckpointStateIndicator{
                    id: checkpoint_16
                    title: "Q"
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

        RowLayout{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Button {
                text: "Error -"
                Layout.fillWidth: true
                id: decreaseWrongGateButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onReleased: {
                    checkpoints_container.decreaseWrongGateCount();
                }
            }
            Button {
                text: "Error +"
                Layout.fillWidth: true
                id: increaseWrongGateButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                onReleased: {
                    checkpoints_container.increaseWrongGateCount();
                }
            }
        }
    }





}


