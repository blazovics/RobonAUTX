/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef ILASERGATE_H
#define ILASERGATE_H

#include <QObject>

class ILaserGate : public QObject {

public:
    virtual void LaserMeasure() = 0;
};

#endif //_ILASERGATE_H
