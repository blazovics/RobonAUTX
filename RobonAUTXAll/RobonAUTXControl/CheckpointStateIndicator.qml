import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

Rectangle {

    property alias mouseArea: mouseArea

    property int checkpointState: CheckpointState.State.Clear;

    property int checkpointID: 0

    property int selectedCheckpointID: -1

    property string title: "A"

    width: 60
    height: 45
    id: indicator

    radius: 5

    ColumnLayout{
        anchors.fill: parent
        Label{
            text: qsTr(title)
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }


        RowLayout{

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: true
            Rectangle{
                border.color: "black"
                border.width: 1
                radius: width*0.5
                width: 12
                height: width
                color: {
                    if (indicator.checkpointState == CheckpointState.State.Clear){
                        "lightGray"
                    }
                    else if (indicator.checkpointState == CheckpointState.State.Checked) {
                        "green"
                    }
                    else if (indicator.checkpointState == CheckpointState.State.PirateFirst ||  indicator.checkpointState == CheckpointState.State.PirateFirstChecked || indicator.checkpointState == CheckpointState.State.PirateSecond || indicator.checkpointState == CheckpointState.State.PirateSecondChecked) {
                        "red"
                    }
                    else {
                        "blue"
                    }
                }
            }
            Rectangle{
                border.color: "black"
                border.width: 1
                radius: width*0.5
                width: 12
                height: width
                color: {
                    if (indicator.checkpointState == CheckpointState.State.Clear || indicator.checkpointState == CheckpointState.State.PirateFirst){
                        "lightGray"
                    }
                    else if (indicator.checkpointState == CheckpointState.State.Checked || indicator.checkpointState == CheckpointState.State.PirateFirstChecked) {
                        "green"
                    }
                    else if (indicator.checkpointState == CheckpointState.State.PirateSecond || indicator.checkpointState == CheckpointState.State.PirateSecondChecked) {
                        "red"
                    }
                    else {
                        "blue"
                    }
                }
            }/*
            Rectangle{
                border.color: "black"
                border.width: 1
                radius: width*0.5
                width: 12
                height: width

                color: {
                    if (indicator.checkpointState == CheckpointState.State.Clear || indicator.checkpointState == CheckpointState.State.Checked || indicator.checkpointState == CheckpointState.State.PirateFirst || indicator.checkpointState == CheckpointState.State.PirateFirstChecked || indicator.checkpointState == CheckpointState.State.PirateSecond){
                        "lightGray"
                    }
                    else if (indicator.checkpointState == CheckpointState.State.PirateSecondChecked) {
                        "green"
                    }
                    else {
                        "blue"
                    }
                }
            }*/
        }
    }




    color: {
        if (selectedCheckpointID == checkpointID){
            "#84B026"
        }
        else{
            "lightgray"
        }
    }

    MouseArea{
        id: mouseArea
        anchors.fill: parent
/*
        onClicked: {
            selectedCheckpointID = checkpointID;
        }
        */

    }

}
