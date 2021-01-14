/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */

#include <QTime>
#include "SpeedRaceResult.h"

/**
 * SpeedRaceResult implementation
 */


/**
 * @return QString
 */

//FIXME: Make it more common!
QString SpeedRaceResult::SpeedTimeToString(qint64 time) {

    QTime qtime(0,0);
    qtime = qtime.addMSecs(int(time));
    QString timeString = qtime.toString("mm:ss.zzz");
    timeString.chop(1);
    return timeString;

}

QString SpeedRaceResult::SkillTimeToString(qint64 time)
{
    QTime qtime(0,0);
    qtime = qtime.addMSecs(int(time));
    return qtime.toString("mm:ss");
}

QDataStream &operator<<(QDataStream &out, const SpeedRaceResult &res)
{
    out<<res.teamName;
    out<<res.teamID;
    out<<res.position;
    out<<res.isJunior;
    out<<res.speedPoint;
    out<<res.speedTime;
    return out;
}

QDataStream &operator>>(QDataStream &in, SpeedRaceResult &res)
{
    in>>res.teamName;
    in>>res.teamID;
    in>>res.position;
    in>>res.isJunior;
    in>>res.speedPoint;
    in>>res.speedTime;
    return  in;
}
