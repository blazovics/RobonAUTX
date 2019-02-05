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
    if(socket == nullptr)
    {
        //TODO: Easylogging
        throw std::runtime_error("trying to free a nullptr socket");
    }

    if(socket == remoteLaserGate.second)
    {
        disconnectDevice(this->centralController.get(),remoteLaserGate.first.get());
        remoteLaserGate.first.reset();
        remoteLaserGate.second = nullptr;
    }
    else if(socket == remoteSkillRaceFieldUnit.second)
    {
        disconnectDevice(this->centralController.get(),remoteSkillRaceFieldUnit.first.get());
        remoteSkillRaceFieldUnit.first.reset();
        remoteSkillRaceFieldUnit.second = nullptr;
    }
    else if(socket == remoteVoteCounter.second)
    {
        disconnectDevice(this->centralController.get(),remoteVoteCounter.first.get());
        remoteVoteCounter.first.reset();
        remoteVoteCounter.second = nullptr;
    }
    else if(socket == remoteSkillRaceGate.second)
    {
        disconnectDevice(this->centralController.get(),remoteSkillRaceGate.first.get());
        remoteSkillRaceGate.first.reset();
        remoteSkillRaceGate.second = nullptr;
    }

    for(int i=0; i<remoteRaceControlUnits.size();i++)
    {
        if(remoteRaceControlUnits[i].get()->second == socket)
        {
             disconnectDevice(this->centralController.get(),remoteRaceControlUnits[i].get()->first.get());
             remoteRaceControlUnits.removeAt(i);
             break;
        }
    }

    for(int i=0; i<remoteDisplayManagers.size();i++)
    {
        if(remoteDisplayManagers[i].get()->second == socket)
        {
             disconnectDevice(this->centralController.get(),remoteDisplayManagers[i].get()->first.get());
             remoteDisplayManagers.removeAt(i);
             break;
        }
    }
    proxiCentralController->RemoveConnection(socket);
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

    if(instance.IsKeyAvailable("MainSystemSettings","RaceControlUnitPort"))
    {
        quint16 port =  quint16(instance.GetLongValue("MainSystemSettings","RaceControlUnitPort"));
        raceControlUnitServer.listen(serverAddress,port);
    }
    else {
        raceControlUnitServer.listen(serverAddress,35000);
        //TODO: Easylogging
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
        skillRaceFieldUnitServer.listen(serverAddress,35003);
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

    connect(&laserGateServer,SIGNAL(newConnection()),this,SLOT(newLaserGateConnection()));
    connect(&skillRaceFieldUnitServer,SIGNAL(newConnection()),this,SLOT(newSkillRaceFieldUnitConnection()));
    connect(&voteCounterServer,SIGNAL(newConnection()),this,SLOT(newVoteCounterConnection()));
    connect(&skillRaceGateServer,SIGNAL(newConnection()),this,SLOT(newSkillRaceGateConnection()));
    connect(&raceControlUnitServer,SIGNAL(newConnection()),this,SLOT(newRaceControlUnitConnection()));
    connect(&displayManagerServer,SIGNAL(newConnection()),this,SLOT(newDisplayManagerConnection()));
}

void MainSystemController::StopServers()
{
    //FIXME: Implement
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
    this->proxiCentralController->AddConnection(newSocket,QIODevice::ReadOnly);
}

void MainSystemController::newSkillRaceFieldUnitConnection()
{
    QTcpSocket* newSocket = this->skillRaceFieldUnitServer.nextPendingConnection();
    std::shared_ptr<RemoteSkillRaceFieldUnit> newRemoteSkillRaceFieldUnit = std::make_shared<RemoteSkillRaceFieldUnit>(this,newSocket, QIODevice::ReadOnly);

    if(this->remoteSkillRaceFieldUnit.second != nullptr)
    {
        CoreController::disconnectDevice(this->centralController.get(),remoteSkillRaceFieldUnit.first.get());
    }

    this->remoteSkillRaceFieldUnit = QPair<std::shared_ptr<RemoteSkillRaceFieldUnit>,QTcpSocket*>(newRemoteSkillRaceFieldUnit,newSocket);

    CoreController::connectDevice(this->centralController.get(),remoteSkillRaceFieldUnit.first.get());
    this->proxiCentralController->AddConnection(newSocket,QIODevice::WriteOnly);
}

void MainSystemController::newVoteCounterConnection()
{
    QTcpSocket* newSocket = this->voteCounterServer.nextPendingConnection();
    std::shared_ptr<RemoteVoteCounter> newRemoteVoteCounter = std::make_shared<RemoteVoteCounter>(this,newSocket,QIODevice::ReadOnly);

    if(this->remoteVoteCounter.second != nullptr)
    {
        CoreController::disconnectDevice(this->centralController.get(),remoteVoteCounter.first.get());
    }

    this->remoteVoteCounter = QPair<std::shared_ptr<RemoteVoteCounter>,QTcpSocket*>(newRemoteVoteCounter,newSocket);

    CoreController::connectDevice(this->centralController.get(),remoteVoteCounter.first.get());
    this->proxiCentralController->AddConnection(newSocket,QIODevice::ReadOnly);
}

void MainSystemController::newSkillRaceGateConnection()
{
    QTcpSocket* newSocket = this->skillRaceGateServer.nextPendingConnection();
    std::shared_ptr<RemoteSkillRaceGate> newRemoteSkillRaceGate = std::make_shared<RemoteSkillRaceGate>(this,newSocket,QIODevice::ReadOnly);

    if(this->remoteSkillRaceGate.second != nullptr)
    {
        CoreController::disconnectDevice(this->centralController.get(),remoteSkillRaceGate.first.get());
    }

    this->remoteSkillRaceGate = QPair<std::shared_ptr<RemoteSkillRaceGate>,QTcpSocket*>(newRemoteSkillRaceGate,newSocket);

    CoreController::connectDevice(this->centralController.get(),remoteSkillRaceGate.first.get());
    this->proxiCentralController->AddConnection(newSocket,QIODevice::ReadOnly);
}

void MainSystemController::newRaceControlUnitConnection()
{
    QTcpSocket* newSocket = this->raceControlUnitServer.nextPendingConnection();

    std::shared_ptr<QPair<std::shared_ptr<RemoteRaceControlUnit>,QTcpSocket*>> pair = std::make_shared<QPair<std::shared_ptr<RemoteRaceControlUnit>,QTcpSocket*>>( QPair<std::shared_ptr<RemoteRaceControlUnit>,QTcpSocket*>(std::make_shared<RemoteRaceControlUnit>(this,newSocket),newSocket));

    this->remoteRaceControlUnits.push_back(pair);

    CoreController::connectDevice(this->centralController.get(),pair->first.get());
    this->proxiCentralController->AddConnection(newSocket,QIODevice::ReadOnly);
}

void MainSystemController::newDisplayManagerConnection()
{
    //FIXME: Implement
}
