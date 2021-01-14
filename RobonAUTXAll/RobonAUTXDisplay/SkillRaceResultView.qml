import QtQuick 2.0

ResultView{
    id: resultsView
    width: 1024
    height: 680
    titleLabel.text: qsTr("Ügyességi rangsor");



    SingleTableContainer{
        id: header
        height: 80
        positionLabel.text: qsTr("#");
        teamNameLabel.text: qsTr("Csapatnév");
        valueLabel.text: qsTr("Pont");

        anchors.top: resultsView.titleRect.bottom
        anchors.topMargin: 10
    }

    ListView {
        id: listView

        spacing: 7
        boundsBehavior: Flickable.StopAtBounds
        clip: true
        anchors.top: header.bottom
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        delegate: SingleTableContainer{
            height: 40
            positionLabel.text: position + "."
            teamNameLabel.text: name
            valueLabel.text: skillPoint + "p"
            color: {
                if(teamID == manager.teamID){
                    "#ccffffff"
                }
                else{
                    "#00000000"
                }
            }
        }

        model: skillRaceModel

        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }

    }

    ListModel {
        id: dummyModel
        ListElement {
            position: 1
            name: "Bill Smith"
            qualificationPoint: 12
        }
        ListElement {
            position: 2
            name: "Bill Smith"
            qualificationPoint: 13
        }
        ListElement {
            position: 3
            name: "Bill Smith"
            qualificationPoint: 14
        }
    }
}
