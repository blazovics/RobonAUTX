import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0

Item {
    id: element
    width: 360
    height: 750

    property int overtakeCount: 0;

    function resetPage(){
        safetyCarFollowedButton.checked = false;
        touchCountLabel.text = "0";
        overtakeCountLabel.text = "0";
        laserTimeLabel.text = "0";
        manualTimeLabel.text = "0";
        overtakeCount = 0;
        skillRaceActions.resetContainer();

        safetyCarOvertakeDecreaseButton.enabled = false;
        safetyCarOvertakeIncreaseButton.enabled = true;
    }

    Connections{
        target: controlUnit

        onUpdateSafetyCarFollowingConfirmedButton:{
            //            (bool status);
            safetyCarFollowedButton.checked = status;
        }
        onUpdateSafetyCarOvertakenConfirmedButton:{
            //(bool status);

            overtakeCount = value;

            overtakeCountLabel.text = overtakeCount;

            if(overtakeCount <= 0)
            {
                safetyCarOvertakeDecreaseButton.enabled = false;
            }
            else {
                 safetyCarOvertakeDecreaseButton.enabled = true;
            }

            if(overtakeCount >= 2)
            {
                safetyCarOvertakeIncreaseButton.enabled = false;
            }
            else {
                safetyCarOvertakeIncreaseButton.enabled = true;
            }
        }
        onUpdateTouchCountModified:{
            //(quint32 numberOfTouches);
            touchCountLabel.text = numberOfTouches;
        }
        onUpdateLaserLapTime:{
            //(QString time);
            laserTimeLabel.text = time;
        }
        onUpdateManualLapTime:{
            //(QString time);
            manualTimeLabel.text = time;
        }
        onUpdateCompletedSpeedLaps:{
            //(quint32 lapNumber, quint32 lapTime);
            //FIXME: do it
            manualTimeLabel.text = 0;
            laserTimeLabel.text = 0;
        }
        onUpdateRaceTime:{
            lapTimeLabel.text = time;
        }
    }

    Rectangle {
        id: panel2
        height: 60
        color: "#99ffffff"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        anchors.leftMargin: 0

        RowLayout {
            id: columnLayout
            anchors.fill: parent
            spacing: 10

            Label {
                id: label
                text: qsTr("Time:")
                font.pointSize: 27
                verticalAlignment: Text.AlignBottom
                Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
            }

            Label {
                id: lapTimeLabel
                text: qsTr("00:00.000")
                font.pointSize: 30
                verticalAlignment: Text.AlignBottom
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            }
        }
    }

    RaceActionsContainer{
        id: skillRaceActions
        anchors.right: parent.right
        anchors.top: panel2.bottom
        anchors.leftMargin: 0
        anchors.rightMargin: 0

    }

    Rectangle {
        id: pane1
        height: 170
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: skillRaceActions.bottom
        color: "#99ffffff"

        GridLayout {
            id: gridLayout1
            rows: 4
            columns: 4
            anchors.fill: parent
            anchors.rightMargin: 10
            anchors.leftMargin: 10

            Button {
                id: safetyCarFollowedButton
                text: qsTr("Safety Car Followed")
                Layout.rightMargin: 20
                Layout.leftMargin: 20
                Layout.minimumWidth: 200
                Layout.fillWidth: false
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.columnSpan: 4
                checkable: true
                onReleased: {
                    controlUnit.qmlSafetyCarFollowed(checked);
                }
            }

            Button {
                id: safetyCarOvertakeIncreaseButton
                text: qsTr("Overtaken +")
                Layout.columnSpan: 1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                checkable: false
                onReleased: {
                    controlUnit.qmlSafetyCarOvertaken(overtakeCount + 1);
                }
            }

            Label {
                id: overtakeCountLabel
                width: 44
                text: qsTr(" 0")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                Layout.minimumWidth: 60
                fontSizeMode: Text.FixedSize
                font.pointSize: 30
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.rowSpan: 2
            }





            Button {
                id: increaseTouchButton
                text: qsTr("Touch +")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onClicked: {
                    controlUnit.qmlIncreaseTouchCount();
                }
            }

            Label {
                id: touchCountLabel
                width: 61
                text: qsTr(" 0")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                Layout.minimumWidth: 100
                fontSizeMode: Text.FixedSize
                font.pointSize: 30
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.rowSpan: 2
            }

            Button {
                id: safetyCarOvertakeDecreaseButton
                text: qsTr("Overtaken -")
                Layout.columnSpan: 1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                checkable: false
                onReleased: {
                    controlUnit.qmlSafetyCarOvertaken(overtakeCount - 1);
                }
            }

            Button {
                id: decreaseTouchButton
                text: qsTr("Touch -")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onClicked: {
                    controlUnit.qmlDecreaseTouchCount();
                }
            }

        }
    }

    Rectangle {
        id: pane
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: pane1.bottom
        anchors.margins: 5
        color: "#99ffffff"

        GridLayout {
            id: gridLayout
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 20
            rowSpacing: 25
            rows: 4
            columns: 2
            columnSpacing: 35

            Label {
                id: label2
                text: qsTr("Manual Time")
                font.pointSize: 13
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                verticalAlignment: Text.AlignVCenter
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter

            }

            Label {
                id: label3
                text: qsTr("Laser Time")
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
                font.pointSize: 13
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            }

            Label {
                id: manualTimeLabel
                text: qsTr("1:23.456")
                font.pointSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignBottom
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            }

            Label {
                id: laserTimeLabel
                text: qsTr("1:23.456")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignBottom
                Layout.fillWidth: true
                font.pointSize: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            }

            Button {
                id: selectManualTimeButton
                text: qsTr("Select")
                rightPadding: 18
                leftPadding: 18
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                onClicked: {
                    controlUnit.qmlManualTimeSelected();
                }
            }

            Button {
                id: selectLaserTimeButton
                text: qsTr("Select")
                rightPadding: 28
                leftPadding: 28
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                onClicked: {
                    controlUnit.qmlLaserTimeSelected();
                }
            }

            Button {
                id: manualMeasureButton
                text: qsTr("Manual Measure")
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.columnSpan: 2
                Layout.rowSpan: 1
                onClicked: {
                    controlUnit.qmlManualMeasure();
                }
            }


        }
    }




}





/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}D{i:1}D{i:4}D{i:5}D{i:3}D{i:2}D{i:6}D{i:9}D{i:10}D{i:11}
D{i:12}D{i:13}D{i:14}D{i:15}D{i:8}D{i:7}D{i:18}D{i:19}D{i:20}D{i:21}D{i:22}D{i:23}
D{i:24}D{i:17}D{i:16}
}
##^##*/
