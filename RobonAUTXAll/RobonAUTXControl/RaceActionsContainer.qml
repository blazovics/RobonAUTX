import QtQuick 2.0

RaceActionsContainerForm {

    startRaceButton.onClicked: {
        controlUnit.qmlStartRace();
    }
    abortRaceButton.onClicked: {
        controlUnit.qmlFinishRace(true);
    }
    saveRaceButton.onClicked: {
        controlUnit.qmlFinishRace(false);
    }
}
