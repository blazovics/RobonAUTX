import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    id: item1
    width: 360
    height: 750
    property alias raceResultsContainer: raceResultsContainer
    property alias actions_container: actions_container
    property alias race_time_container: race_time_container
    property alias checkpoints_container: checkpoints_container

    SkillRaceResultsContainer {
        id: raceResultsContainer
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
    }

    RaceTimeContainer {
        id: race_time_container
        anchors.top: raceResultsContainer.bottom
        anchors.topMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
    }

    RaceActionsContainer {
        id: actions_container
        anchors.top: race_time_container.bottom
        anchors.topMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
    }

    CheckpointsContainer {
        id: checkpoints_container
        //anchors.left: parent.left
        //anchors.leftMargin: 10
        anchors.top: actions_container.bottom
        anchors.topMargin: 15
    }
}
