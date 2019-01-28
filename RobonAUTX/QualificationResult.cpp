/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "QualificationResult.h"
#include <QDataStream>

QDataStream &operator<<(QDataStream &out, const QualificationResult &res)
{
    out<<res.teamID;
    out<<res.position;
    out<<res.qualificationPoint;

    return out;
}


QDataStream &operator>>(QDataStream &in, QualificationResult &res)
{
    in >> res.teamID;
    in >> res.position;
    in >> res.qualificationPoint;

    return in;
}
