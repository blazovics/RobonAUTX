/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef VOTERESULT_H
#define VOTERESULT_H

#include "BaseResult.h"


class VoteResult: public BaseResult {
public: 
    quint32 voteCount;
    quint32 votePoint;
};

QDataStream &operator<<(QDataStream &, const VoteResult &);
QDataStream &operator>>(QDataStream &, VoteResult &);

#endif //_VOTERESULT_H
