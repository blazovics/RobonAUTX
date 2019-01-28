/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef FINALRESULT_H
#define FINALRESULT_H

#include "BaseResult.h"


class FinalResult: public BaseResult {
public: 
    bool isJunior;
    quint32 skillPoint;
    quint32 speedPoint;
    quint32 qualificationPoint;
    quint32 votePoint;
    quint32 finalPoint;
};

QDataStream &operator<<(QDataStream &, const FinalResult &);
QDataStream &operator>>(QDataStream &, FinalResult &);

#endif //_FINALRESULT_H
