import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: actions_container
    width: 200
    height: 353
    color: "#e2fdea"
    ColumnLayout {
        id: actions_layout
        anchors.topMargin: 5
        anchors.bottomMargin: 5
        anchors.fill: parent
        
        Button {
            id: start_race_button
            text: qsTr("Start Race")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        
        Switch {
            id: abort_race_toggle
            text: qsTr("Abort Race")
            checked: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        
        Button {
            id: abort_race_button
            text: qsTr("Abort Race")
            checked: false
            visible: abort_race_toggle.checked
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        
        Switch {
            id: save_race_toggle
            text: qsTr("Save Race")
            checked: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        
        Button {
            id: save_race_button
            text: qsTr("Save Race")
            visible: save_race_toggle.checked
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }
}
