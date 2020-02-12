/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "DisplayManager.h"

/**
 * DisplayManager implementation
 */



QualificationResultModel* DisplayManager::getQualificationResult()
{
    return &qualificationResult;
}

SkillRaceResultModel* DisplayManager::getSkillRaceResult()
{
    return &skillRaceResult;
}

SpeedRaceResultModel* DisplayManager::getSpeedRaceResult()
{
    return &speedRaceResult;
}

VoteResultModel *DisplayManager::getVoteResult()
{
    return &voteResult;
}

FinalResultModel* DisplayManager::getFinalResult()
{
    return &finalResult;
}

SpeedRaceResultModel *DisplayManager::getInRaceSpeedResult()
{
    return &inRaceSpeedResult;
}

DisplayManager::DisplayManager()
{
    m_teamID = 0;
    updateTimer = std::make_unique<QTimer>();
    connect(updateTimer.get(),SIGNAL(timeout()),this,SLOT(TimerFired()));
}

DisplayManager::~DisplayManager()
{

}

void DisplayManager::showSpeedResults(QList<SpeedRaceResult> result, bool isJunior, quint32 fromPos)
{
    speedRaceResult.removeAll();

    if(int(fromPos) < result.size())
    {
        int ifromPos = int(fromPos);
        for (int i = ifromPos; i < result.size(); i++) {
            speedRaceResult.addSpeedRaceResult(result[i]);
        }
    }
    emit presentSpeedResults(isJunior);
}

void DisplayManager::showSkillResults(QList<SkillRaceResult> result, quint32 fromPos)
{
    skillRaceResult.removeAll();

    if(int(fromPos) < result.size())
    {
        int ifromPos = int(fromPos);
        for (int i = ifromPos; i < result.size(); i++) {
            skillRaceResult.addSkillRaceResult(result[i]);
        }
    }
    emit presentSkillResults();
}

void DisplayManager::showFinalResults(QList<FinalResult> result, bool isJunior, quint32 fromPos)
{
    finalResult.removeAll();

    if(int(fromPos) < result.size())
    {
        int ifromPos = int(fromPos);
        for (int i = ifromPos; i < result.size(); i++) {
            finalResult.addFinalResult(result[i]);
        }
    }
    emit presentFinalResults(isJunior);
}

void DisplayManager::showFinalResultAtPosition(QList<FinalResult> result, bool isJunior, quint32 position)
{
    if(position < quint32(result.size())){
        FinalResult res = result[int(position)];

        emit presentFinalResultAtPosition(res.teamID, res.skillPoint,res.speedPoint,res.votePoint,res.qualificationPoint,res.finalPoint,res.position,res.teamName);

    }

}

void DisplayManager::showVotesResults(QList<VoteResult> result, quint32 fromPos)
{
    voteResult.removeAll();

    if(int(fromPos) < result.size())
    {
        int ifromPos = int(fromPos);
        for (int i = ifromPos; i < result.size(); i++) {
            voteResult.addVoteResult(result[i]);
        }
    }
    emit presentVotesResults();
}

void DisplayManager::showQualificationResults(QList<QualificationResult> result, quint32 fromPos)
{
    qualificationResult.removeAll();

    if(int(fromPos) < result.size())
    {
        int ifromPos = int(fromPos);
        for (int i = ifromPos; i < result.size(); i++) {
            qualificationResult.addQualificationResult(result[i]);
        }
    }

    emit presentQualificationResults();
}

void DisplayManager::showInterRaceScreen()
{

}

void DisplayManager::SkillRaceInitiated(quint32 teamID)
{
    eventType = Skill;
    this->m_teamID = teamID;
    emit teamIDChanged(teamID);
    timeCredit = 0;

    emit presentSkillRace();
}

void DisplayManager::SpeedRaceInitiated(quint32 teamID)
{
    eventType = Speed;
    this->m_teamID = teamID;
    this->setProperty("teamID",QVariant(teamID));
    emit teamIDChanged(teamID);
    speedTimeOffset = 0;

    emit presentSpeedRace();
}

void DisplayManager::LaneChangeAchieved(bool success)
{
    emit sendLaneChangeAchieved(success);
}

void DisplayManager::VehicleStartAchieved(bool success)
{
    emit sendVehicleStartAchieved(success);
}

void DisplayManager::SafetyCarFollowed(bool success)
{
    emit sendSafetyCarFollowed(success);
}

void DisplayManager::SafetyCarOvertaken(quint32 value)
{
    emit sendSafetyCarOvertaken(value);
}

void DisplayManager::CheckpointStateUpdated(quint32 checkpointID, bool state)
{
    emit sendCheckpointStateUpdated(checkpointID,state);
}

void DisplayManager::SpeedLapCompleted(quint32 lapNumber, quint32 lapTime)
{
    speedTimeOffset += lapTime;
    emit sendSpeedLapCompleted(lapNumber,SpeedRaceResult::SpeedTimeToString(lapTime));
}

void DisplayManager::SkillPointUpdated(quint32 skillPoint, quint32 timeCredit)
{
    this->timeCredit = timeCredit;
    emit sendSkillPointUpdated(skillPoint);
}

void DisplayManager::TeamListUpdated(QList<Team> teams)
{
    //?
}

void DisplayManager::SkillRacePaused()
{
    if(eventType == Skill)
    {
        raceTimer.PauseTimer();
    }
}

void DisplayManager::SkillRaceResumed()
{
    if(eventType == Skill)
    {
        raceTimer.ResumeTimer();
    }
}

void DisplayManager::RaceStarted()
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

void DisplayManager::RaceFinished(bool aborted)
{
    if(eventType == Skill)
    {
        raceTimer.StopTimer();

    }
    if(eventType == Speed)
    {
        this->speedRaceTimer.invalidate();
    }

    updateTimer->stop();
}

void DisplayManager::updateInRaceSpeedResults(QList<SpeedRaceResult> result)
{
    inRaceSpeedResult.removeAll();

    for (int ifromPos = 0; ifromPos < result.size() && ifromPos < 4; ifromPos++) {
        inRaceSpeedResult.addSpeedRaceResult(result[ifromPos]);
    }
}

void DisplayManager::TimerFired()
{
    if(eventType == Skill)
    {
        qint64 realTimeCredit = timeCredit;
        qint64 elapsedTime = raceTimer.Elapsed();

        qint64 remainingTime = realTimeCredit-elapsedTime;

        if(remainingTime > 0)
        {
             emit sendRemainingTime(SpeedRaceResult::SkillTimeToString(quint32(remainingTime)));
        }
        else {
            emit sendRemainingTime("-" + SpeedRaceResult::SkillTimeToString(quint32(abs(remainingTime))));
        }
    }
    else if(eventType == Speed)
    {
        emit sendSpeedRaceTime(SpeedRaceResult::SpeedTimeToString(speedRaceTimer.elapsed()-speedTimeOffset));
    }
}

