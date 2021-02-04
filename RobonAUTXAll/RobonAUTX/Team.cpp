/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "Team.h"
#include <QDataStream>

/**
 * Team implementation
 */


/**
 * @return QByteArray
 */
QString Team::getName() const
{
    return name;
}

void Team::setName(const QString &value)
{
    name = value;
}

quint32 Team::getTeamID() const
{
    return teamID;
}

void Team::setTeamID(const quint32 &value)
{
    teamID = value;
}

quint32 Team::getQualificationPoint() const
{
    return qualificationPoint;
}

void Team::setQualificationPoint(const quint32 &value)
{
    qualificationPoint = value;
}

bool Team::getIsJunior() const
{
    return isJunior;
}

void Team::setIsJunior(bool value)
{
    isJunior = value;
}

quint32 Team::getAudienceVoteCount() const
{
    return audienceVoteCount;
}

void Team::setAudienceVoteCount(const quint32 &value)
{
    audienceVoteCount = value;
}

QList<QString> Team::getTeamMembers() const
{
    return teamMembers;
}

void Team::setTeamMembers(const QList<QString> &value)
{
    teamMembers = value;
}

Team::Team()
{
    
}

QDataStream &operator<<(QDataStream &out, const Team &team)
{
    out << team.name;
    out << team.teamID;
    out << team.audienceVoteCount;
    out << team.qualificationPoint;
    out << quint32(team.isJunior);
    out << team.teamMembers;

    return out;
}

QDataStream &operator>>(QDataStream &in, Team &team)
{
    in >> team.name;
    in >> team.teamID;
    in >> team.audienceVoteCount;
    in >> team.qualificationPoint;
    quint32 intIsJunior;
    in >> intIsJunior;
    team.isJunior = bool(intIsJunior);
    in >> team.teamMembers;

    return in;
}
