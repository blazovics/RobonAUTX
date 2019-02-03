import QtQuick 2.0

RaceTimeContainerForm {
    manualStartButton.onClicked: {
        controlUnit.qmlSkillGateManualStarted();
    }

    pauseTimerButton.onClicked: {
        controlUnit.qmlPauseRaceTimer();
    }
    resumeTimerButton.onClicked: {
        controlUnit.qmlResumeRaceTimer();
    }
}
