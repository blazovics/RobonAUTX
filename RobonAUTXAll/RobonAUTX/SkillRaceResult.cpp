/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "SkillRaceResult.h"

/**
 * SkillRaceResult implementation
 */


QDataStream &operator<<(QDataStream &out, const SkillRaceResult &res)
{
    out<<res.teamName;
    out<<res.teamID;
    out<<res.position;
    out<<res.skillPoint;
    return out;
}

QDataStream &operator>>(QDataStream &in, SkillRaceResult &res)
{
    in>>res.teamName;
    in>>res.teamID;
    in>>res.position;
    in>>res.skillPoint;
    return  in;
}
