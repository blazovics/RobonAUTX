/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef TEAM_H
#define TEAM_H

#include "DBRecord.h"


class Team: public DBRecord  {

    QString name;
    quint32 teamID;
    quint32 audienceVoteCount;
    quint32 qualificationPoint;
    bool isJunior;

public:
    Team();

    QString getName() const;
    void setName(const QString &value);
    quint32 getTeamID() const;
    void setTeamID(const quint32 &value);
    quint32 getQualificationPoint() const;
    void setQualificationPoint(const quint32 &value);
    bool getIsJunior() const;
    void setIsJunior(bool value);
    quint32 getAudienceVoteCount() const;
    void setAudienceVoteCount(const quint32 &value);

    friend QDataStream &operator<<(QDataStream &, const Team &);
    friend QDataStream &operator>>(QDataStream &, Team &);
};

QDataStream &operator<<(QDataStream &, const Team &);
QDataStream &operator>>(QDataStream &, Team &);

#endif //_TEAM_H
