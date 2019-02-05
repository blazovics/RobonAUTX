import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Window {
    id: window
    visible: true
    width: 768
    height: 1024
    title: qsTr("Hello World")

    property int selectedTeamID: -1

    Image {
        id: main_background
        source: "images/controllerBackground.png"
        anchors.fill: parent
    }

    Connections{
        target: controlUnit
        onShowMainView:
        {
            view.currentIndex = 0
        }
        onShowSkillRaceView:
        {
            //FIXME: handle TeamID
            view.currentIndex = 1
            skillRaceControlPage.resetPage();
        }
        onShowSpeedRaceView:
        {
            //FIXME: do it!
            view.currentIndex = 2
            speedRaceControlPage.resetPage();
        }

    }

    SwipeView {
        id: view
        anchors.topMargin: 150
        currentIndex: 0
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top

        MainControlPage {
            id: mainControlPage
            onTeamSelected: {
                selectedTeamID = teamID
            }
        }
        SkillRaceControlPage {
            id: skillRaceControlPage
        }
        SpeedRaceControlPage {
            id: speedRaceControlPage
        }
        Page {
            title: qsTr("Activity")
        }

    }

    Connections{
        target: controller
        onConnected:{
            connectButton.enabled = false;
            disconnectButton.enabled = true;
            connectionStateLabel.text = qsTr("Connected");
        }
        onDisconnected:{
            connectButton.enabled = true;
            disconnectButton.enabled = false;
            connectionStateLabel.text = qsTr("Disconnected");
        }
    }

    Rectangle {
        id: rectangle
        height: 144
        color: "#99ffffff"
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0


        Button {
            id: button
            x: 334
            y: 8
            text: qsTr("Configuration")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            display: AbstractButton.TextOnly

            onClicked: {
                rectangle.anchors.topMargin == 0 ? rectangle.anchors.topMargin = -100 : rectangle.anchors.topMargin = 0;
            }
        }


        RowLayout {
            id: row
            height: 53
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0

            TextField {
                id: ipTextField
                width: 98
                height: 40
                text: qsTr("192.168.0.150")
                placeholderText: "Server IP"
            }

            Label {
                id: connectionStateLabel
                text: qsTr("Disconnected")
            }

            Button {
                id: connectButton
                enabled: true
                text: qsTr("Connect")
                onPressed: {
                    controller.qmlConnect(ipTextField.text)
                }
            }

            Button {
                id: disconnectButton
                enabled: false
                text: qsTr("Disconnect")
                onPressed: {
                    controller.qmlDisconnect();
                }
            }


        }
    }
}





/*##^## Designer {
    D{i:6;anchors_height:144;anchors_width:768;anchors_x:0;anchors_y:880}
}
 ##^##*/
