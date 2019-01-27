/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef RACECONTROLUNIT_H
#define RACECONTROLUNIT_H

#include "IRaceControlUnit.h"
#include <QObject>

#include "MainViewcontroller.h"
#include "SkillRaceViewController.h"
#include "SpeedRaceViewController.h"
#include "ResultViewController.h"

class RaceControlUnit: public QObject, public IRaceControlUnit {

    Q_OBJECT

    MainViewcontroller mainViewController;
    SkillRaceViewController skillRaceViewController;
    SpeedRaceViewController speedRaceViewController;
    ResultViewController resultViewController;
    QList<Team> teams;
    
public:
    explicit RaceControlUnit(QObject* parent = nullptr);

    virtual ~RaceControlUnit();

    /**
    * Should raise exception when the teamID is not valid.
    * @param teamID
    */
    Team getTeamForID(quint32 teamID);
};

#endif //_RACECONTROLUNIT_H
