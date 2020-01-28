import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0

Item {
    id: element
    width: 768
    height: 850

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
        id: pane
        y: 479
        width: 350
        height: 350
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: 30
        color: "#99ffffff"

        GridLayout {
            id: gridLayout
            rows: 4
            columns: 2
            anchors.fill: parent

            Label {
                id: label2
                text: qsTr("Manual Time")
                font.pointSize: 13
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter

            }

            Label {
                id: label3
                text: qsTr("Laser Time")
                font.pointSize: 13
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            }

            Label {
                id: manualTimeLabel
                text: qsTr("1:23.456")
                font.pointSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignBottom
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            }

            Label {
                id: laserTimeLabel
                text: qsTr("1:23.456")
                verticalAlignment: Text.AlignBottom
                font.pointSize: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            }

            Button {
                id: selectManualTimeButton
                text: qsTr("Select")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                onClicked: {
                    controlUnit.qmlManualTimeSelected();
                }
            }

            Button {
                id: selectLaserTimeButton
                text: qsTr("Select")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                onClicked: {
                    controlUnit.qmlLaserTimeSelected();
                }
            }

            Button {
                id: manualMeasureButton
                text: qsTr("Manual Measure")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.columnSpan: 2
                Layout.rowSpan: 1
                onClicked: {
                    controlUnit.qmlManualMeasure();
                }
            }


        }
    }

    Rectangle {
        id: pane1
        x: 43
        width: 300
        height: 300
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.top: parent.top
        anchors.topMargin: 30
        color: "#99ffffff"

        GridLayout {
            id: gridLayout1
            rows: 4
            columns: 2
            anchors.fill: parent

            Button {
                id: safetyCarFollowedButton
                text: qsTr("Safety Car Followed")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.columnSpan: 2
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
                width: 100
                text: qsTr(" 0")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
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
                id: increaseTouchButton
                text: qsTr("Touch +")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onClicked: {
                    controlUnit.qmlIncreaseTouchCount();
                }
            }

            Label {
                id: touchCountLabel
                width: 100
                text: qsTr(" 0")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                Layout.minimumWidth: 100
                fontSizeMode: Text.FixedSize
                font.pointSize: 30
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.rowSpan: 2
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

    RaceActionsContainer{
        id: skillRaceActions
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
    }

    Rectangle {
        id: rectangle
        x: 30
        y: 121
        width: 300
        height: 200
        color: "#99ffffff"

        ColumnLayout {
            id: columnLayout
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.bottomMargin: 10
            anchors.topMargin: 10
            anchors.fill: parent

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
                font.pointSize: 50
                verticalAlignment: Text.AlignBottom
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            }
        }
    }
}



/*##^## Designer {
    D{i:1;anchors_x:36}D{i:10;anchors_width:300;anchors_x:43;anchors_y:32}
}
 ##^##*/
