import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: actions_container
    width: 220
    height: 353
    color: "#99ffffff"
    property alias saveRaceButton: saveRaceButton
    property alias abortRaceButton: abortRaceButton
    property alias startRaceButton: startRaceButton
    ColumnLayout {
        id: actions_layout
        anchors.topMargin: 5
        anchors.bottomMargin: 5
        anchors.fill: parent
        
        Button {
            id: startRaceButton
            text: qsTr("Start Race")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        
        Switch {
            id: abort_race_toggle
            text: qsTr("Abort Race")
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
        
        Switch {
            id: save_race_toggle
            text: qsTr("Save Race")
            checked: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        
        Button {
            id: saveRaceButton
            text: qsTr("Save Race")
            visible: save_race_toggle.checked
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }
}
