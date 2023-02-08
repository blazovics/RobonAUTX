import QtQuick 2.10
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

Rectangle {

    property alias mouseArea: mouseArea

    property int checkpointState: CheckpointState.State.Clear;

    property bool selected: false


    color: {
        if (selected == false){

            "lightgray"
        } else {
            "#84B026"
        }
    }

    width: 45
    height: 45
    id: setter

    radius: 5

        ColumnLayout{
            anchors.fill: parent
            Label{
                text: {
                    if (setter.checkpointState == CheckpointState.State.Clear){
                        "-"
                    }
                    else if (setter.checkpointState == CheckpointState.State.Checked) {
                       "R"
                    }
                    else if (setter.checkpointState == CheckpointState.State.PirateFirst) {
                        "P"
                    }
                    else if (setter.checkpointState == CheckpointState.State.PirateFirstChecked) {
                        "PR"
                    }
                    else if (setter.checkpointState == CheckpointState.State.PirateSecond || setter.checkpointState == CheckpointState.State.PirateSecondChecked) {
                        "PP"
                    }
                    else {
                        "??"
                    }
                }

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
                        if (setter.checkpointState == CheckpointState.State.Clear){
                            "lightGray"
                        }
                        else if (setter.checkpointState == CheckpointState.State.Checked) {
                            "green"
                        }
                        else if (setter.checkpointState == CheckpointState.State.PirateFirst ||  setter.checkpointState == CheckpointState.State.PirateFirstChecked || setter.checkpointState == CheckpointState.State.PirateSecond || setter.checkpointState == CheckpointState.State.PirateSecondChecked) {
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
                        if (setter.checkpointState == CheckpointState.State.Clear || setter.checkpointState == CheckpointState.State.PirateFirst){
                            "lightGray"
                        }
                        else if (setter.checkpointState == CheckpointState.State.PirateFirstChecked  || setter.checkpointState == CheckpointState.State.Checked ) {
                            "green"
                        }
                        else if (setter.checkpointState == CheckpointState.State.PirateSecond || setter.checkpointState == CheckpointState.State.PirateSecondChecked) {
                            "red"
                        }
                        else {
                            "blue"
                        }
                    }
                }
            }
        }



        MouseArea{
            id: mouseArea
            anchors.fill: parent
        }
}
