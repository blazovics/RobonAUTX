/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "Lap.h"

/**
 * Lap implementation
 */

quint32 Lap::GetChoosenLapTime()
{
    switch (choosenLapType) {
        case TimeSourceType::laserTime:
        return laserTime;
    case TimeSourceType::manualTime:
        return  manualTime;
    }
}
