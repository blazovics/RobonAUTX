import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Rectangle{
    id: rectangle2
    width: 1024
    height: 680
    color: "#00000000"
    property alias speedTimeLabel: speedTimeLabel
    property alias teamImage: teamImage

    property int finishedLapCount: -1

    anchors.fill: parent

    function resetView(){
        lap1Label.visible = false;
        lap1TitleLabel.visible = false;

        lap2Label.visible = false;
        lap2TitleLabel.visible = false;

        lap3Label.visible = false;
        lap3TitleLabel.visible = false;

        overtakingImage.visible = false;
        overtakingMultiplierLabel.visible = false;
        safetyCarImage.visible = false;
        speedTimeLabel.text = "00:00.00"

        finishedLapCount = -1;
    }

    FontLoader {
        id: digital7;
        source: "qrc:/resources/digital-7.ttf"
    }

    FontLoader {
        id: roboto;
        source: "qrc:/resources/Roboto.ttf"
    }

    Connections{
        target:manager

        onSendSpeedRaceTime:{
            //(QString time);
            if(finishedLapCount > -1 && finishedLapCount < 3)
            {
                speedTimeLabel.text = time;
            }
        }
        onTeamIDChanged:{
            //(const quint32 newTeamID);
            //teamImage = "resources/icons/" + manager.teamID + ".png"
        }
        onSendSafetyCarFollowed:{
            //(bool success);
            safetyCarImage.visible = success;
        }
        onSendSafetyCarOvertaken:{
            if(value == 0)
            {
                overtakingImage.visible = false;
                overtakingMultiplierLabel.visible = false;
            }
            else if(value == 1)
            {
                overtakingImage.visible = true;
                overtakingMultiplierLabel.visible = false;
            }
            else if(value == 2)
            {
                overtakingImage.visible = true;
                overtakingMultiplierLabel.visible = true;
            }
        }
        onSendSpeedLapCompleted:{
            //(quint32 lapNumber, quint32 lapTime);

            finishedLapCount = lapNumber;

            switch (lapNumber){
            case 1:
                lap1Label.visible = true;
                lap1TitleLabel.visible = true;
                lap1Label.text = lapTime;
                break;
            case 2:
                lap2Label.visible = true;
                lap2TitleLabel.visible = true;
                lap2Label.text = lapTime;
                break;
            case 3:
                lap3Label.visible = true;
                lap3TitleLabel.visible = true;
                lap3Label.text = lapTime;
                break;
            }
        }
    }

    Rectangle {
        id: rectangle
        width: 605
        color: "#99000000"
        anchors.top: rectangle3.bottom
        anchors.topMargin: 15
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        Column {
            id: column
            width: 390
            height: 450
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 0

            Label {
                id: lap1Label
                height: 150
                color: "#ffffff"
                text: qsTr("8:88.88")
                fontSizeMode: Text.Fit
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 10
                horizontalAlignment: Text.AlignHCenter
                font.family: digital7.name
                lineHeight: 1.2
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 80
            }

            Label {
                id: lap2Label
                height: 150
                color: "#ffffff"
                text: qsTr("8:88.88")
                fontSizeMode: Text.Fit
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 10
                horizontalAlignment: Text.AlignHCenter
                font.family: digital7.name
                lineHeight: 1.2
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 80
            }

            Label {
                id: lap3Label
                height: 150
                color: "#ffffff"
                text: qsTr("8:88.88")
                fontSizeMode: Text.Fit
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 10
                horizontalAlignment: Text.AlignHCenter
                font.family: digital7.name
                lineHeight: 1.2
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 80
            }
        }

        Column {
            id: column1
            height: 450
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: column.left
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0

            Label {
                id: lap1TitleLabel
                width: parent.width
                height: 150
                color: "#ffffff"
                text: qsTr("1. KÖR")
                font.family: roboto.name
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 40
            }

            Label {
                id: lap2TitleLabel
                width: parent.width
                height: 150
                color: "#ffffff"
                text: qsTr("2. KÖR")
                font.family: roboto.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 40
            }

            Label {
                id: lap3TitleLabel
                width: parent.width
                height: 150
                color: "#ffffff"
                text: qsTr("3. KÖR")
                font.family: roboto.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 40
            }
        }
    }

    Rectangle {
        id: rectangle1
        color: "#99000000"
        anchors.top: rectangle.top
        anchors.topMargin: 0
        anchors.left: rectangle.right
        anchors.leftMargin: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 20

        Label {
            id: label7
            height: 100
            color: "#ffffff"
            text: qsTr("TOPLISTA")
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            horizontalAlignment: Text.AlignHCenter
            font.family: roboto.name
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 40
        }

        ListView {
            id: listView
            x: 8
            y: 104
            width: 348
            height: 403
            model:inRaceSpeedModel
            /*
            ListModel {
                ListElement {
                    time:  qsTr("8:88.88")
                    teamID: 1
                }

                ListElement {
                    time:  qsTr("8:88.88")
                    teamID: 2
                }

                ListElement {
                    time:  qsTr("8:88.88")
                    teamID: 3
                }

                ListElement {
                    time:  qsTr("8:88.88")
                    teamID: 4
                }
            }*/
            delegate: TopSpeeds {
            }
        }

    }

    Rectangle {
        id: rectangle3
        width: 130
        height: 130
        color: "#99000000"
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20

        Rectangle {
            id: rectangle6
            color: "#ffffff"
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.bottomMargin: 10
            anchors.topMargin: 10
            anchors.fill: parent
        }

        Image {
            id: teamImage
            x: 15
            y: 15
            width: 110
            height: 110
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            fillMode: Image.PreserveAspectFit
            source: "resources/icons/" + manager.teamID + ".png"
        }

    }

    Rectangle {
        id: rectangle4
        width: 460
        color: "#99000000"
        anchors.bottom: rectangle3.bottom
        anchors.bottomMargin: 0
        anchors.left: rectangle3.right
        anchors.leftMargin: 15
        anchors.top: parent.top
        anchors.topMargin: 20

        Label {
            id: speedTimeLabel
            color: "#ffffff"
            text: qsTr("8:88.88")
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.bottomMargin: 10
            anchors.topMargin: 10
            lineHeight: 1.2
            font.pointSize: 90
            font.family: digital7.name
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
        }
    }

    Rectangle {
        id: rectangle5
        color: "#99000000"
        anchors.left: rectangle4.right
        anchors.leftMargin: 15
        anchors.bottom: rectangle4.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20

        Image {
            id: image2
            x: -625
            y: 270
            width: 150
            height: 100
            anchors.leftMargin: 15
            source: "resources/safetyred.png"
            anchors.left: parent.left
            fillMode: Image.PreserveAspectFit
            anchors.verticalCenter: parent.verticalCenter
        }

        Image {
            id: safetyCarImage
            width: 150
            height: 100
            anchors.left: parent.left
            anchors.leftMargin: 15
            anchors.verticalCenter: parent.verticalCenter
            fillMode: Image.PreserveAspectFit
            source: "resources/safetygreen.png"
        }

        Image {
            id: image1
            x: 226
            y: 3
            width: 150
            height: 100
            anchors.right: parent.right
            anchors.rightMargin: 15
            anchors.verticalCenterOffset: 0
            anchors.verticalCenter: parent.verticalCenter
            fillMode: Image.PreserveAspectFit
            source: "resources/overtakingred.png"
        }

        Image {
            id: overtakingImage
            x: 233
            y: 10
            width: 150
            height: 100
            source: "resources/overtakinggreen.png"
            anchors.rightMargin: 15
            anchors.verticalCenterOffset: 0
            anchors.right: parent.right
            fillMode: Image.PreserveAspectFit
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: overtakingMultiplierLabel
            x: 303
            y: 70
            color: "#32ff32"
            text: qsTr("x2")
            font.bold: true
            font.family: roboto.name
            font.pointSize: 32
            verticalAlignment: Text.AlignVCenter
        }

    }



}



















/*##^## Designer {
    D{i:6;anchors_width:390}D{i:7;anchors_width:390}D{i:8;anchors_width:390}D{i:4;anchors_height:400}
}
 ##^##*/
