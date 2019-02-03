import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

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
        }
        onShowSpeedRaceView:
        {
            //FIXME: do it!
        }

    }

    SwipeView {
        id: view
        currentIndex: 0
        anchors.bottom: rectangle.top
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
        Page {
            title: qsTr("Discover")
        }
        Page {
            title: qsTr("Activity")
        }

    }

    Rectangle {
        id: rectangle
        y: 880
        height: 144
        color: "#99ffffff"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        Behavior on anchors.bottomMargin {

            NumberAnimation {
                //This specifies how long the animation takes
                duration: 1000
                //This selects an easing curve to interpolate with, the default is Easing.Linear
                easing.type: Easing.InCurve
            }
        }

        Button {
            id: button
            x: 334
            y: 8
            text: qsTr("Configuration")
            display: AbstractButton.TextOnly

            onClicked: {
                rectangle.anchors.bottomMargin == 0 ? rectangle.anchors.bottomMargin = -100 : rectangle.anchors.bottomMargin = 0;
            }
        }


        Row {
            id: row
            width: 471
            height: 53

            TextField {
                id: textField
                width: 98
                height: 40
                text: qsTr("192.168.0.150")
                placeholderText: "Server IP"
            }

            ToolSeparator {
                id: toolSeparator
            }

            TextField {
                id: textField1
                width: 78
                height: 40
                text: qsTr("Text Field")
            }

            Button {
                id: button1
                text: qsTr("Button")
            }

        }
    }
}



/*##^## Designer {
    D{i:6;anchors_height:144;anchors_width:768;anchors_x:0;anchors_y:880}
}
 ##^##*/
