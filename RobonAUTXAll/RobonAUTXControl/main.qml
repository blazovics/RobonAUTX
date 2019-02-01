import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 600
    height: 800
    title: qsTr("Hello World")
    
    SwipeView {
        id: view
        anchors.fill: parent
        
        SkillRaceControlPage {

        }
        Page {
            title: qsTr("Discover")
        }
        Page {
            title: qsTr("Activity")
        }
    }
}
