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
            source: "resources/icons/10.png"
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
            id: label
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
            id: label1
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
            id: image
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "qrc:/qtquickplugin/images/template_image.png"
        }
    }
}

/*##^## Designer {
    D{i:11;anchors_height:100;anchors_width:100;anchors_x:335;anchors_y:208}D{i:10;anchors_height:200;anchors_width:200;anchors_x:293;anchors_y:280}
}
 ##^##*/
