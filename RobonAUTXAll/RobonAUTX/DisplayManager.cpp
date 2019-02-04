/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "DisplayManager.h"

/**
 * DisplayManager implementation
 */

DisplayManager::DisplayManager()
{

}

DisplayManager::~DisplayManager()
{

}

void DisplayManager::showSpeedResults(QList<SpeedRaceResult> result, bool isJunior, quint32 fromPos)
{

}

void DisplayManager::showSkillResults(QList<SkillRaceResult> result, quint32 fromPos)
{

}

void DisplayManager::showFinalResults(QList<FinalResult> result, bool isJunior, quint32 fromPos)
{

}

void DisplayManager::showFinalResultAtPosition(QList<FinalResult> result, bool isJunior, quint32 position)
{

}

void DisplayManager::showVotesResults(QList<VoteResult> result, quint32 fromPos)
{

}

void DisplayManager::showQualificationResults(QList<QualificationResult> result, quint32 fromPos)
{

}

void DisplayManager::showInterRaceScreen()
{

}

void DisplayManager::SkillRaceInitiated(quint32 teamID)
{

}

void DisplayManager::SpeedRaceInitiated(quint32 teamID)
{

}

void DisplayManager::LaneChangeAchieved(bool success)
{

}

void DisplayManager::VehicleStartAchieved(bool success)
{

}

void DisplayManager::SafetyCarFollowed(bool success)
{

}

void DisplayManager::SafetyCarOvertaken(bool success)
{

}

void DisplayManager::CheckpointStateUpdated(quint32 checkpointID, bool state)
{

}

void DisplayManager::SpeedLapCompleted(quint32 lapNumber, quint32 lapTime)
{

}

void DisplayManager::SkillPointUpdated(quint32 skillPoint, quint32 timeCredit)
{

}

void DisplayManager::TeamListUpdated(QList<Team> teams)
{

}

