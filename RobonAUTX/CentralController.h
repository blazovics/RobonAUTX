/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef CENTRALCONTROLLER_H
#define CENTRALCONTROLLER_H

#include "ICentralController.h"
#include "RaceEvent.h"
#include "DatabaseManager.h"

class CentralController: public ICentralController {
public: 
    RaceEvent* raceEvent;
    DatabaseManager* databaseManager;
    
   CentralController();

   virtual ~CentralController();
};

#endif //_CENTRALCONTROLLER_H
