import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Button {
    id: checkpoint_0_button
    text: qsTr("Checkpoint " + checkpointID)
    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
    checkable: true

    property int checkpointID: 0

}
