import QtQuick 2.0

RaceTimeContainerForm {

    Connections{
        target: controlUnit
        onShowSkillRaceView:{
            manualStartButton.enabled = true;
            pauseTimerButton.enabled = true;
        }
        onUpdateRaceTime:{
            manualStartButton.enabled = false;
        }
    }

    manualStartButton.onClicked: {
        controlUnit.qmlSkillGateManualStarted();
        manualStartButton.enabled = false;
    }

    pauseTimerButton.onClicked: {
        controlUnit.qmlPauseRaceTimer();
        pauseTimerButton.enabled = false;
        resumeTimerButton.enabled = true;
    }
    resumeTimerButton.onClicked: {
        controlUnit.qmlResumeRaceTimer();
        pauseTimerButton.enabled = true;
        resumeTimerButton.enabled = false;
    }

    function resetContainer(){
        manualStartButton.enabled = true;
        pauseTimerButton.enabled = false;
        resumeTimerButton.enabled = false;
        manualTimerToggle.checked = false;
    }
}
