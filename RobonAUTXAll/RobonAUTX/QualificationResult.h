/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef QUALIFICATIONRESULT_H
#define QUALIFICATIONRESULT_H

#include "BaseResult.h"


class QualificationResult: public BaseResult {
public: 
    quint32 qualificationPoint;
};

QDataStream &operator<<(QDataStream &, const QualificationResult &);
QDataStream &operator>>(QDataStream &, QualificationResult &);

#endif //_QUALIFICATIONRESULT_H
