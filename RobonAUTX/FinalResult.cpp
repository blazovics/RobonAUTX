/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "FinalResult.h"
#include <QDataStream>
/**
 * FinalResult implementation
 */

QDataStream &operator<<(QDataStream &out, const FinalResult &res)
{
    out<<res.teamID;
    out<<res.position;
    out<<res.isJunior;
    out<<res.skillPoint;
    out<<res.speedPoint;
    out<<res.qualificationPoint;
    out<<res.votePoint;
    out<<res.finalPoint;

    return out;
}


QDataStream &operator>>(QDataStream &in, FinalResult &res)
{
    in >> res.teamID;
    in >> res.position;
    in >> res.isJunior;
    in >> res.skillPoint;
    in >> res.speedPoint;
    in >> res.qualificationPoint;
    in >> res.votePoint;
    in >> res.finalPoint;

    return in;
}
