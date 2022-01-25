import QtQuick 2.0

SkillRaceResultsContainerForm {

    function resetContainer(){
        skillRacePointLabel.text = "0";
        elapsedTimeLabel.text = "0";
        remainingTimeLabel.text = "0";
        wrongGateCountLabel.text ="0";
    }

    Connections{
        target: controlUnit
        onUpdateSkillPoint:{
            skillRacePointLabel.text = point;
        }
        onUpdateWrongGateCountModified:{
            wrongGateCountLabel.text = numberOfWrongGates;
        }
        onUpdateRaceTime:{
            elapsedTimeLabel.text = time;
        }
        onUpdateRemainingTime:{
            remainingTimeLabel.text = time;
        }

    }
}
