import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

    SingleResultView{
        width: 1024
        height: 680



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
            delegate: SingleTableContainer{
                height: 60
                positionLabel.text: position
                teamNameLabel.text: name
                valueLabel.text: qualificationPoint
            }

            model: qualificationModel

            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }

        }
    }
