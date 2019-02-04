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

    function resetContainer()
    {
        abort_race_toggle.checked = false;
        save_race_toggle.checked = false;
    }
}
