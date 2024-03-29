/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef BASERESULT_H
#define BASERESULT_H

#include <QObject>

class BaseResult {
public: 
    quint32 teamID;
    quint32 position;
    QString teamName;
};

#endif //_BASERESULT_H
