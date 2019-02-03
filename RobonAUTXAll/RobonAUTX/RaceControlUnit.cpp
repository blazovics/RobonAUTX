/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RaceControlUnit.h"
//FIXME: just for time formatting
#include "SpeedRaceResult.h"
/**
 * RaceControlUnit implementation
 */


/**
 * Should raie exception when the teamID is not valid.
 * @param teamID
 * @return Team
 */

TeamModel *RaceControlUnit::getTeamModel()
{
    return &teamModel;
}

RaceControlUnit::RaceControlUnit()
{
    updateTimer = std::make_unique<QTimer>();
    connect(updateTimer.get(),SIGNAL(timeout()),this,SLOT(TimerFired()));
}

RaceControlUnit::~RaceControlUnit()
{

}

void RaceControlUnit::TeamListUpdated(QList<Team> teams)
{
    //teamModel.removeAll();

    for (int i = 0; i < teams.size(); i++) {
        teamModel.addTeam(teams[i]);
    }
}

void RaceControlUnit::SkillRaceInitiated(quint32 teamID)
{
    eventType = Skill;
    emit showSkillRaceView(teamID);
}

void RaceControlUnit::SpeedRaceInitiated(quint32 teamID)
{
    eventType = Speed;
    emit showSpeedRaceView(teamID);
}

void RaceControlUnit::raceStarted()
{
    raceTimer.StartTimer();
    updateTimer.get()->start(10);
}

void RaceControlUnit::RaceFinished(bool aborted)
{
    emit showMainView();
    raceTimer.StopTimer();
}

void RaceControlUnit::LaserLapTimeUpdated(quint32 time)
{

}

void RaceControlUnit::ManualLapTimeUpdated(quint32 time)
{

}

void RaceControlUnit::SpeedLapCompleted(quint32 lapNumber, quint32 lapTime)
{

}

void RaceControlUnit::CheckpointStateUpdated(quint32 checkpointID, bool checked)
{
    emit updateCheckpointButtons(checkpointID,checked);
}

void RaceControlUnit::VehicleStartConfirmed(bool achieved)
{
    emit updateStartSuccessButton(achieved);
}

void RaceControlUnit::LaneChangeConfirmed(bool achieved)
{
    emit updateLaneChangeConfirmedButton(achieved);
}

void RaceControlUnit::SkillPointUpdated(quint32 skillPoint, quint32 timeCredit)
{  
    this->timeCredit = timeCredit;
    emit updateSkillPoint(skillPoint);
}

void RaceControlUnit::SafetyCarFollowingConfirmed(bool achieved)
{

}

void RaceControlUnit::SafetyCarOvertakeConfirmed(bool achieved)
{

}

void RaceControlUnit::TouchCountModified(quint32 numberOfTouches)
{

}

void RaceControlUnit::RaceTimerPaused()
{
    raceTimer.PauseTimer();
}

void RaceControlUnit::RaceTimerResumed()
{
    raceTimer.ResumeTimer();
}

void RaceControlUnit::TimerFired()
{
    if(eventType == Skill)
    {


        emit updateRemainingTime(SpeedRaceResult::SpeedTimeToString(timeCredit - quint32(raceTimer.Elapsed())));
        emit updateRaceTime(SpeedRaceResult::SpeedTimeToString(raceTimer.Elapsed()));
    }
}

void RaceControlUnit::qmlGetTeamList()
{
    emit getTeamList();
}
void RaceControlUnit::qmlInitSkillRace(quint32 teamID)
{
    emit InitSkillRace(teamID);
}
void RaceControlUnit::qmlInitSpeedRace(quint32 teamID)
{
    emit InitSpeedRace(teamID);
}
void RaceControlUnit::qmlStartRace()
{
    emit startRace();
}
void RaceControlUnit::qmlFinishRace(bool aborted)
{
    emit FinishRace(aborted);
}
void RaceControlUnit::qmlManualMeasure()
{
    emit manualMeasure();
}
void RaceControlUnit::qmlSelectTimeSourceForLap(TimeSourceType timeSource)
{
    emit SelectTimeSourceForLap(timeSource);
}
void RaceControlUnit::qmlUpdateCheckpointState(quint32 checkpointID, bool checked, bool forced)
{
    emit updateCheckpointState(checkpointID,checked,forced);
}
void RaceControlUnit::qmlVehicleStarted(bool achieved)
{
    emit VehicleStarted(achieved);
}
void RaceControlUnit::qmlLaneChanged(bool achieved)
{
    emit LaneChanged(achieved);
}
void RaceControlUnit::qmlSafetyCarFollowed(bool achieved)
{
    emit SafetyCarFollowed(achieved);
}
void RaceControlUnit::qmlSafetyCarOvertaken(bool achieved)
{
    emit SafetyCarOvertaken(achieved);
}
void RaceControlUnit::qmlModifyTouchCount(quint32 numberOfTouches)
{
    emit ModifyTouchCount(numberOfTouches);
}

void RaceControlUnit::qmlPauseRaceTimer()
{
    emit PauseRaceTimer();
}

void RaceControlUnit::qmlResumeRaceTimer()
{
    emit ResumeRaceTimer();
}

void RaceControlUnit::qmlShowSpeedResults(bool isJunior, quint32 fromPos)
{
    emit ShowSpeedResults(isJunior,fromPos);
}
void RaceControlUnit::qmlShowSkillResults(quint32 fromPos)
{
    emit ShowSkillResults(fromPos);
}
void RaceControlUnit::qmlShowFinalResults(bool isJunior, quint32 fromPos)
{
    emit ShowFinalResults(isJunior,fromPos);
}
void RaceControlUnit::qmlShowFinalResultAtPosition(bool isJunior, quint32 position)
{
    emit ShowFinalResultAtPosition(isJunior,position);
}
void RaceControlUnit::qmlShowVotesResults(quint32 fromPos)
{
    emit ShowVotesResults(fromPos);
}
void RaceControlUnit::qmlShowQualificationResults(quint32 fromPos)
{
    emit ShowQualificationResults(fromPos);
}
void RaceControlUnit::qmlShowInterRaceScreen()
{
    emit ShowInterRaceScreen();
}

void RaceControlUnit::qmlSkillGateManualStarted()
{
    emit SkillGateManualStarted();
}
