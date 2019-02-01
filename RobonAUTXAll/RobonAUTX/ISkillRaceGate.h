#ifndef ISKILLRACEGATE_H
#define ISKILLRACEGATE_H

#include <QObject>

//FIXME put it somewhere else to be more robust
#define Event_SkillRaceGateStarted 36
#define Event_StartSkillRaceGate 34

class ISkillRaceGate : public QObject
{
    Q_OBJECT

public:

signals:
    void SkillRaceGateStarted();

public slots:
    virtual void StartSkillRaceGate() = 0;
};

#endif // ISKILLRACEGATE_H
