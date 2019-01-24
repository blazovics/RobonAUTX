/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SKILLRACEVIEWCONTROLLER_H
#define SKILLRACEVIEWCONTROLLER_H

#include "RaceViewController.h"


class SkillRaceViewController: public RaceViewController {
public: 
    
/**
 * @param team
 */
void InitRace(Team team);
};

#endif //_SKILLRACEVIEWCONTROLLER_H