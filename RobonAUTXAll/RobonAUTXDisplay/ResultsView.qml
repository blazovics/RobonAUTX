import QtQuick 2.0

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
}
