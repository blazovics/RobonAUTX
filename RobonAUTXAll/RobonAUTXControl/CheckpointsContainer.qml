import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: checkpoints_container
    width: 123
    height: 680
    color: "#c4d2d7"

    //signal checkpointButtonPressed(int checkpointID, Boolean State);

    /*
    function updateCheckpoint(checkpointID,state)
    {
        for(var i = 0; i < root.children.length; ++i)
            if(root.children[i].type==="image"){
                 //balabala
            }
    }*/

    ColumnLayout {
        id: checkpointsLayout
        clip: true
        anchors.topMargin: 5
        anchors.bottomMargin: 5
        anchors.fill: parent

        DelayButton {
            id: btn_checkpoint_start_succeeded
            text: qsTr("Start Success")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        CheckpointButton {
            id: btn_checkpoint_0
            checked: true
            checkpointID: 1
            onPressed: {
                checkpointButtonPressed(checkpointID,checked);
            }
        }

        DelayButton {
            id: btn_checkpoint_1
            text: qsTr("Checkpoint 2")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        DelayButton {
            id: btn_checkpoint_2
            text: qsTr("Checkpoint 3")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        DelayButton {
            id: btn_checkpoint_3
            text: qsTr("Checkpoint 4")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        DelayButton {
            id: btn_checkpoint_4
            text: qsTr("Checkpoint 5")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        DelayButton {
            id: btn_checkpoint_5
            text: qsTr("Checkpoint 6")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        DelayButton {
            id: btn_checkpoint_6
            text: qsTr("Checkpoint 7")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        DelayButton {
            id: btn_checkpoint_7
            text: qsTr("Checkpoint 8")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        DelayButton {
            id: btn_checkpoint_8
            text: qsTr("Checkpoint 9")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        DelayButton {
            id: btn_checkpoint_9
            text: qsTr("Checkpoint 10")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        DelayButton {
            id: btn_checkpoint_10
            text: qsTr("Checkpoint 11")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        DelayButton {
            id: btn_checkpoint_11
            text: qsTr("Checkpoint 12")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }


        DelayButton {
            id: btn_checkpoint_lane_change_succeeded
            text: qsTr("Lane Change Success")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }
}
