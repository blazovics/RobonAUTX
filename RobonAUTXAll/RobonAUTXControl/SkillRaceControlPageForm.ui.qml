import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    id: item1
    width: 768
    height: 850
    property alias raceResultsContainer: raceResultsContainer
    property alias actions_container: actions_container
    property alias race_time_container: race_time_container
    property alias checkpoints_container: checkpoints_container

    RaceTimeContainer {
        id: race_time_container
        height: 250
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.leftMargin: 15
        anchors.topMargin: 15
        anchors.left: checkpoints_container.right
    }

    CheckpointsContainer {
        id: checkpoints_container
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: raceResultsContainer.bottom
        anchors.topMargin: 15
    }

    RaceActionsContainer {
        id: actions_container
        anchors.top: race_time_container.bottom
        anchors.rightMargin: 15
        anchors.leftMargin: 15
        anchors.topMargin: 15
        anchors.left: checkpoints_container.right
        anchors.right: parent.right
    }

    SkillRaceResultsContainer {
        id: raceResultsContainer
        height: 120
        anchors.top: parent.top
        anchors.topMargin: 15
        anchors.left: parent.left
        anchors.leftMargin: 15
        anchors.right: race_time_container.left
        anchors.rightMargin: 15
    }
}
