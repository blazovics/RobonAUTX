import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Rectangle{
    id: rectangle

    width: 1024
    height: 60
    color: "#00000000"

    property alias positionLabel: positionLabel
    property alias teamNameLabel: teamNameLabel
    property alias value2Label: value2Label
    property alias value1Label: value1Label

    FontLoader {
        id: digital7;
        source: "qrc:/resources/digital-7.ttf"
    }

    FontLoader {
        id: roboto;
        source: "qrc:/resources/Roboto.ttf"
    }

    Rectangle {
        id: rectangle1
        width: 125
        color: "#80000000"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: rectangle4.left
        anchors.rightMargin: 10
        anchors.top: rectangle3.top
        anchors.topMargin: 0

        Label {
            id: value1Label
            color: "#ffffff"
            text: qsTr("Label")
            anchors.rightMargin: 3
            anchors.leftMargin: 3
            anchors.bottomMargin: 3
            anchors.topMargin: 3
            anchors.fill: parent
            font.pointSize: 35
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: roboto.name
            fontSizeMode: Text.Fit
        }
    }

    Rectangle {
        id: rectangle4
        width: 125
        color: "#80000000"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: rectangle3.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 20

        Label {
            id: value2Label
            color: "#ffffff"
            text: qsTr("Label")
            anchors.rightMargin: 3
            anchors.leftMargin: 3
            anchors.bottomMargin: 3
            anchors.topMargin: 3
            anchors.fill: parent
            font.pointSize: 35
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: roboto.name
            fontSizeMode: Text.Fit
        }
    }

    Rectangle {
        id: rectangle2
        color: "#80000000"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: rectangle1.left
        anchors.rightMargin: 10
        anchors.left: rectangle3.right
        anchors.leftMargin: 10
        anchors.top: rectangle3.top
        anchors.topMargin: 0

        Label {
            id: teamNameLabel
            color: "#ffffff"
            text: qsTr("Unemployed and Single")
            anchors.rightMargin: 3
            anchors.leftMargin: 3
            anchors.bottomMargin: 3
            anchors.topMargin: 3
            anchors.fill: parent
            font.pointSize: 35
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: roboto.name
            fontSizeMode: Text.Fit
        }
    }

    Rectangle {
        id: rectangle3
        width: 60
        color: "#80000000"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 20

        Label {
            id: positionLabel
            color: "#ffffff"
            text: qsTr("#")
            anchors.rightMargin: 3
            anchors.leftMargin: 3
            anchors.bottomMargin: 3
            anchors.topMargin: 3
            anchors.fill: parent
            font.pointSize: 35
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: roboto.name
            fontSizeMode: Text.Fit
        }
    }
}
