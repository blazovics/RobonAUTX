/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RemoteCentralController.h"

/**
 * RemoteCentralController implementation
 */



CentralController *RemoteCentralController::getLocalController() const
{
    return localController;
}

void RemoteCentralController::setLocalController(CentralController *value)
{
    localController = value;
}

RemoteCentralController::RemoteCentralController(CoreController* parentController, QTcpSocket *socket, QIODevice::OpenMode mode):RemoteDevice (parentController,socket,mode)
{

}

RemoteCentralController::~RemoteCentralController()
{

}

void RemoteCentralController::EventReceived(Event &event)
{

    switch (event.getEventID()) {
    case Device_ICentralController + Event_InitSkillRace:
        localController->InitSkillRace(event.extractQuint32FromRawData());
        break;
    case Device_ICentralController + Event_InitSpeedRace:
        localController->InitSpeedRace(event.extractQuint32FromRawData());
        break;
    case Device_ICentralController + Event_UpdateVotesForTeam:
        {
            quint32 first = event.extractQuint32FromRawData();
            quint32 second = event.extractQuint32FromRawData();
            localController->UpdateVotesForTeam(first,second);
        }
        break;
    case Device_ICentralController + Event_ManualMeasureReceived:
        localController->ManualMeasureReceived();
        break;
    case Device_ICentralController + Event_LaserMeasureReceived:
        localController->LaserMeasureReceived(event.extractQuint32FromRawData());
        break;
    case Device_ICentralController + Event_TimeSourceForLapSelected:
        localController->TimeSourceForLapSelected(TimeSourceType(event.extractQuint32FromRawData()));
        break;
    case Device_ICentralController + Event_UpdateCheckpointState:
    {
        quint32 first = event.extractQuint32FromRawData();
        bool second = event.extractBoolFromRawData();
        bool third = event.extractBoolFromRawData();
        localController->UpdateCheckpointState(first,second,third);
    }
        break;
    case Device_ICentralController + Event_UpdateTargetCheckpoint:
    {
        quint32 first = event.extractQuint32FromRawData();
        localController->UpdateTargetCheckpoint(first);
    }
        break;
    case Device_ICentralController + Event_StartRace:
        localController->StartRace();
        break;
    case Device_ICentralController + Event_FinishRace:
        localController->FinishRace(event.extractBoolFromRawData());
        break;
    case Device_ICentralController + Event_TeamListRequested:
        localController->TeamListRequested();
        break;
    case Device_ICentralController + Event_VechicleStartAchieved:
        localController->VechicleStartAchieved(event.extractBoolFromRawData());
        break;
    case Device_ICentralController + Event_LaneChangeAchieved:
        localController->LaneChangeAchieved(event.extractBoolFromRawData());
        break;
    case Device_ICentralController + Event_SafetyCarFollowed:
        localController->SafetyCarFollowed(event.extractBoolFromRawData());
        break;
    case Device_ICentralController + Event_SafetyCarOvertaken:
    {
        quint32 value = event.extractQuint32FromRawData();
        localController->SafetyCarOvertaken(value);
    }
        break;
    case Device_ICentralController + Event_ModifyTouchCount:
        localController->ModifyTouchCount(event.extractQuint32FromRawData());
        break;

    case Device_ICentralController + Event_ShowSpeedResults:
    {
        quint32 first = event.extractBoolFromRawData();
        quint32 second = event.extractQuint32FromRawData();
        localController->ShowSpeedResults(first,second);
    }
        break;
    case Device_ICentralController + Event_ShowSkillResults:
        localController->ShowSkillResults(event.extractQuint32FromRawData());
        break;
    case Device_ICentralController + Event_ShowFinalResults:
    {
        quint32 first = event.extractBoolFromRawData();
        quint32 second = event.extractQuint32FromRawData();
        localController->ShowFinalResults(first, second);
    }
        break;
    case Device_ICentralController + Event_ShowFinalResultAtPosition:
    {
        quint32 first = event.extractBoolFromRawData();
        quint32 second = event.extractQuint32FromRawData();
        localController->ShowFinalResultAtPosition(first, second);
    }
        break;
    case Device_ICentralController + Event_ShowVotesResults:
        localController->ShowVotesResults(event.extractQuint32FromRawData());
        break;
    case Device_ICentralController + Event_ShowQualificationResults:
        localController->ShowQualificationResults(event.extractQuint32FromRawData());
        break;
    case Device_ICentralController + Event_ShowInterRaceScreen:
        localController->ShowInterRaceScreen();
        break;
    case Device_ICentralController + Event_SkillGateStarted:
        localController->SkillGateStarted();
        break;
    case Device_ICentralController + Event_PauseRaceTimer:
        localController->PauseRaceTimer();
        break;
    case Device_ICentralController + Event_ResumeRaceTimer:
        localController->ResumeRaceTimer();
        break;
    case Device_ICentralController + Event_UpdateBSS:
        localController->UpdateBSS();
    }
}

void RemoteCentralController:: InitSkillRace(quint32 teamID)
{
    Event event(Device_ICentralController + Event_InitSkillRace);
    event.insertQuint32(teamID);
    sendEvent(event);
}

void RemoteCentralController:: InitSpeedRace(quint32 teamID)
{
    Event event(Device_ICentralController + Event_InitSpeedRace);
    event.insertQuint32(teamID);
    sendEvent(event);
}

void RemoteCentralController:: UpdateVotesForTeam(quint32 teamID, quint32 voteCount)
{
    Event event(Device_ICentralController + Event_UpdateVotesForTeam);
    event.insertQuint32(teamID);
    event.insertQuint32(voteCount);
    sendEvent(event);
}

void RemoteCentralController:: ManualMeasureReceived()
{
    Event event(Device_ICentralController + Event_ManualMeasureReceived);
    sendEvent(event);
}

void RemoteCentralController:: LaserMeasureReceived(quint32 time)
{
    Event event(Device_ICentralController + Event_LaserMeasureReceived);
    event.insertQuint32(time);
    sendEvent(event);
}

void RemoteCentralController:: TimeSourceForLapSelected(TimeSourceType timeSource)
{
    Event event(Device_ICentralController + Event_TimeSourceForLapSelected);
    event.insertQuint32(timeSource);
    sendEvent(event);
}

void RemoteCentralController:: UpdateCheckpointState(quint32 checkpointID, bool checked, bool forced)
{
    Event event(Device_ICentralController + Event_UpdateCheckpointState);
    event.insertQuint32(checkpointID);
    event.insertBool(checked);
    event.insertBool(forced);
    sendEvent(event);
}

void RemoteCentralController::UpdateTargetCheckpoint(quint32 checkpointID)
{
    Event event(Device_ICentralController + Event_UpdateTargetCheckpoint);
    event.insertQuint32(checkpointID);
    sendEvent(event);
}

void RemoteCentralController:: StartRace()
{
    Event event(Device_ICentralController + Event_StartRace);
    sendEvent(event);
}

void RemoteCentralController:: FinishRace(bool aborted)
{
    Event event(Device_ICentralController + Event_FinishRace);
    event.insertBool(aborted);
    sendEvent(event);
}

void RemoteCentralController:: TeamListRequested()
{
    Event event(Device_ICentralController + Event_TeamListRequested);
    sendEvent(event);
}

void RemoteCentralController:: VechicleStartAchieved(bool achieved)
{
    Event event(Device_ICentralController + Event_VechicleStartAchieved);
    event.insertBool(achieved);
    sendEvent(event);
}

void RemoteCentralController:: LaneChangeAchieved(bool achieved)
{
    Event event(Device_ICentralController + Event_LaneChangeAchieved);
    event.insertBool(achieved);
    sendEvent(event);
}

void RemoteCentralController:: SafetyCarFollowed(bool achieved)
{
    Event event(Device_ICentralController + Event_SafetyCarFollowed);
    event.insertBool(achieved);
    sendEvent(event);
}

void RemoteCentralController:: SafetyCarOvertaken(quint32 value)
{
    Event event(Device_ICentralController + Event_SafetyCarOvertaken);
    event.insertQuint32(value);
    sendEvent(event);
}

void RemoteCentralController:: ModifyTouchCount(quint32 touchCount)
{
    Event event(Device_ICentralController + Event_ModifyTouchCount);
    event.insertQuint32(touchCount);
    sendEvent(event);
}

void RemoteCentralController::ShowSpeedResults(bool isJunior, quint32 fromPos)
{
    Event event(Device_ICentralController + Event_ShowSpeedResults);
    event.insertBool(isJunior);
    event.insertQuint32(fromPos);
    sendEvent(event);
}

void RemoteCentralController::ShowSkillResults(quint32 fromPos)
{
    Event event(Device_ICentralController + Event_ShowSkillResults);
    event.insertQuint32(fromPos);
    sendEvent(event);
}

void RemoteCentralController::ShowFinalResults(bool isJunior, quint32 fromPos)
{
    Event event(Device_ICentralController + Event_ShowFinalResults);
    event.insertBool(isJunior);
    event.insertQuint32(fromPos);
    sendEvent(event);
}

void RemoteCentralController::ShowFinalResultAtPosition(bool isJunior, quint32 position)
{
    Event event(Device_ICentralController + Event_ShowFinalResultAtPosition);
    event.insertBool(isJunior);
    event.insertQuint32(position);
    sendEvent(event);
}

void RemoteCentralController::ShowVotesResults(quint32 fromPos)
{
    Event event(Device_ICentralController + Event_ShowVotesResults);
    event.insertQuint32(fromPos);
    sendEvent(event);
}

void RemoteCentralController::ShowQualificationResults(quint32 fromPos)
{
    Event event(Device_ICentralController + Event_ShowQualificationResults);
    event.insertQuint32(fromPos);
    sendEvent(event);
}

void RemoteCentralController::ShowInterRaceScreen()
{
    Event event(Device_ICentralController + Event_ShowInterRaceScreen);
    sendEvent(event);
}

void RemoteCentralController::SkillGateStarted()
{
    Event event(Device_ICentralController + Event_SkillGateStarted);
    sendEvent(event);
}

void RemoteCentralController::PauseRaceTimer()
{
    Event event(Device_ICentralController + Event_PauseRaceTimer);
    sendEvent(event);
}

void RemoteCentralController::ResumeRaceTimer()
{
    Event event(Device_ICentralController + Event_ResumeRaceTimer);
    sendEvent(event);
}

void RemoteCentralController::UpdateBSS()
{
    Event event(Device_ICentralController + Event_UpdateBSS);
    sendEvent(event);
}

