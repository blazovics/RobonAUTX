import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    id: window
    visible: true
    width: 1024
    height: 768
    title: qsTr("RobonAUT 2019")

    Image {
        id: backgroundImgae
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "resources/bg.png"
    }

    Footer {
        id: footer
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
        SingleResultView{

        }
    }




}







/*##^## Designer {
    D{i:1;anchors_height:200;anchors_width:200}D{i:5;anchors_x:24;anchors_y:-284}D{i:4;anchors_height:200;anchors_width:200}
D{i:6;anchors_width:130}
}
 ##^##*/
