/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef IDISPLAYMANAGER_H
#define IDISPLAYMANAGER_H

#include <QObject>
#include "Team.h"

class IDisplayManager {
public: 
    
    virtual ~IDisplayManager() = 0;
    /**
 * @param isJunior
 * @param fromPos
 */
    virtual void showSpeedResults(bool isJunior, quint32 fromPos) = 0;
    
    /**
 * @param fromPos
 */
    virtual void showSkillResults(quint32 fromPos) = 0;
    
    /**
 * @param isJunior
 * @param fromPos
 */
    virtual void showFinalResults(bool isJunior, quint32 fromPos) = 0;
    
    /**
 * @param isJunior
 * @param position
 */
    virtual void showFinalResultAtPosition(bool isJunior, quint32 position) = 0;
    
    /**
 * @param fromPos
 */
    virtual void showVotesResults(quint32 fromPos) = 0;
    
    virtual void showInterRaceScreen() = 0;
    
    virtual void SkillRaceInitiated() = 0;
    
    virtual void SpeedRaceInitiated() = 0;
    
    virtual void StartTimer() = 0;
    
    /**
 * @param value
 */
    virtual void SetTimerValue(quint32 value) = 0;
    
    virtual void StopTimer() = 0;
    
    /**
 * @param lapNumber
 * @param lapTime
 */
    virtual void SpeedLapCompleted(quint32 lapNumber, quint32 lapTime) = 0;
    
    /**
 * @param skillPoint
 */
    virtual void SkillPointUpdated(quint32 skillPoint) = 0;
    
    /**
 * @param teams
 */
    virtual void TeamListUpdated(QList<Team> teams) = 0;
    
    /**
 * @param teamID
 */
    virtual void TeamSelected(quint32 teamID) = 0;
};

#endif //_IDISPLAYMANAGER_H
