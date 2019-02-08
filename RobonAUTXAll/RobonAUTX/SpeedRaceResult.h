/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SPEEDRACERESULT_H
#define SPEEDRACERESULT_H

#include "BaseResult.h"

#include <QDataStream>

class SpeedRaceResult: public BaseResult {
public: 
    bool isJunior;
    quint32 speedPoint;
    qint64 speedTime;
    
    static QString SpeedTimeToString(qint64 time);
    static QString SkillTimeToString(qint64 time);
};

QDataStream &operator<<(QDataStream &, const SpeedRaceResult &);
QDataStream &operator>>(QDataStream &, SpeedRaceResult &);

#endif //_SPEEDRACERESULT_H
