import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: race_time_container
    width: 150
    height: 250
    color: "#99ffffff"
    property alias manualTimerToggle: manualTimerToggle
    property alias resumeTimerButton: resumeTimerButton
    property alias pauseTimerButton: pauseTimerButton
    property alias manualStartButton: manualStartButton
    ColumnLayout {
        id: columnLayout
        anchors.topMargin: 10
        anchors.bottomMargin: 10
        anchors.fill: parent

        Switch {
            id: manualTimerToggle
            text: qsTr("Manual Timer")
            focusPolicy: Qt.WheelFocus
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Button {
            id: manualStartButton
            text: qsTr("Manual Start Timer")
            checkable: true
            visible: manualTimerToggle.checked
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Button {
            id: pauseTimerButton
            text: qsTr("Pause Timer")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            checkable: true
            visible: manualTimerToggle.checked
        }

        Button {
            id: resumeTimerButton
            text: qsTr("Resume Timer")
            enabled: true
            checkable: true
            visible: manualTimerToggle.checked
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }
}
