#include "MainSystemController.h"
#include "Configuration.h"
#include <QHostAddress>
#include <QDebug>

MainSystemController::MainSystemController()
{

}

void MainSystemController::StartServers()
{

    Configuration& instance = Configuration::GetInstance();

    QHostAddress serverAddress;

    if(instance.IsKeyAvailable("MainSystemSettings","ListenAddress"))
    {
        QString serverAddressString = QString::fromStdString(instance.GetStringValue("MainSystemSettings","ListenAddress"));
        serverAddress.setAddress(serverAddressString);
    }
    else
    {
        serverAddress.setAddress(QHostAddress::Any);

        //TODO: Easylogging
        qDebug()<<"No valid server configuration";
    }

    if(instance.IsKeyAvailable("MainSystemSettings","LaserGateServerPort"))
    {
        quint16 port =  quint16(instance.GetLongValue("MainSystemSettings","LaserGateServerPort"));
        laserGateServer.listen(serverAddress,port);
    }
    else {
        laserGateServer.listen(serverAddress,35001);
        //TODO: Easylogging
    }

    if(instance.IsKeyAvailable("MainSystemSettings","VoteCounterServerPort"))
    {
        quint16 port =  quint16(instance.GetLongValue("MainSystemSettings","VoteCounterServerPort"));
        voteCounterServer.listen(serverAddress,port);
    }
    else {
        voteCounterServer.listen(serverAddress,35002);
        //TODO: Easylogging
    }

    if(instance.IsKeyAvailable("MainSystemSettings","SkillRaceFieldUnitServerPort"))
    {
        quint16 port =  quint16(instance.GetLongValue("MainSystemSettings","SkillRaceFieldUnitServerPort"));
        skillRaceFieldUnitServer.listen(serverAddress,port);
    }
    else {
        laserGateServer.listen(serverAddress,35003);
        //TODO: Easylogging
    }

    if(instance.IsKeyAvailable("MainSystemSettings","SkillRaceGateServerPort"))
    {
        quint16 port =  quint16(instance.GetLongValue("MainSystemSettings","SkillRaceGateServerPort"));
        skillRaceGateServer.listen(serverAddress,port);
    }
    else {
        skillRaceGateServer.listen(serverAddress,35004);
        //TODO: Easylogging
    }

    if(instance.IsKeyAvailable("MainSystemSettings","DisplayManagerServerPort"))
    {
        quint16 port =  quint16(instance.GetLongValue("MainSystemSettings","DisplayManagerServerPort"));
        displayManagerServer.listen(serverAddress,port);
    }
    else {
        displayManagerServer.listen(serverAddress,35005);
        //TODO: Easylogging
    }

}

void MainSystemController::StopServers()
{

}
