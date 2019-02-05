import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Rectangle{
    id: singleResultView
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
        id: titleRect
        height: 100
        color: "#80000000"
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20

        Label {
            id: label
            color: "#ffffff"
            text: qsTr("Label")
            font.pointSize: 70
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.family: roboto.name
        }
    }

    SingleTableContainer {
        id: headerContainer
        x: 0
        y: 130
        height: 31
    }

    DoubleTableContainer {
        id: headerContainer2
        x: 0
        y: 230
        height: 31
    }
}
