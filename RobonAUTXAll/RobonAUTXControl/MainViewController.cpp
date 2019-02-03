/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "MainViewcontroller.h"
#include "TeamModel.h"

/**
 * MainViewcontroller implementation
 */


void MainViewcontroller::setRootContext(QQmlContext *value)
{
    rootContext = value;
    if(rootContext != nullptr)
    {
        rootContext->setContextProperty("teamModel",&teamModel);
    }
}

MainViewcontroller::MainViewcontroller(QObject *parent):QObject (parent)
{

}

void MainViewcontroller::TeamListUpdated(QList<Team> teams)
{




}

void MainViewcontroller::ShowSkillRaceView(quint32 teamID) {

}

void MainViewcontroller::ShowSpeedRaceView() {

}

void MainViewcontroller::ShowResultView() {

}
