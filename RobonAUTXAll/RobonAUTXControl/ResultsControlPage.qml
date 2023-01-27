import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.3

Item {
    id: element
    width: 760
    height: 750

    property int fromPos: 1

    Rectangle {
        id: column
        width: 180
        color: "#99ffffff"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10

        Column {
            id: column1
            spacing: 10
            anchors.fill: parent
            anchors.margins: 20

            Button {
                id: button
                //width: 250
                text: qsTr("Ügyességi eredmény")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowSkillResults(fromPos-1);
                }
            }

            Button {
                id: button1
                //width: 250
                text: qsTr("Gyorsasági eredmény")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowSpeedResults(false,fromPos-1);
                }
            }

            Button {
                id: button2
               // width: 250
                text: qsTr("Kvalifikációs eredmény")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowQualificationResults(fromPos-1);
                }
            }

            Button {
                id: button3
               // width: 250
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
                //width: 250
                text: qsTr("Junior végeredmény")
                visible: resultSwitch.checked
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowFinalResults(true,fromPos-1);
                }
            }

            Button {
                id: button5
               // width: 250
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
               // width: 250
                text: qsTr("Egyéni Végeredmény")
                visible: singleFinalSwitch.checked
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlShowFinalResultAtPosition(false,fromPos-1);
                }
            }
            Button {
                id: button7
               // width: 250
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
        anchors.left: column.right
        anchors.leftMargin: 10
        color: "#99ffffff"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: rectangle1.top
        anchors.bottomMargin: 10


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
                font.pointSize: 10
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
                font.pointSize: 10
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
        height: 300
        color: "#99ffffff"
        anchors.left: column.right
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10

        ColumnLayout {
            id: columnLayout
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.bottomMargin: 20
            anchors.topMargin: 20
            anchors.fill: parent

            Button {
                id: button12
                text: qsTr("BSS Csapatok")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlUpdateBSS(4);
                }
            }

            Button {
                id: button9
                text: qsTr("BSS Kvalifikáció")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlUpdateBSS(1);
                }
            }
            Button {
                id: button10
                text: qsTr("BSS Gyorsasági")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlUpdateBSS(2);
                }
            }
            Button {
                id: button8
                text: qsTr("BSS Közönség")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlUpdateBSS(0);
                }
            }
            Button {
                id: button11
                text: qsTr("BSS Végeredmény")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controlUnit.qmlUpdateBSS(3);
                }
            }


        }
    }



}
