import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

Rectangle {

property bool checked: false;

    width: 80
    height: 60
    id: checkpoint_0_button
    Label{
        text: qsTr("Chkpt " + (checkpointID + 1))
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.fill: parent
    }


    property int checkpointID: 0

    color: { if (checked == true)
            return "green"
        else
            return "red"
    }

}
