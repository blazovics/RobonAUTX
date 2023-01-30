import QtQuick 2.0

SkillRaceResultsContainerForm {

    function resetContainer(){
        skillRacePointLabel.text = "0";
        elapsedTimeLabel.text = "0";
        remainingTimeLabel.text = "0";
        touchCountLabel.text ="0";
    }

    Connections{
        target: controlUnit
        onUpdateSkillPoint:{
            skillRacePointLabel.text = point;
        }
        onUpdateRemainingTime:{
            remainingTimeLabel.text = time;
        }
        onUpdateRaceTime:{
            elapsedTimeLabel.text = time;
        }
        onUpdateTouchCountModified:{
            touchCountLabel.text = numberOfTouches;
        }

    }
}
