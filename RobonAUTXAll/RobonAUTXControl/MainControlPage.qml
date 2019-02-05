import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.3

Item {
    id: mainControlPage
    width: 768
    height: 850

    signal teamSelected(int teamID);

    signal startSkillRace(int teamID);
    signal startSpeedRace(int teamID);

    property int selectedTeamID: 0

    ListView {
        id: listView
        width: 230
        spacing: 10
        boundsBehavior: Flickable.StopAtBounds
        clip: true
        anchors.top: parent.top
        anchors.topMargin: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        anchors.left: parent.left
        anchors.leftMargin: 15
        delegate: Pane {

            Material.background:  Material.Grey
            Material.elevation: 3
            x: 5
            width: 200
            height: 40

            Label {
                text: name
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.fill: parent
            }
            MouseArea {
                anchors.fill: parent
                onClicked:{
                    listView.currentIndex = index
                    selectedTeamID = index + 1;
                }
            }

        }
        model: teamModel

        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }

        onCurrentItemChanged: {
            mainControlPage.teamSelected(selectedTeamID);
        }
    }

    Pane {
        id: pane
        width: 300
        height: 400
        anchors.top: parent.top
        anchors.topMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: 15

        Material.elevation: 3
        Material.background: Material.Grey

        ColumnLayout {
            id: columnLayout
            anchors.fill: parent

            Button {
                id: button
                text: qsTr("Start Skill Race")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                visible: selectedTeamID > 0
                onClicked: {
                    controlUnit.qmlInitSkillRace(selectedTeamID)
                }
            }

            Switch {
                id: manualSpeedRaceSwitch
                text: qsTr("Manual Start Speed Race")
                checked: false
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            Button {
                id: button1
                text: qsTr("Start Speed Race")
                visible: manualSpeedRaceSwitch.checked
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onClicked: {
                    controlUnit.qmlInitSpeedRace(selectedTeamID);
                }
            }

        }
    }

}



/*##^## Designer {
    D{i:1;anchors_height:850}
}
 ##^##*/
