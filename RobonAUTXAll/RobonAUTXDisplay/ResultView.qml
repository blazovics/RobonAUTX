import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Rectangle{
    id: singleResultView
    color: "#00000000"
    property alias titleRect: titleRect
    property alias titleLabel: titleLabel
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
            id: titleLabel
            color: "#ffffff"
            text: qsTr("Label")
            anchors.rightMargin: 5
            anchors.leftMargin: 5
            anchors.bottomMargin: 5
            anchors.topMargin: 5
            fontSizeMode: Text.Fit
            font.pointSize: 70
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.family: roboto.name
        }
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
