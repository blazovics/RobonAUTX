/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "Lap.h"
#include <stdexcept>

/**
 * Lap implementation
 */

Lap::Lap()
{
    this->laserTime = 0;
    this->manualTime = 0;
    this->choosenLapType = Undefined;
    this->isWarmUp = false;
}

quint32 Lap::GetChoosenLapTime()
{
    switch (choosenLapType) {
        case TimeSourceType::LaserTime:
        if(laserTime == 0)
        {
            //throw std::domain_error("Choosen Laser Time not valid");
        }
        return laserTime;
    case TimeSourceType::ManualTime:
        if(manualTime == 0)
        {
            //throw std::domain_error("Choosen Manual Time not valid");
        }
        return  manualTime;
    case TimeSourceType::Undefined:
        //throw std::domain_error("No existing choosen laptime");
        break;
    }
}
