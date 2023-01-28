import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: actions_container
    width: 360
    height: 90
    color: "#99ffffff"
    property alias save_race_toggle: save_race_toggle
    property alias abort_race_toggle: abort_race_toggle
    property alias saveRaceButton: saveRaceButton
    property alias abortRaceButton: abortRaceButton
    property alias startRaceButton: startRaceButton
    RowLayout {
        id: actions_layout
        anchors.fill: parent
        spacing: 5

        anchors.leftMargin: 5

        //scale: 0.7
        Button {
            id: startRaceButton
            text: qsTr("Start Race")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        ColumnLayout {
            spacing: 0
            Switch {
                id: abort_race_toggle
                width: 94
                height: 18
                text: qsTr("Abort")

                checkable: true
                checked: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            Button {
                id: abortRaceButton
                text: qsTr("Abort Race")

                checked: false
                visible: abort_race_toggle.checked
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }
        }
        ColumnLayout {
            Layout.fillWidth: false
            spacing: 0
            Switch {
                id: save_race_toggle
                height: 18
                text: qsTr("Save")
                spacing: 8
                scale: 1

                checked: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            Button {
                id: saveRaceButton
                text: qsTr("Save Race")
                scale: 1

                visible: save_race_toggle.checked
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }
        }
    }
}
