import QtQuick 2.0

SkillRaceResultsContainerForm {

    Connections{
        target: controlUnit
        onUpdateSkillPoint:{
            skillRacePointLabel.text = point;
        }
        onUpdateRaceTime:{
            elapsedTimeLabel.text = time;
        }
        onUpdateRemainingTime:{
            remainingTimeLabel.text = time;
        }

    }
}
