import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: race_time_container
    width: 360
    height: 45
    color: "#99ffffff"
    property alias manualTimerToggle: manualTimerToggle
    property alias resumeTimerButton: resumeTimerButton
    property alias pauseTimerButton: pauseTimerButton
    property alias manualStartButton: manualStartButton
    RowLayout {
        id: rowLayout

        anchors.fill: parent
        anchors.leftMargin: 5

        Switch {
            id: manualTimerToggle
            text: qsTr("Timer")
            checked: true
            focusPolicy: Qt.WheelFocus
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Button {
            id: manualStartButton
            text: qsTr("Start")
            checkable: true
            visible: manualTimerToggle.checked
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Button {
            id: pauseTimerButton
            text: qsTr("Pause")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            checkable: true
            visible: manualTimerToggle.checked
        }

        Button {
            id: resumeTimerButton
            text: qsTr("Resume")
            enabled: true
            checkable: true
            visible: manualTimerToggle.checked
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }
}
