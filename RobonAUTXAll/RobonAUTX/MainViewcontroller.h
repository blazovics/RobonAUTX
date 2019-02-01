/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef MAINVIEWCONTROLLER_H
#define MAINVIEWCONTROLLER_H

#include <QObject>

class MainViewcontroller : public QObject{

    Q_OBJECT


public: 
    explicit MainViewcontroller(QObject* parent = nullptr);

    void ShowSkillRaceView();
    
    void ShowSpeedRaceView();
    
    void ShowResultView();
};

#endif //_MAINVIEWCONTROLLER_H
