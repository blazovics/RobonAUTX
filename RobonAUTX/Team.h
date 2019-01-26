/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef TEAM_H
#define TEAM_H

#include "DBRecord.h"


class Team: public DBRecord {
private:
    QString name;
    quint32 teamID;
    quint32 audiencePoint;
    quint32 qualificationPoint;
    bool isJunior;
public:
    Team();
    Team(QByteArray data);
    
    QByteArray serialize();
};

#endif //_TEAM_H
