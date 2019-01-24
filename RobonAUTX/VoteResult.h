/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef VOTERESULT_H
#define VOTERESULT_H

#include "DBRecord.h"
#include "BaseResult.h"


class VoteResult: public DBRecord, public BaseResult {
public: 
    quint32 voteCount;
    quint32 votePoint;
};

#endif //_VOTERESULT_H