/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SKILLRACERESULT_H
#define SKILLRACERESULT_H

#include "BaseResult.h"
#include <QDataStream>

class SkillRaceResult: public BaseResult {
public: 
    quint32 skillPoint;
    quint32 wrongGateCount;
};

QDataStream &operator<<(QDataStream &, const SkillRaceResult &);
QDataStream &operator>>(QDataStream &, SkillRaceResult &);

#endif //_SKILLRACERESULT_H
