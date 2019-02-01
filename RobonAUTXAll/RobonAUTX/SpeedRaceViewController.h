/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SPEEDRACEVIEWCONTROLLER_H
#define SPEEDRACEVIEWCONTROLLER_H

#include "RaceViewController.h"


class SpeedRaceViewController: public RaceViewController {
public: 
    
/**
 * @param team
 */
void InitRace(Team team);
};

#endif //_SPEEDRACEVIEWCONTROLLER_H