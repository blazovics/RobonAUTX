import QtQuick 2.0

//new Date(72333).toLocaleTimeString(Qt.locale(),"mm:ss.zzz")
ResultView{
    id: resultsView
    width: 1024
    height: 680
    titleLabel.text: qsTr("Gyorsasági rangsor");

    SingleTableContainer{
        id: header
        height: 80
        positionLabel.text: qsTr("#");
        teamNameLabel.text: qsTr("Csapatnév");
        valueLabel.text: qsTr("Idő");

        anchors.top: resultsView.titleRect.bottom
        anchors.topMargin: 10
    }

    ListView {
        id: listView

        spacing: 10
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
            height: 60
            positionLabel.text: position + "."
            teamNameLabel.text: name
            valueLabel.text: new Date(speedTime).toLocaleTimeString(Qt.locale(),"mm:ss.zz")
        }

        model: speedRaceModel

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
