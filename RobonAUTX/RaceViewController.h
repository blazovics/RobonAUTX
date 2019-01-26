/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef RACEVIEWCONTROLLER_H
#define RACEVIEWCONTROLLER_H

#include <QObject>
#include "RTimer.h"
#include "Team.h"

class RaceViewController : public QObject {

    Q_OBJECT
protected:
    Team selectedTeam;
    RTimer raceTimer;
public:

    explicit RaceViewController(QObject* parent = nullptr);
    virtual ~RaceViewController();
    /**
 * @param team
 */
    virtual void InitRace(Team team) = 0;

    void StartRaceTimer();
    
    /**
 * @param teamName
 * @param teamID
 */

    


signals:
    void teamUpdated(QVariant teamName, QVariant teamID);


};

#endif //_RACEVIEWCONTROLLER_H
