import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Rectangle{
    id: rectangle2
    width: 1024
    height: 680
    color: "#00000000"
    property alias sumPointLabel: sumPointLabel
    property alias teamImage: teamImage
    property alias positionLabel: positionLabel
    property alias votePointLabel: votePointLabel
    property alias speedRacePointLabel: speedRacePointLabel
    property alias skillRacePointLabel: skillRacePointLabel
    property alias qualificationPointLabel: qualificationPointLabel
    property alias teamNameLabel: teamNameLabel

    anchors.fill: parent

    Rectangle {
        id: titlerect
        height: 100
        color: "#99000000"
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 20

        Label {
            id: teamNameLabel
            color: "#ffffff"
            text: qsTr("8:88.88")
            lineHeight: 1.2
            font.pointSize: 70
            font.family: roboto.name
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
        }
    }

    FontLoader {
        id: digital7;
        source: "qrc:/resources/digital-7.ttf"
    }

    FontLoader {
        id: roboto;
        source: "qrc:/resources/Roboto.ttf"
    }

    Grid {
        id: grid
        width: 499
        height: 350
        spacing: 10
        rows: 4
        columns: 2
        anchors.top: titlerect.bottom
        anchors.topMargin: 10
        anchors.left: rectangle.right
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 20

        Rectangle {
            id: rectangle1
            width: 374
            height: 80
            color: "#99000000"

            Label {
                id: label7
                color: "#ffffff"
                text: qsTr("Kvalifikáció")
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                font.family: roboto.name
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 40
            }

        }

        Rectangle {
            id: rectangle3
            width: 130
            height: 80
            color: "#99000000"
            Label {
                id: qualificationPointLabel
                color: "#ffffff"
                text: "12p"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pointSize: 40
            }
        }

        Rectangle {
            id: rectangle4
            width: 374
            height: 80
            color: "#99000000"
            Label {
                id: label9
                width: 374
                color: "#ffffff"
                text: qsTr("Ügyességi")
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pointSize: 40
                horizontalAlignment: Text.AlignHCenter
                font.family: roboto.name
            }
        }

        Rectangle {
            id: rectangle5
            width: 130
            height: 80
            color: "#99000000"
            Label {
                id: skillRacePointLabel
                color: "#ffffff"
                text: "12p"
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pointSize: 40
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: rectangle6
            width: 374
            height: 80
            color: "#99000000"
            Label {
                id: label11
                width: 374
                color: "#ffffff"
                text: qsTr("Gyorsasági")
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pointSize: 40
                horizontalAlignment: Text.AlignHCenter
                font.family: roboto.name
            }
        }

        Rectangle {
            id: rectangle7
            width: 130
            height: 80
            color: "#99000000"
            Label {
                id: speedRacePointLabel
                color: "#ffffff"
                text: "12p"
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pointSize: 40
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: rectangle8
            width: 374
            height: 80
            color: "#99000000"
            Label {
                id: label13
                width: 374
                color: "#ffffff"
                text: qsTr("Közönség")
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pointSize: 40
                horizontalAlignment: Text.AlignHCenter
                font.family: roboto.name
            }
        }

        Rectangle {
            id: rectangle9
            width: 130
            height: 80
            color: "#99000000"
            Label {
                id: votePointLabel
                color: "#ffffff"
                text: "12p"
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pointSize: 40
                horizontalAlignment: Text.AlignHCenter
            }
        }
    }

    Rectangle {
        id: rectangle
        width: 460
        color: "#99000000"
        anchors.top: titlerect.bottom
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        Label {
            id: positionLabel
            color: "#ffffff"
            text: qsTr("9.")
            leftPadding: 36
            anchors.bottom: rectangle11.top
            anchors.bottomMargin: 0
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.top: parent.top
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 110
            horizontalAlignment: Text.AlignHCenter
            font.family: roboto.name
        }

        Rectangle {
            id: rectangle11
            x: 124
            y: 315
            width: 400
            height: 400
            color: "#2effffff"
            radius: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter

            Image {
                id: teamImage
                anchors.fill: parent
                anchors.margins: 25
                fillMode: Image.PreserveAspectFit
                source: "resources/icons/5.png"
            }
        }
    }

    Rectangle {
        id: rectangle10
        color: "#99000000"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: grid.bottom
        anchors.topMargin: 10
        anchors.left: rectangle.right
        anchors.leftMargin: 10
        Label {
            id: sumPointLabel
            color: "#ffffff"
            text: qsTr("100p")
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
            font.pointSize: 90
            horizontalAlignment: Text.AlignHCenter
            font.family: roboto.name
        }
    }





}

/*##^##
Designer {
    D{i:1;anchors_width:460}D{i:7;anchors_height:100}D{i:9;anchors_height:100}D{i:11;anchors_height:100}
D{i:13;anchors_height:100}D{i:15;anchors_height:100}D{i:17;anchors_height:100}D{i:19;anchors_height:100}
D{i:21;anchors_height:100}D{i:23;anchors_height:100}D{i:25;anchors_height:100;anchors_width:100;anchors_x:92;anchors_y:90}
D{i:27;anchors_height:100}D{i:26;anchors_height:80;anchors_width:374;anchors_x:7;anchors_y:"-1"}
}
##^##*/
