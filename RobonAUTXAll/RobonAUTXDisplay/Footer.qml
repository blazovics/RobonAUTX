import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Rectangle {
    id: footer
    color: "#00000000"
    anchors.top: container.bottom
    anchors.topMargin: 0
    anchors.right: parent.right
    anchors.rightMargin: 0
    anchors.left: parent.left
    anchors.leftMargin: 0
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 0
    
    Image {
        id: image
        x: 20
        width: 330
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 20
        fillMode: Image.PreserveAspectFit
        source: "resources/RobonAUT_logo_black.png"
    }
    
    Image {
        id: image1
        width: 240
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        fillMode: Image.PreserveAspectFit
        source: "resources/sds.png"
    }
}
