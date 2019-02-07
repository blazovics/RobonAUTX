import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    id: window
    visible: true
    width: 1024
    height: 768
    title: qsTr("RobonAUT 2019")

    function hideAll(){
        speedRaceView.visible = false;
        skillRaceView.visible = false;
        speedRaceResultView.visible = false;
        skillRaceResultView.visible = false;
        voteResultView.visible = false;
        qualificationResultView.visible = false;
        finalResultView.visible = false;
        juniorFinalResultView.visible = false;
        finalSingleResultView.visible = false;
    }

    Image {
        id: backgroundImgae
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "resources/bg.png"
    }

    Footer {
        id: footer

        MouseArea {
            id: mouseArea
            x: 0
            y: 9
            width: 96
            height: 77
            onClicked:
            {
                controller.qmlConnect("");
            }
        }

        Rectangle {
            id: connectionIndicator
            x: 22
            y: 18
            width: 10
            height: 10
            color: "#ffffff"
            radius: 5
            border.width: 0
        }
    }

    Connections{
        target:controller
        onDisconnected:{
            connectionIndicator.visible = true;
        }
        onConnected:{
            connectionIndicator.visible = false;
        }
        onTeamIDChanged:{
            //(const quint32 newTeamID);
        }
        onSendLaneChangeAchieved:{
            //(bool success);
        }
        onSendVehicleStartAchieved:{
            //(bool success);
        }
        onSendSafetyCarFollowed:{
            //(bool success);
        }
        onSendSafetyCarOvertaken:{
            //(bool success);
        }
        onSendCheckpointStateUpdated:{
            //(quint32 checkpointID, bool state);
        }
        onSendSpeedLapCompleted:{
            //(quint32 lapNumber, quint32 lapTime);
        }
        onSendSkillPointUpdated:{
            //(quint32 skillPoint);
        }
        onSendSkillRaceTime:{
            //(QString time);
        }
        onSendRemainingTime:{
             //(QString itme);
        }
        onPresentSpeedResults:{
            hideAll();
            speedRaceResultView.visible = true;

        }
        onPresentSkillResults:{
            hideAll();
            skillRaceResultView.visible = true;

        }
        onPresentFinalResults:{
            hideAll();
            if(isJunior){
                juniorFinalResultView.visible = true
            }
            else{
                finalResultView.visible = true;
            }
        }
        onPresentFinalResultAtPosition:{
            //(quint32 skillPoint, quint32 speedPoint, quint32 votePoint, quint32 qualificationPoint, quint32 finalPoint, quint32 position);
            hideAll();

            finalSingleResultView.sumPointLabel.text = finalPoint;
            finalSingleResultView.teamImage= "resources/icons/" + teamID + ".png";
            finalSingleResultView.positionLabel.text= position + ".";
            finalSingleResultView.votePointLabel.text= votePoint + "p";
            finalSingleResultView.speedRacePointLabel.text= speedPoint + "p";
            finalSingleResultView.skillRacePointLabel.text= skillPoint + "p";
            finalSingleResultView.qualificationPointLabel.text= qualificationPoint + "p";
            finalSingleResultView.teamNameLabel.text= teamName;

            finalSingleResultView.visible = true;

        }
        onPresentVotesResults:{
            hideAll();
            voteResultView.visible = true;

        }
        onPresentQualificationResults:{
            hideAll();
            qualificationResultView.visible = true;

        }
        onPresentSkillRace:{
            hideAll();
            skillRaceView.visible = true;

        }
        onPresentSpeedRace:{
            hideAll();
            speedRaceView.visible = true;
        }
    }

    Rectangle{
        id:container
        color: "#00000000"
        anchors.bottomMargin: 88
        anchors.fill: parent

        SpeedRaceView {
            id: speedRaceView
            visible: false
        }
        SkillRaceView{
            id: skillRaceView
            visible: false
        }
        SpeedRaceResultView{
            id: speedRaceResultView
            visible: false
        }
        SkillRaceResultView{
            id: skillRaceResultView
            visible: false
        }
        VoteResultView{
            id: voteResultView
            visible: false
        }
        QualificationResultView{
            id: qualificationResultView
            visible: false
        }
        FinalResultView{
            id: finalResultView
            mainTitle:  qsTr("Összesített Rangsor")
            visible: false
        }
        FinalResultView{
            id: juniorFinalResultView
            mainTitle: qsTr("Junior Rangsor")
            visible: false
        }
        FinalSingleResultView{
            id: finalSingleResultView
            visible: false
        }
    }





}











/*##^## Designer {
    D{i:1;anchors_height:200;anchors_width:200}D{i:4;anchors_height:200;anchors_width:200}
D{i:5;anchors_x:24;anchors_y:"-284"}D{i:6;anchors_width:130}
}
 ##^##*/
