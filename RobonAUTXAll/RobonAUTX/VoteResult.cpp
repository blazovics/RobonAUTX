/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "VoteResult.h"
#include <QDataStream>

/**
 * VoteResult implementation
 */

QDataStream &operator<<(QDataStream &out, const VoteResult &res)
{
    out<<res.teamName;
    out<<res.teamID;
    out<<res.position;
    out<<res.voteCount;
    out<<res.votePoint;

    return out;
}


QDataStream &operator>>(QDataStream &in, VoteResult &res)
{
    in>>res.teamName;
    in >> res.teamID;
    in >> res.position;
    in >> res.voteCount;
    in >> res.votePoint;

    return in;
}
