#include "BSSCommunicator.h"
#include <QJsonDocument>
#include <QJsonObject>

BSSCommunicator::BSSCommunicator(QString serverUrlString, QObject *parent) :  QObject(parent), serverUrlString(serverUrlString)
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager,SIGNAL(encrypted(QNetworkReply*)),this,SLOT(encrypted(QNetworkReply*)));
    connect(networkManager,SIGNAL(finished(QNetworkReply*)), this, SLOT(finished(QNetworkReply*)));
    connect(networkManager,SIGNAL(sslErrors(QNetworkReply*,const QList<QSslError> &)),this,SLOT(sslErrors(QNetworkReply*,const QList<QSslError> &)));
}

BSSCommunicator::~BSSCommunicator()
{
    delete networkManager;
}

void BSSCommunicator::SendStartSkillTimer(int offset)
{
    QJsonObject obj;

    obj["timerAt"] = offset;
    obj["timerAction"] ="START";

    this->PostRequest(obj,"/api/skill/timer/start");
}

void BSSCommunicator::SendStopSkillTimer(int offset)
{
    QJsonObject obj;

    obj["timerAt"] = offset;
    obj["timerAction"] ="STOP";

    this->PostRequest(obj,"/api/skill/timer/start");
}

void BSSCommunicator::SendSkillScoreUpdated(int teamID, int bonusTime, int timeLeft, int newScore, int totalScore)
{

}

void BSSCommunicator::SendSkillRaceFinished(int teamID, int totalScore)
{

}

void BSSCommunicator::SendStartSpeedTimer(int offset)
{

}

void BSSCommunicator::SendStopSpeedimer(int offset)
{

}

void BSSCommunicator::SendSafetyCarFollowed(int teamID, bool followed)
{

}

void BSSCommunicator::SendSafetyCarOvertaken(int teamID, int occurence)
{

}

void BSSCommunicator::SendSpeedLapAchieved(int teamID, QList<quint32> laps)
{

}

void BSSCommunicator::SendSpeedRaceFinished(int teamID, int totalScore, QList<int> laps)
{

}

void BSSCommunicator::SendQualificationResult(int teamID, int qualificationPoint)
{

}

void BSSCommunicator::SendAudienceResult(int teamID, int voteCount, int audiencePoint)
{

}

void BSSCommunicator::SendFinalResult(int teamID, int totalScore, int rank, int juniorRank)
{

}

//Slots

void BSSCommunicator::encrypted(QNetworkReply *reply)
{

}

void BSSCommunicator::finished(QNetworkReply *reply)
{

}

void BSSCommunicator::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{

}

void BSSCommunicator::PostRequest(QJsonObject &object, QString uri)
{
    QJsonDocument doc(object);
    QByteArray data = doc.toJson();

    QUrl url(serverUrlString + uri);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("RobonAuth-Api-Key", "bss");

    networkManager->post(request,data);
}
