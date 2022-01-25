/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef CENTRALCONTROLLER_H
#define CENTRALCONTROLLER_H

#include "ICentralController.h"
#include <memory>

#include "DatabaseManager.h"

#include "BSSSocketManager.h"
#include "BSSCommunicator.h"

class RaceEvent;

class CentralController: public ICentralController {

    Q_OBJECT

    std::unique_ptr<RaceEvent> raceEvent;
    std::shared_ptr<DatabaseManager> databaseManager;

    BSSSocketManager bssManager;
    BSSCommunicator *bssCommunicator;

public: 

    
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
   void UpdateTargetCheckpoint(quint32 checkpointID);
   void StartRace();
   void FinishRace(bool aborted);
   void TeamListRequested();
   void VechicleStartAchieved(bool achieved);
   void LaneChangeAchieved(bool achieved);
   void SafetyCarFollowed(bool achieved);
   void SafetyCarOvertaken(quint32 value);
   void ModifyTouchCount(quint32 touchCount);
   void ModifyWrongGateCount(quint32 wrongGateCount);

   void WrongGatePassed();

   void ShowSpeedResults(bool isJunior, quint32 fromPos);
   void ShowSkillResults(quint32 fromPos);
   void ShowFinalResults(bool isJunior, quint32 fromPos);
   void ShowFinalResultAtPosition(bool isJunior, quint32 position);
   void ShowVotesResults(quint32 fromPos);
   void ShowQualificationResults(quint32 fromPos);
   void ShowInterRaceScreen();

   void SkillGateStarted();

   void PauseRaceTimer();
   void ResumeRaceTimer();

   void UpdateBSS(quint32 actionType);

   void saveResultsToFile();

   void saveResultsToHTML();

private slots:
   void bssConnected(bool alive);

private:
   void SaveVoteResultToHTML();
   void SaveFinalResultToHTML();
   void SaveJuniorFinalResultToHTML();

public:
   void SkillRaceTimeout();
};

#endif //_CENTRALCONTROLLER_H
