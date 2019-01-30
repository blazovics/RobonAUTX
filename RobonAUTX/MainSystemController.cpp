#include "MainSystemController.h"
#include "Configuration.h"
#include <QHostAddress>
#include <QDebug>

MainSystemController::MainSystemController()
{
    centralController = std::make_unique<CentralController>();
    proxiCentralController = std::make_unique<RemoteCentralController>(this,nullptr);
    proxiCentralController->setLocalController(centralController.get());
}

void MainSystemController::RemoteDeviceDisconnected(RemoteDevice *device, QTcpSocket *socket)
{
    //FIXME: Implement!
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

void MainSystemController::newLaserGateConnection()
{
    QTcpSocket* newSocket = this->laserGateServer.nextPendingConnection();
    std::shared_ptr<RemoteLaserGate> newRemoteLaserGate = std::make_shared<RemoteLaserGate>(this,newSocket);

    if(this->remoteLaserGate.second != nullptr)
    {
        CoreController::disconnectDevice(this->centralController.get(),remoteLaserGate.first.get());
    }

    this->remoteLaserGate = QPair<std::shared_ptr<RemoteLaserGate>,QTcpSocket*>(newRemoteLaserGate,newSocket);
    CoreController::connectDevice(this->centralController.get(),remoteLaserGate.first.get());
}

void MainSystemController::newSkillRaceFieldUnitConnection()
{
    QTcpSocket* newSocket = this->skillRaceFieldUnitServer.nextPendingConnection();
    std::shared_ptr<RemoteSkillRaceFieldUnit> newRemoteSkillRaceFieldUnit = std::make_shared<RemoteSkillRaceFieldUnit>(this,newSocket);

    if(this->remoteSkillRaceFieldUnit.second != nullptr)
    {
        CoreController::disconnectDevice(this->centralController.get(),remoteSkillRaceFieldUnit.first.get());
    }

    this->remoteSkillRaceFieldUnit = QPair<std::shared_ptr<RemoteSkillRaceFieldUnit>,QTcpSocket*>(newRemoteSkillRaceFieldUnit,newSocket);

    CoreController::connectDevice(this->centralController.get(),remoteSkillRaceFieldUnit.first.get());
}

void MainSystemController::newVoteCounterConnection()
{
    QTcpSocket* newSocket = this->voteCounterServer.nextPendingConnection();
    std::shared_ptr<RemoteVoteCounter> newRemoteVoteCounter = std::make_shared<RemoteVoteCounter>(this,newSocket);

    if(this->remoteVoteCounter.second != nullptr)
    {
        CoreController::disconnectDevice(this->centralController.get(),remoteVoteCounter.first.get());
    }

    this->remoteVoteCounter = QPair<std::shared_ptr<RemoteVoteCounter>,QTcpSocket*>(newRemoteVoteCounter,newSocket);

    CoreController::connectDevice(this->centralController.get(),remoteVoteCounter.first.get());
}

void MainSystemController::newSkillRaceGateConnection()
{
    QTcpSocket* newSocket = this->skillRaceGateServer.nextPendingConnection();
    std::shared_ptr<RemoteSkillRaceGate> newRemoteSkillRaceGate = std::make_shared<RemoteSkillRaceGate>(this,newSocket);

    if(this->remoteSkillRaceGate.second != nullptr)
    {
        CoreController::disconnectDevice(this->centralController.get(),remoteSkillRaceGate.first.get());
    }

    this->remoteSkillRaceGate = QPair<std::shared_ptr<RemoteSkillRaceGate>,QTcpSocket*>(newRemoteSkillRaceGate,newSocket);

    CoreController::connectDevice(this->centralController.get(),remoteSkillRaceGate.first.get());
}

void MainSystemController::newRaceControlUnitConnection()
{

}

void MainSystemController::newDisplayManagerConnection()
{

}
