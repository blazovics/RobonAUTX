import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Rectangle{
    id: rectangle2
    width: 1024
    height: 680
    color: "#00000000"
    anchors.fill: parent

    FontLoader {
        id: digital7;
        source: "qrc:/resources/digital-7.ttf"
    }

    FontLoader {
        id: roboto;
        source: "qrc:/resources/Roboto.ttf"
    }

    function resetView(){
        for(var i = 0; i<12; i++)
        {
            setCheckpointVisibility(i,false);
        }
        skillPointLabel.text = "0p"
        skillTimeLabel.text = "00:00"
    }

    Connections{
        target:manager

        onSendCheckpointStateUpdated:{
            //(quint32 checkpointID, bool state);
            setCheckpointVisibility(checkpointID,state);
        }
        onSendSkillPointUpdated:{
            //(quint32 skillPoint);
            skillPointLabel.text = skillPoint + "p"
        }
        onSendRemainingTime:{
            //(QString time);
            skillTimeLabel.text = time
        }
        onTeamIDChanged:{
            //(const quint32 newTeamID);
            teamImage.source = "resources/icons/" + newTeamID + ".png"
        }
    }


    function setCheckpointVisibility(index,value){
        switch (index) {
        case 0:
            checkpoint0.visible = value;
            break;
        case 1:
            checkpoint1.visible = value;
            break;
        case 2:
            checkpoint2.visible = value;
            break;
        case 3:
            checkpoint3.visible = value;
            break;
        case 4:
            checkpoint4.visible = value;
            break;
        case 5:
            checkpoint5.visible = value;
            break;
        case 6:
            checkpoint6.visible = value;
            break;
        case 7:
            checkpoint7.visible = value;
            break;
        case 8:
            checkpoint8.visible = value;
            break;
        case 9:
            checkpoint9.visible = value;
            break;
        case 10:
            checkpoint10.visible = value;
            break;
        case 11:
            checkpoint11.visible = value;
            break;
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
            source: "resources/icons/" + controller.teamID + ".png"
        }

    }

    Rectangle {
        id: rectangle4
        x: 8
        y: 2
        width: 300
        color: "#99000000"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        Label {
            id: skillTimeLabel
            color: "#ffffff"
            text: "88:88"
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 1.2
            font.pointSize: 90
            font.family: digital7.name
        }
        anchors.topMargin: 20
        anchors.bottom: rectangle3.bottom
        anchors.bottomMargin: 0
    }

    Rectangle {
        id: rectangle5
        x: 3
        y: 4
        width: 160
        color: "#99000000"
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: parent.top
        Label {
            id: skillPointLabel
            color: "#ffffff"
            text: "88p"
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            font.family: roboto.name
            lineHeight: 1.2
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 70
        }
        anchors.topMargin: 20
        anchors.bottom: rectangle3.bottom
        anchors.bottomMargin: 0
    }

    Rectangle {
        id: rectangle
        color: "#80000000"
        anchors.top: rectangle3.bottom
        anchors.topMargin: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20

        Image {
            id: background
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "resources/track/palyaterv_red.png"
        }

        Image {
            id: checkpoint0
            source: "resources/track/1.png"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
        }

        Image {
            id: checkpoint1
            source: "resources/track/2.png"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
        }

        Image {
            id: checkpoint2
            source: "resources/track/3.png"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
        }

        Image {
            id: checkpoint3
            source: "resources/track/4.png"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
        }

        Image {
            id: checkpoint4
            source: "resources/track/5.png"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
        }

        Image {
            id: checkpoint5
            source: "resources/track/6.png"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
        }

        Image {
            id: checkpoint6
            source: "resources/track/7.png"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
        }

        Image {
            id: checkpoint7
            source: "resources/track/8.png"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
        }

        Image {
            id: checkpoint8
            source: "resources/track/9.png"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
        }

        Image {
            id: checkpoint9
            source: "resources/track/10.png"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
        }

        Image {
            id: checkpoint10
            source: "resources/track/11.png"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
        }

        Image {
            id: checkpoint11
            source: "resources/track/12.png"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
        }
    }
}

/*##^## Designer {
    D{i:11;anchors_height:100;anchors_width:100;anchors_x:335;anchors_y:208}D{i:10;anchors_height:200;anchors_width:200;anchors_x:293;anchors_y:280}
}
 ##^##*/
