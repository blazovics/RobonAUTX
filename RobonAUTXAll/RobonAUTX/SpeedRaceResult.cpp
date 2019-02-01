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
QString SpeedRaceResult::SpeedTimeToString(qint64 time) {

    QTime qtime;
    qtime = qtime.addMSecs(int(time));
    return qtime.toString("mm:ss.zzz");

}
QDataStream &operator<<(QDataStream &out, const SpeedRaceResult &res)
{
    out<<res.teamID;
    out<<res.position;
    out<<res.isJunior;
    out<<res.speedPoint;
    out<<res.speedTime;
    return out;
}

QDataStream &operator>>(QDataStream &in, SpeedRaceResult &res)
{
    in>>res.teamID;
    in>>res.position;
    in>>res.isJunior;
    in>>res.speedPoint;
    in>>res.speedTime;
    return  in;
}
