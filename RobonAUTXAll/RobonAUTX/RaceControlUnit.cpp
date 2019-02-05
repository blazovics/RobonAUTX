/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RaceControlUnit.h"
//FIXME: just for time formatting
#include "SpeedRaceResult.h"
#include <math.h>
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
    teamModel.removeAll();

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
    touchCount = 0;
    emit showSpeedRaceView(teamID);
}

void RaceControlUnit::raceStarted()
{
    if(eventType == Skill)
    {
        raceTimer.StartTimer();
    }
    else if(eventType == Speed){
        this->speedRaceTimer.start();
        speedTimeOffset = 0;
    }
    updateTimer->start(10);
}

void RaceControlUnit::RaceFinished(bool aborted)
{
    if(eventType == Skill)
    {
        raceTimer.StopTimer();

    }
    if(eventType == Speed)
    {
        this->speedRaceTimer.invalidate();
        emit showMainView();
    }

    updateTimer->stop();
}

void RaceControlUnit::LaserLapTimeUpdated(quint32 time)
{
    emit updateLaserLapTime(SpeedRaceResult::SpeedTimeToString(time));
}

void RaceControlUnit::ManualLapTimeUpdated(quint32 time)
{
    emit updateManualLapTime(SpeedRaceResult::SpeedTimeToString(time));
}

void RaceControlUnit::SpeedLapCompleted(quint32 lapNumber, quint32 lapTime)
{
    speedTimeOffset += lapTime;
    emit updateCompletedSpeedLaps(lapNumber,lapTime);
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
    emit updateSafetyCarFollowingConfirmedButton(achieved);
}

void RaceControlUnit::SafetyCarOvertakeConfirmed(bool achieved)
{
    emit updateSafetyCarOvertakenConfirmedButton(achieved);
}

void RaceControlUnit::TouchCountModified(quint32 numberOfTouches)
{
    emit updateTouchCountModified(numberOfTouches);
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
        qint64 realTimeCredit = timeCredit;
        qint64 elapsedTime = raceTimer.Elapsed();

        qint64 remainingTime = realTimeCredit-elapsedTime;

        if(remainingTime > 0)
        {
             emit updateRemainingTime(SpeedRaceResult::SpeedTimeToString(quint32(remainingTime)));
        }
        else {
            emit updateRemainingTime("-" + SpeedRaceResult::SpeedTimeToString(quint32(abs(remainingTime))));
        }


        emit updateRaceTime(SpeedRaceResult::SpeedTimeToString(raceTimer.Elapsed()));
    }
    else if(eventType == Speed)
    {
        emit updateRaceTime(SpeedRaceResult::SpeedTimeToString(speedRaceTimer.elapsed()-speedTimeOffset));
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

void RaceControlUnit::qmlManualTimeSelected()
{
    emit SelectTimeSourceForLap(ManualTime);
}

void RaceControlUnit::qmlLaserTimeSelected()
{
    emit SelectTimeSourceForLap(LaserTime);
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

void RaceControlUnit::qmlIncreaseTouchCount()
{
    if(touchCount < 5)
    {
        touchCount++;
    }
    emit ModifyTouchCount(touchCount);
}

void RaceControlUnit::qmlDecreaseTouchCount()
{
    if(touchCount > 0)
    {
        touchCount--;
    }
    emit ModifyTouchCount(touchCount);
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
