import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: checkpoints_container
    width: 200
    height: 800
    color: "#99ffffff"

    signal checkpointButtonPressed(int checkpointID, bool state);
    signal startSucceededButtonPressed(bool state);
    signal laneChangeSucceededButtonPressed(bool state);


    function resetContainer(){
        startSuccededButton.checked = false;
        laneChangeSuccededButton.checked = false;

        for(var i = 0; i< checkpointList.model.rowCount(); i++ )
        {
            checkpointList.model.setProperty(i,"is_checked",false);
        }
    }

    function updateCheckpoint(checkpointID,state)
    {
        console.log(checkpointID)
        console.log(state)

        checkpointList.model.setProperty(checkpointID,"is_checked",state);
    }

    function updateLaneChangeSucceededButton(state)
    {
        laneChangeSuccededButton.checked = state;
    }

    function updateStartSucceededButton(state)
    {
        startSuccededButton.checked = state;
    }

    Component{
        id: ckeckpointButtonDelegate

        CheckpointButton {
            checked: is_checked
            checkpointID: checkpoint_ID

            onReleased: {
                checkpoints_container.checkpointButtonPressed(checkpointID,checked) ;
                console.log("checked changed")
            }
        }
    }

    ColumnLayout{
        anchors.bottomMargin: 15
        anchors.topMargin: 15
        spacing: 5
        anchors.fill: parent

        Button {
            text: "Star Succeeded"
            id: startSuccededButton
            checkable: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onReleased: {
                checkpoints_container.startSucceededButtonPressed(checked);
            }
        }


        //ListView{
        GridView{
            id:checkpointList
            height: 600
            flow: GridView.FlowTopToBottom
            cellWidth: 100
            cellHeight: 65
            cacheBuffer: 300
            contentHeight: 480
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillHeight: false
            width: 200
            model: CheckpointListModel {}
            delegate: ckeckpointButtonDelegate

        }

        Button {
            text: "Lane Change Succeeded"
            id: laneChangeSuccededButton
            checkable: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onReleased: {
                checkpoints_container.laneChangeSucceededButtonPressed(checked);
            }
        }
    }
}
