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
                id: label1
                width: 390
                height: 150
                color: "#ffffff"
                text: qsTr("8:88.88")
                horizontalAlignment: Text.AlignHCenter
                font.family: digital7.name
                lineHeight: 1.2
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 80
            }

            Label {
                id: label2
                width: 390
                height: 150
                color: "#ffffff"
                text: qsTr("8:88.88")
                horizontalAlignment: Text.AlignHCenter
                font.family: digital7.name
                lineHeight: 1.2
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 80
            }

            Label {
                id: label3
                width: 390
                height: 150
                color: "#ffffff"
                text: qsTr("8:88.88")
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
                id: label4
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
                id: label5
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
                id: label6
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
            model: ListModel {
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
            }
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
            source: "resources/icons/10.png"
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
            id: label
            color: "#ffffff"
            text: qsTr("8:88.88")
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
            id: image
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
    }


}













/*##^## Designer {
    D{i:4;anchors_height:400}D{i:8;anchors_width:200}
}
 ##^##*/
