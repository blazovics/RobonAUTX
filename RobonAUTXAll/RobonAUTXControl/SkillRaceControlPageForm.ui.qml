import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    width: 768
    height: 850
    property alias time_container: time_container
    property alias actions_container: actions_container
    property alias race_time_container: race_time_container
    property alias checkpoints_container: checkpoints_container

    RaceTimeContainer {
        id: race_time_container
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 15
        x: 390
    }

    CheckpointsContainer {
        id: checkpoints_container
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 15
    }

    RaceActionsContainer {
        id: actions_container
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: race_time_container.bottom
        anchors.topMargin: 15
        x: 185
    }

    SkillRaceResultsContainer {
        id: time_container
        anchors.top: parent.top
        anchors.topMargin: 15
        anchors.left: checkpoints_container.right
        anchors.leftMargin: 15
        anchors.right: race_time_container.left
        anchors.rightMargin: 15
    }
}






/*##^## Designer {
    D{i:2;anchors_y:16}D{i:3;anchors_height:100;anchors_width:100;anchors_x:50;anchors_y:81}
}
 ##^##*/
