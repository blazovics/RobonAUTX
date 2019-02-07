import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.3

Item {
    id: element
    width: 768
    height: 850

    property int fromPos: 0

    Rectangle {
        id: column
        width: 300
        color: "#99ffffff"
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 200
        anchors.left: parent.left
        anchors.leftMargin: 50

        Column {
            id: column1
            spacing: 10
            anchors.fill: parent
            anchors.margins: 20

            Button {
                id: button
                width: 250
                text: qsTr("Ügyességi eredmény")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowSkillResults(fromPos);
                }
            }

            Button {
                id: button1
                width: 250
                text: qsTr("Gyorsasági eredmény")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowSpeedResults(false,fromPos);
                }
            }

            Button {
                id: button2
                width: 250
                text: qsTr("Kvalifikációs eredmény")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowQualificationResults(fromPos);
                }
            }

            Button {
                id: button3
                width: 250
                text: qsTr("Közönségdíj eredmény")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowVotesResults(fromPos);
                }
            }

            Switch {
                id: resultSwitch
                text: qsTr("Végeredmény mutatása")
                checked: true
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowFinalResults(false,fromPos);
                }
            }

            Button {
                id: button4
                width: 250
                text: qsTr("Junior végeredmény")
                visible: resultSwitch.checked
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowFinalResults(true,fromPos);
                }
            }

            Button {
                id: button5
                width: 250
                text: qsTr("Végeredmény")
                visible: resultSwitch.checked
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowFinalResults(false,fromPos);
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
                opacity: singleFinalSwitch.checked
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowFinalResultAtPosition(false,fromPos);
                }
            }
            Button {
                id: button7
                width: 250
                text: qsTr("Egyéni Junior Végeredmény")
                opacity: singleFinalSwitch.checked
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowFinalResultAtPosition(true,fromPos);
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
                    if (fromPos > 0)
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



}
