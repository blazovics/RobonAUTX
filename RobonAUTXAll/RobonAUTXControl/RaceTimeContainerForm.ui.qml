import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: race_time_container
    width: 220
    height: 250
    color: "#99ffffff"
    property alias resumeTimerButton: resumeTimerButton
    property alias pauseTimerButton: pauseTimerButton
    property alias manualStartButton: manualStartButton
    ColumnLayout {
        id: columnLayout
        anchors.topMargin: 10
        anchors.bottomMargin: 10
        anchors.fill: parent

        Switch {
            id: manual_set_timer_toggle
            text: qsTr("Manual Timer Functions")
            focusPolicy: Qt.WheelFocus
            checked: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Button {
            id: manualStartButton
            text: qsTr("Manual Start Timer")
            checkable: true
            visible: manual_set_timer_toggle.checked
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Button {
            id: pauseTimerButton
            text: qsTr("Pause Timer")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            checkable: true
            visible: manual_set_timer_toggle.checked
        }

        Button {
            id: resumeTimerButton
            text: qsTr("Resume Timer")
            enabled: true
            checkable: true
            visible: manual_set_timer_toggle.checked
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }
}