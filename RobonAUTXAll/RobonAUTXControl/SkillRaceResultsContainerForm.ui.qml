import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: rectangle
    width: 360
    height: 65
    color: "#99ffffff"
    property alias skillRacePointLabel: skillRacePointLabel
    property alias elapsedTimeLabel: elapsedTimeLabel
    property alias remainingTimeLabel: remainingTimeLabel

    //property alias wrongGateCountLabel: wrongGateCountLabel
    GridLayout {
        id: column
        anchors.fill: parent
        columns: 3

        Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        Layout.fillWidth: true

        anchors.margins: 5

        Label {
            text: qsTr("Elapsed Time:")
        }

        Label {
            id: elapsedTimeLabel
            text: qsTr("00:12:654")
            fontSizeMode: Text.Fit
            horizontalAlignment: Text.AlignRight
            font.pointSize: 15
        }

        Label {
            id: label
            text: qsTr("Earned Points:")
        }

        Label {
            id: label2
            text: qsTr("Remaining Time:")
        }

        Label {
            id: remainingTimeLabel
            text: qsTr("04:47:346")
            horizontalAlignment: Text.AlignRight
            font.pointSize: 15
            fontSizeMode: Text.Fit
        }

        Label {
            id: skillRacePointLabel
            text: qsTr("30")
            horizontalAlignment: Text.AlignRight
            fontSizeMode: Text.Fit
            font.pointSize: 15
        }

        /*
        Label {
            id: label3
            text: qsTr("Wrong Gates:")
        }

        Label {
            id: wrongGateCountLabel
            text: qsTr("1")
            horizontalAlignment: Text.AlignRight
            fontSizeMode: Text.Fit
            font.pointSize: 15
        }
        */
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:2}D{i:2}D{i:3}D{i:4}D{i:5}D{i:6}D{i:7}D{i:1}
}
##^##*/

