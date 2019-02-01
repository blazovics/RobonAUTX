import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    width: 200
    height: 200
    color: "#fee1e1"
    property alias skillRacePointLabel: skillRacePointLabel
    property alias elapsedTimeLabel: elapsedTimeLabel
    property alias remainingTimeLabel: remainingTimeLabel

    Column {
        id: columnLayout1
        anchors.rightMargin: 5
        anchors.leftMargin: 5
        anchors.bottomMargin: 5
        anchors.topMargin: 5
        anchors.fill: parent

        Label {
            text: qsTr("Elapsed Time:")
        }

        Label {
            id: elapsedTimeLabel
            text: qsTr("00:12:654")
            anchors.right: parent.right
            anchors.rightMargin: 10
            font.pointSize: 28
        }

        Label {
            id: label2
            text: qsTr("Remaining Time:")
        }

        Label {
            id: remainingTimeLabel
            text: qsTr("04:47:346")
            anchors.right: parent.right
            anchors.rightMargin: 10
            font.pointSize: 28
        }

        Label {
            id: label
            text: qsTr("Earned Points:")
        }

        Label {
            id: skillRacePointLabel
            text: qsTr("30")
            anchors.right: parent.right
            anchors.rightMargin: 10
            horizontalAlignment: Text.AlignRight
            font.pointSize: 33
        }
    }
}
