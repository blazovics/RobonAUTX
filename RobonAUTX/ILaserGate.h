/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef ILASERGATE_H
#define ILASERGATE_H

#include <QObject>

//FIXME put it somewhere else to be more robust
#define Event_LaserTimeReceived 20

class ILaserGate : public QObject {

    Q_OBJECT

signals:
    void LaserMeasure(quint32 time);
};

#endif //_ILASERGATE_H
