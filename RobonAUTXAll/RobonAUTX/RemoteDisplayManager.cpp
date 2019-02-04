/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RemoteDisplayManager.h"

/**
 * RemoteDisplayManager implementation
 */

RemoteDisplayManager::RemoteDisplayManager(CoreController *parentController, QTcpSocket *socket, QIODevice::OpenMode mode):RemoteDevice (parentController,socket,mode)
{

}

RemoteDisplayManager::~RemoteDisplayManager()
{

}



DisplayManager *RemoteDisplayManager::getLocalManager() const
{
    return localManager;
}

void RemoteDisplayManager::setLocalManager(DisplayManager *value)
{
    localManager = value;
}

void RemoteDisplayManager::EventReceived(Event &event)
{
    switch (event.getEventID()) {
    case Device_IDisplayManager + Event_showSpeedResults :
    {
        QList<SpeedRaceResult> result = event.extractSpeedRaceResultsFromRawData();
        bool isJunior = event.extractBoolFromRawData();
        quint32 fromPos = event.extractQuint32FromRawData();

        localManager->showSpeedResults(result,isJunior,fromPos);
    }
        break;
    case Device_IDisplayManager + Event_showSkillResults :
    {
        QList<SkillRaceResult> result = event.extractSkillRaceResultFromRawData();
        quint32 fromPos = event.extractQuint32FromRawData();

        localManager->showSkillResults(result,fromPos);
    }
        break;
    case Device_IDisplayManager + Event_showFinalResults :
    {
        QList<FinalResult> result = event.extractFinalResultsFromRawData();
        bool isJunior = event.extractBoolFromRawData();
        quint32 fromPos = event.extractQuint32FromRawData();

        localManager->showFinalResults(result,isJunior,fromPos);
    }
        break;
    case Device_IDisplayManager + Event_showFinalResultAtPosition :
    {
        QList<FinalResult> result = event.extractFinalResultsFromRawData();
        bool isJunior = event.extractBoolFromRawData();
        quint32 position = event.extractQuint32FromRawData();

        localManager->showFinalResultAtPosition(result,isJunior,position);
    }
        break;
    case Device_IDisplayManager + Event_showVotesResults :
    {
        QList<VoteResult> result = event.extractVoteResultsFromRawData();
        quint32 fromPos = event.extractQuint32FromRawData();

        localManager->showVotesResults(result,fromPos);
    }
        break;
    case Device_IDisplayManager + Event_showQualificationResults :
    {
        QList<QualificationResult> result = event.extractQualificationResultsFromRawData();
        quint32 fromPos = event.extractQuint32FromRawData();

        localManager->showQualificationResults(result,fromPos);
    }
        break;
    case Device_IDisplayManager + Event_showInterRaceScreen :
        localManager->showInterRaceScreen();
        break;
    case Device_IDisplayManager + Event_SkillRaceInitiated :
        localManager->SkillRaceInitiated(event.extractQuint32FromRawData());
        break;
    case Device_IDisplayManager + Event_SpeedRaceInitiated :
        localManager->SpeedRaceInitiated(event.extractQuint32FromRawData());
        break;
    case Device_IDisplayManager + Event_LaneChangeAchieved :
        localManager->LaneChangeAchieved(event.extractBoolFromRawData());
        break;
    case Device_IDisplayManager + Event_VehicleStartAchieved :
        localManager->VehicleStartAchieved(event.extractBoolFromRawData());
        break;
    case Device_IDisplayManager + Event_SafetyCarFollowed :
        localManager->SafetyCarFollowed(event.extractBoolFromRawData());
        break;
    case Device_IDisplayManager + Event_SafetyCarOvertaken :
        localManager->SafetyCarOvertaken(event.extractBoolFromRawData());
        break;
    case Device_IDisplayManager + Event_CheckpointStateUpdated :
    {
       quint32 checkpointID = event.extractQuint32FromRawData();
       bool state = event.extractBoolFromRawData();

       localManager->CheckpointStateUpdated(checkpointID,state);
    }
        break;
    case Device_IDisplayManager + Event_SpeedLapCompleted :
    {
        quint32 lapNumber = event.extractQuint32FromRawData();
        quint32 lapTime = event.extractQuint32FromRawData();

        localManager->SpeedLapCompleted(lapNumber,lapTime);
    }
        break;
    case Device_IDisplayManager + Event_SkillPointUpdated :
    {
        quint32 skillPoint = event.extractQuint32FromRawData();
        quint32 timeCredit = event.extractQuint32FromRawData();

        localManager->SkillPointUpdated(skillPoint,timeCredit);
    }
        break;
    case Device_IDisplayManager + Event_TeamListUpdated :
    {
        localManager->TeamListUpdated(event.extractTeamsFromRawData());
    }
        break;
    }
}


void RemoteDisplayManager::showSpeedResults(QList<SpeedRaceResult> result, bool isJunior, quint32 fromPos)
{
    Event event(Device_IDisplayManager + Event_showSpeedResults);
    event.insertSpeedRaceResults(result);
    event.insertBool(isJunior);
    event.insertQuint32(fromPos);
    sendEvent(event);
}

void RemoteDisplayManager::showSkillResults(QList<SkillRaceResult> result, quint32 fromPos)
{
    Event event(Device_IDisplayManager +  Event_showSkillResults );
    event.insertSkillRaceResults(result);
    event.insertQuint32(fromPos);
    sendEvent(event);

}

void RemoteDisplayManager::showFinalResults(QList<FinalResult> result, bool isJunior, quint32 fromPos)
{
    Event event(Device_IDisplayManager +  Event_showFinalResults );
    event.insertFinalResults(result);
    event.insertBool(isJunior);
    event.insertQuint32(fromPos);
    sendEvent(event);

}

void RemoteDisplayManager::showFinalResultAtPosition(QList<FinalResult> result, bool isJunior, quint32 position)
{
    Event event(Device_IDisplayManager +  Event_showFinalResultAtPosition );
    event.insertFinalResults(result);
    event.insertBool(isJunior);
    event.insertQuint32(position);
    sendEvent(event);

}

void RemoteDisplayManager::showVotesResults(QList<VoteResult> result, quint32 fromPos)
{
    Event event(Device_IDisplayManager +  Event_showVotesResults );
    event.insertVoteResults(result);
    event.insertQuint32(fromPos);
    sendEvent(event);

}

void RemoteDisplayManager::showQualificationResults(QList<QualificationResult> result, quint32 fromPos)
{
    Event event(Device_IDisplayManager +  Event_showQualificationResults );
    event.insertQualificationResuls(result);
    event.insertQuint32(fromPos);
    sendEvent(event);

}

void RemoteDisplayManager::LaneChangeAchieved(bool success)
{
    Event event(Device_IDisplayManager +  Event_LaneChangeAchieved );
    event.insertBool(success);
    sendEvent(event);

}

void RemoteDisplayManager::VehicleStartAchieved(bool success)
{
    Event event(Device_IDisplayManager +  Event_VehicleStartAchieved );
    event.insertBool(success);
    sendEvent(event);

}

void RemoteDisplayManager::SafetyCarFollowed(bool success)
{
    Event event(Device_IDisplayManager +  Event_SafetyCarFollowed );
    event.insertBool(success);
    sendEvent(event);

}

void RemoteDisplayManager::SafetyCarOvertaken(bool success)
{
    Event event(Device_IDisplayManager +  Event_SafetyCarOvertaken );
    event.insertBool(success);
    sendEvent(event);

}

void RemoteDisplayManager::CheckpointStateUpdated(quint32 checkpointID, bool state)
{
    Event event(Device_IDisplayManager +  Event_CheckpointStateUpdated );
    event.insertQuint32(checkpointID);
    event.insertBool(state);
    sendEvent(event);

}

void RemoteDisplayManager::showInterRaceScreen()
{
    Event event(Device_IDisplayManager +  Event_showInterRaceScreen );
    sendEvent(event);

}

void RemoteDisplayManager::SkillRaceInitiated(quint32 teamID)
{
    Event event(Device_IDisplayManager +  Event_SkillRaceInitiated );
    event.insertQuint32(teamID);
    sendEvent(event);

}

void RemoteDisplayManager::SpeedRaceInitiated(quint32 teamID)
{
    Event event(Device_IDisplayManager +  Event_SpeedRaceInitiated );
    event.insertQuint32(teamID);
    sendEvent(event);

}



void RemoteDisplayManager::SpeedLapCompleted(quint32 lapNumber, quint32 lapTime)
{
    Event event(Device_IDisplayManager +  Event_SpeedLapCompleted );
    event.insertQuint32(lapNumber);
    event.insertQuint32(lapTime);
    sendEvent(event);

}

void RemoteDisplayManager::SkillPointUpdated(quint32 skillPoint, quint32 timeCredit)
{
    Event event(Device_IDisplayManager +  Event_SkillPointUpdated );
    event.insertQuint32(skillPoint);
    event.insertQuint32(timeCredit);
    sendEvent(event);

}

void RemoteDisplayManager::TeamListUpdated(QList<Team> teams)
{
    Event event(Device_IDisplayManager +  Event_TeamListUpdated );
    event.insertTeams(teams);
    sendEvent(event);

}
