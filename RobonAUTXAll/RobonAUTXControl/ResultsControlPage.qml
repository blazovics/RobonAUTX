import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.3

Item {
    id: element
    width: 768
    height: 850

    property int fromPos: 1

    Rectangle {
        id: column
        width: 300
        color: "#99ffffff"
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 100
        anchors.left: parent.left
        anchors.leftMargin: 50

        Column {
            id: column1
            height: 590
            spacing: 10
            anchors.fill: parent
            anchors.margins: 20

            Button {
                id: button
                width: 250
                text: qsTr("Ügyességi eredmény")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowSkillResults(fromPos-1);
                }
            }

            Button {
                id: button1
                width: 250
                text: qsTr("Gyorsasági eredmény")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowSpeedResults(false,fromPos-1);
                }
            }

            Button {
                id: button2
                width: 250
                text: qsTr("Kvalifikációs eredmény")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowQualificationResults(fromPos-1);
                }
            }

            Button {
                id: button3
                width: 250
                text: qsTr("Közönségdíj eredmény")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowVotesResults(fromPos-1);
                }
            }

            Switch {
                id: resultSwitch
                text: qsTr("Végeredmény mutatása")
                checked: true
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowFinalResults(false,fromPos-1);
                }
            }

            Button {
                id: button4
                width: 250
                text: qsTr("Junior végeredmény")
                visible: resultSwitch.checked
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowFinalResults(true,fromPos-1);
                }
            }

            Button {
                id: button5
                width: 250
                text: qsTr("Végeredmény")
                visible: resultSwitch.checked
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowFinalResults(false,fromPos-1);
                }
            }

            Switch {
                id: singleFinalSwitch
                text: qsTr("Egyéni végeredmény")
                checked: true
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Button {
                id: button6
                width: 250
                text: qsTr("Egyéni Végeredmény")
                visible: singleFinalSwitch.checked
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowFinalResultAtPosition(false,fromPos-1);
                }
            }
            Button {
                id: button7
                width: 250
                text: qsTr("Egyéni Junior Végeredmény")
                visible: singleFinalSwitch.checked
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowFinalResultAtPosition(true,fromPos-1);
                }
            }
        }
    }

    Rectangle {
        id: rectangle
        x: 516
        width: 300
        color: "#99ffffff"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 550
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.right: parent.right
        anchors.rightMargin: 50


        GridLayout {
            id: gridLayout
            columns: 2
            rows: 2
            anchors.fill: parent

            Label {
                id: label
                text: qsTr("Pozíció")
                font.pointSize: 26
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                Layout.columnSpan: 2
            }

            TextField {
                id: textField
                text: fromPos
                font.pointSize: 15
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.columnSpan: 2
            }

            Button {
                id: minusButton
                text: qsTr("-")
                font.pointSize: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onClicked: {
                    if (fromPos > 1)
                    {
                        fromPos = fromPos - 1;
                    }
                }
            }

            Button {
                id: plusButton
                text: qsTr("+")
                font.pointSize: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onClicked: {
                    if (fromPos < 11)
                    {
                        fromPos = fromPos + 1;
                    }
                }

            }
        }
    }

    Rectangle {
        id: rectangle1
        y: 550
        height: 200
        color: "#99ffffff"
        anchors.left: rectangle.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 100
        anchors.right: parent.right
        anchors.rightMargin: 50

        ColumnLayout {
            id: columnLayout
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.bottomMargin: 20
            anchors.topMargin: 20
            anchors.fill: parent

            Button {
                id: button8
                width: 250
                text: qsTr("BSS adatközlés")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlUpdateBSS(0);
                }
            }
        }
    }



}
