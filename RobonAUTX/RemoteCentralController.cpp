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

RemoteCentralController::RemoteCentralController(CoreController* parentController, QTcpSocket *socket):RemoteDevice (parentController,socket)
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
        localController->UpdateVotesForTeam(event.extractQuint32FromRawData(),event.extractQuint32FromRawData());
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
        localController->UpdateCheckpointState(event.extractQuint32FromRawData(),event.extractBoolFromRawData(),event.extractBoolFromRawData());
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
        localController->SafetyCarOvertaken(event.extractBoolFromRawData());
        break;
    case Device_ICentralController + Event_ModifyTouchCount:
        localController->ModifyTouchCount(event.extractQuint32FromRawData());
        break;
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

void RemoteCentralController:: SafetyCarOvertaken(bool achieved)
{
    Event event(Device_ICentralController + Event_SafetyCarOvertaken);
    event.insertBool(achieved);
    sendEvent(event);
}

void RemoteCentralController:: ModifyTouchCount(quint32 touchCount)
{
    Event event(Device_ICentralController + Event_ModifyTouchCount);
    event.insertQuint32(touchCount);
    sendEvent(event);
}

