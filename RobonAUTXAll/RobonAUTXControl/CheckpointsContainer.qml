import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: checkpoints_container
    width: 360
    height: 490
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
        startSuccededButton.checked = false;
        laneChangeSuccededButton.checked = false;

        for(var i = 0; i< 17; i++ )
        {
            findItemById(i).checkpointState = CheckpointState.State.Clear;
            //checkpointList.model.setProperty(i,"is_checked",false);
        }
    }

    function updateCheckpoint(checkpointID,state)
    {
        console.log(checkpointID)
        console.log(state)

        findItemById(checkpointID).checkpointState = state;
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
        //anchors.fill: parent
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        layoutDirection: Qt.RightToLeft
        Layout.alignment: Qt.AlignTop
        id: containers

        RowLayout{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Button {
                text: "Touch -"
                Layout.fillWidth: true
                id: decreaseWrongGateButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onReleased: {
                    checkpoints_container.decreaseTouchCount();
                }
            }
            Button {
                text: "Touch +"
                Layout.fillWidth: true
                id: increaseWrongGateButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                onReleased: {
                    checkpoints_container.increaseTouchCount();
                }
            }
        }
        RowLayout{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Button {
                text: "Start Succeeded"
                Layout.fillWidth: true
                id: startSuccededButton
                checkable: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                onReleased: {
                    checkpoints_container.startSucceededButtonPressed(checked);
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
        }
    }
        ColumnLayout{
            //Layout.fillWidth: true
            anchors.top: containers.bottom
            anchors.left: parent.left
            anchors.bottom: parent.bottom

            id: checkpoint_buttons



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
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    selectedCheckpoint = -1;
                }
                z: -1
            }

        }
        Rectangle{
            id: control_buttons
            anchors.top: containers.bottom
            anchors.left: checkpoint_buttons.right
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            //anchors.rightMargin: selectedCheckpoint > -1 ? 0 : (width * -1) + 10
            visible: selectedCheckpoint > -1 ? true : false


            states: [
                     // This adds a second state to the container where the rectangle is farther to the right

                     State { name: "other"

                         PropertyChanges {
                             target: control_buttons
                             anchors.rightMargin: (width * -1) + 10
                         }
                     }
                 ]

                transitions: Transition {
                    PropertyAnimation { properties: "anchors.rightMargin"; easing.type: Easing.InOutQuad }
                }

            color: "transparent"
        ColumnLayout{
            anchors.fill: parent
            anchors.horizontalCenter: parent.horizontalCenter



            id: setter_buttons

            //Layout.alignment: Qt.AlignTop
            spacing: 10

            CheckpointSetterButton{
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                checkpointState: CheckpointState.State.Clear
                selected: findItemById(selectedCheckpoint).checkpointState == CheckpointState.State.Clear
                mouseArea.onClicked: {
                    checkpoints_container.checkpointButtonPressed(selectedCheckpoint,checkpointState);
                }
            }
            CheckpointSetterButton{
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                checkpointState: CheckpointState.State.Checked
                selected: findItemById(selectedCheckpoint).checkpointState == CheckpointState.State.Checked
                mouseArea.onClicked: {
                    checkpoints_container.checkpointButtonPressed(selectedCheckpoint,checkpointState);
                }
            }
            CheckpointSetterButton{
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                checkpointState: CheckpointState.State.PirateFirst
                selected: findItemById(selectedCheckpoint).checkpointState == CheckpointState.State.PirateFirst
                mouseArea.onClicked: {
                    checkpoints_container.checkpointButtonPressed(selectedCheckpoint,checkpointState);
                }
            }
            CheckpointSetterButton{
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                checkpointState: CheckpointState.State.PirateFirstChecked
                selected: findItemById(selectedCheckpoint).checkpointState == CheckpointState.State.PirateFirstChecked
                mouseArea.onClicked: {
                    checkpoints_container.checkpointButtonPressed(selectedCheckpoint,checkpointState);
                }
            }
            CheckpointSetterButton{
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                checkpointState: CheckpointState.State.PirateSecond
                selected: findItemById(selectedCheckpoint).checkpointState == CheckpointState.State.PirateSecond
                mouseArea.onClicked: {
                    checkpoints_container.checkpointButtonPressed(selectedCheckpoint,checkpointState);
                }
            }
        }
        Rectangle{
            width: 20
            height: 20
            anchors.top: parent.top
            anchors.right: parent.right
            color: "red"
            anchors.margins: 10
            radius: 3

            Label{
                text: "X"
                color: "white"
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    selectedCheckpoint = -1;
                }
            }

        }
        }
}



