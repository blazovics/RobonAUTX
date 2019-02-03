/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef MAINVIEWCONTROLLER_H
#define MAINVIEWCONTROLLER_H

#include <QObject>
#include "Team.h"
#include <QQmlContext>
#include <TeamModel.h>

class MainViewcontroller : public QObject{

    Q_OBJECT

     QQmlContext *rootContext;
     TeamModel teamModel;

public: 
    explicit MainViewcontroller(QObject* parent = nullptr);

     void setRootContext(QQmlContext *value);

public slots:

     void TeamListUpdated(QList<Team> teams);

    void ShowSkillRaceView(quint32 teamID);
    
    void ShowSpeedRaceView();
    
    void ShowResultView();
};

#endif //_MAINVIEWCONTROLLER_H
