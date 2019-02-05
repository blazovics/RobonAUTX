import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Rectangle{
    id: rectangle

    width: 1024
    height: 60
    color: "#00000000"

    property alias valueLabel: valueLabel
    property alias teamNameLabel: teamNameLabel
    property alias positionLabel: positionLabel


    Rectangle {
        id: rectangle1
        width: 260
        color: "#80000000"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: rectangle3.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 20

        Label {
            id: valueLabel
            color: "#ffffff"
            text: qsTr("Label")
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
            fontSizeMode: Text.Fit
            anchors.fill: parent
            font.pointSize: 35
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: roboto.name
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
            anchors.fill: parent
            font.pointSize: 35
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: roboto.name
            fontSizeMode: Text.Fit
        }
    }
}
