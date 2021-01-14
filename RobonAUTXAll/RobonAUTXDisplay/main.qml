import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    id: window
    visible: true
    width: 1024
    height: 768
    title: qsTr("RobonAUT 2019")
    flags: Qt.Window | Qt.WindowFullscreenButtonHint

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

        onDisconnected:
        {
            connectionIndicator.visible = true;
        }
        onConnected:
        {
            connectionIndicator.visible = false;
            hideAll();
        }
    }

    Connections{
        target:manager
        onPresentSpeedResults:
        {
            hideAll();
            speedRaceResultView.visible = true;
        }
        onPresentSkillResults:
        {
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
        onPresentFinalResultAtPosition:
        {
            //(quint32 skillPoint, quint32 speedPoint, quint32 votePoint, quint32 qualificationPoint, quint32 finalPoint, quint32 position);
            hideAll();

            finalSingleResultView.sumPointLabel.text = finalPoint;
            finalSingleResultView.teamImage.source = "resources/icons/" + teamID + ".png";
            finalSingleResultView.positionLabel.text= position + ".";
            finalSingleResultView.votePointLabel.text= votePoint + "p";
            finalSingleResultView.speedRacePointLabel.text= speedPoint + "p";
            finalSingleResultView.skillRacePointLabel.text= skillPoint + "p";
            finalSingleResultView.qualificationPointLabel.text= qualificationPoint + "p";
            finalSingleResultView.teamNameLabel.text= teamName;

            finalSingleResultView.visible = true;
        }
        onPresentVotesResults:
        {
            hideAll();
            voteResultView.visible = true;
        }
        onPresentQualificationResults:
        {
            hideAll();
            qualificationResultView.visible = true;
        }
        onPresentSkillRace:
        {
            hideAll();
            skillRaceView.resetView();
            skillRaceView.visible = true;
            console.log("SKILL" + skillRaceView.visible);
        }
        onPresentSpeedRace:
        {
            hideAll();
            speedRaceView.resetView();
            speedRaceView.visible = true;
            console.log("SPEED" + skillRaceView.visible);
        }
    }

    Rectangle{
        id:container
        color: "#00000000"
        anchors.bottomMargin: 88
        anchors.fill: parent

        SpeedRaceView {
            id: speedRaceView
        }
        SkillRaceView{
            id: skillRaceView
        }
        SpeedRaceResultView{
            id: speedRaceResultView
        }
        SkillRaceResultView{
            id: skillRaceResultView
        }
        VoteResultView{
            id: voteResultView
        }
        QualificationResultView{
            id: qualificationResultView
        }
        FinalResultView{
            id: finalResultView
            mainTitle:  qsTr("Összesített Rangsor")
        }
        FinalResultView{
            id: juniorFinalResultView
            mainTitle: qsTr("Junior Rangsor")
        }
        FinalSingleResultView{
            id: finalSingleResultView
        }
    }





}













/*##^## Designer {
    D{i:1;anchors_height:200;anchors_width:200}D{i:4;anchors_height:200;anchors_width:200}
D{i:5;anchors_x:24;anchors_y:"-284"}D{i:6;anchors_width:130}
}
 ##^##*/
