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

#endif //_QUALIFICATIONRESULT_H