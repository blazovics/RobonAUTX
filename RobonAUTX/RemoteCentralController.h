/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTECENTRALCONTROLLER_H
#define REMOTECENTRALCONTROLLER_H

#include "ICentralController.h"
#include "RemoteDevice.h"


class RemoteCentralController: public ICentralController, public RemoteDevice {

public:
    virtual ~RemoteCentralController();

public slots:
    void InitSkillRace(quint32 teamID);
    void InitSpeedRace(quint32 teamID);
    void UpdateVotesForTeam(quint32 teamID, quint32 voteCount);
    void ManualMeasureReceived();
    void LaserMeasureReceived();
    void TimeSourceForLapSelected(TimeSourceType timeSource);
    void UpdateCheckpointState(quint32 checkpointID, bool checked, bool forced);
    void StartRace();
    void FinishRace(bool aborted);
    void TeamListRequested();
    void VechicleStartAchieved(bool achieved);
    void LaneChangeAchieved(bool achieved);
    void SafetyCarFollowed(bool achieved);
    void SafetyCarOvertaken(bool achieved);
    void ModifyTouchCount(quint32 touchCount);

};

#endif //_REMOTECENTRALCONTROLLER_H
