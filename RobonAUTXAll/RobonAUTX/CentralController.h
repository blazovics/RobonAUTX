/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef CENTRALCONTROLLER_H
#define CENTRALCONTROLLER_H

#include "ICentralController.h"
#include <memory>
#include "RaceEvent.h"
#include "DatabaseManager.h"

class CentralController: public ICentralController {

    Q_OBJECT

public: 
    std::unique_ptr<RaceEvent> raceEvent;
    std::shared_ptr<DatabaseManager> databaseManager;
    
   CentralController();

   virtual ~CentralController();

signals:

public slots:
   void InitSkillRace(quint32 teamID);
   void InitSpeedRace(quint32 teamID);
   void UpdateVotesForTeam(quint32 teamID, quint32 voteCount);
   void ManualMeasureReceived();
   void LaserMeasureReceived(quint32 time);
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

   void ShowSpeedResults(bool isJunior, quint32 fromPos);
   void ShowSkillResults(quint32 fromPos);
   void ShowFinalResults(bool isJunior, quint32 fromPos);
   void ShowFinalResultAtPosition(bool isJunior, quint32 position);
   void ShowVotesResults(quint32 fromPos);
   void ShowQualificationResults(quint32 fromPos);
   void ShowInterRaceScreen();

   void SkillGateStarted();
};

#endif //_CENTRALCONTROLLER_H
