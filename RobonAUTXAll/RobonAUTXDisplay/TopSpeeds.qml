import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Item {
    id: element
    width: 340
    height: 100

    FontLoader {
        id: digital7;
        source: "qrc:/resources/digital-7.ttf"
    }

    Rectangle{
        id: imageContainer
        x: 15
        y: 5
        width: 80
        height: 80
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        color: "#ffffff"
        Image {
            id: image
            width: 78
            height: 78
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "resources/icons/" + teamID + ".png"
        }
    }

    Label {
        y: 43
        height: 90
        color: "#ffffff"
        text: {
            var timeString = new Date(speedTime).toLocaleTimeString(Qt.locale(),"mm:ss.zzz");
            timeString.substring(0,timeString.length-1);
        }
        font.pointSize: 50
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: imageContainer.right
        anchors.leftMargin: 20
        anchors.verticalCenter: parent.verticalCenter
        font.family: digital7.name
    }

}





/*##^## Designer {
    D{i:2;anchors_x:105}D{i:3;anchors_x:105}
}
 ##^##*/
