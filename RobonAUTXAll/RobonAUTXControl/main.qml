import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Window {
    id: window
    visible: true
    //Designed for Samsung Galaxy S20
    width: 360
    height: 800
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
            view.currentIndex = 1
        }
        onShowSkillRaceView:
        {
            view.currentIndex = 2
            skillRaceControlPage.resetPage();
        }
        onShowSpeedRaceView:
        {
            view.currentIndex = 3
            speedRaceControlPage.resetPage();
        }
    }

    SwipeView {
        id: view
        anchors.topMargin: 1
        currentIndex: 1
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: rectangle.bottom

        ResultsControlPage{
            id: resultsControlPage
        }
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

    }

    Connections{
        target: controller
        onConnected:{
            connectButton.enabled = false;
            disconnectButton.enabled = true;
            connectionStateLabel.text = qsTr("Online");
        }
        onDisconnected:{
            connectButton.enabled = true;
            disconnectButton.enabled = false;
            connectionStateLabel.text = qsTr("Offline");
        }
    }

    Rectangle {
        id: rectangle
        height: 65
        color: "#99ffffff"
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0


        Rectangle {
            id: button
            anchors.top: row.bottom
            anchors.topMargin: 5
            width: 50
            height: 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5

            radius: 10

            color: "darkGrey"

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    rectangle.anchors.topMargin == 0 ? rectangle.anchors.topMargin = -50 : rectangle.anchors.topMargin = 0;
                }
            }

            Label{
                anchors.fill: parent
                text: qsTr("Configuration")
                font.pointSize: 7
            }
        }


        RowLayout {
            id: row
           //height: 53
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0

            TextField {
                id: ipTextField
                //width: 98
                //height: 40
                text: qsTr("192.168.5.100")
                placeholderText: "Server IP"
            }

            Label {
                id: connectionStateLabel
                text: qsTr("Offline")
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






