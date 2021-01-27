#include "BSSCommunicator.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QNetworkReply>

BSSCommunicator::BSSCommunicator(QString serverUrlString, QObject *parent) :  QObject(parent), serverUrlString(serverUrlString)
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager,SIGNAL(finished(QNetworkReply*)), this, SLOT(finished(QNetworkReply*)));
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

    this->PostRequest(obj,"/api/skill/timer/stop");
}

void BSSCommunicator::SendSkillScoreUpdated(int teamID, int bonusTime, int timeLeft, int newScore, int totalScore)
{
    QJsonObject obj;

    obj["teamId"]= teamID;
    obj["bonusTime"]= bonusTime;
    obj["timeLeft"]= timeLeft;
    obj["skillScore"]= newScore;
    obj["totalSkillScore"]= totalScore;

    this->PostRequest(obj,"/api/skill/gate");
}

void BSSCommunicator::SendSkillRaceFinished(int teamID, int totalScore)
{
    QJsonObject obj;

    obj["teamId"]= teamID;
    obj["skillScore"]= totalScore;

    this->PostRequest(obj,"/api/skill/result");
}

void BSSCommunicator::SendStartSpeedTimer(int offset)
{
    QJsonObject obj;

    obj["timerAt"] = offset;
    obj["timerAction"] ="START";

    this->PostRequest(obj,"/api/speed/timer/start");
}

void BSSCommunicator::SendStopSpeedimer(int offset)
{
    QJsonObject obj;

    obj["timerAt"] = offset;
    obj["timerAction"] ="STOP";

    this->PostRequest(obj,"/api/speed/timer/stop");
}

void BSSCommunicator::SendSafetyCarFollowed(int teamID, bool followed)
{
    QJsonObject obj;

    obj["teamId"]= teamID;
    obj["safetyCarFollowed"]= followed;

    this->PostRequest(obj,"/api/speed/safetyCar/follow");
}

void BSSCommunicator::SendSafetyCarOvertaken(int teamID, int occurence)
{
    QJsonObject obj;

    obj["teamId"]= teamID;
    obj["numberOfOvertakes"]= occurence;

    this->PostRequest(obj,"/api/speed/safetyCar/overtake");
}

void BSSCommunicator::SendSpeedLapAchieved(int teamID, QList<quint32> laps)
{

    QJsonArray lapArray;
    for (quint32 lap : laps){
        lapArray.append(int(lap));
    }

    QJsonObject obj;

    obj["teamId"]= teamID;
    obj["speedTimes"]= lapArray;

    this->PostRequest(obj,"/api/speed/lap");
}

void BSSCommunicator::SendSpeedRaceFinished(int teamID, int totalScore, QList<int> laps)
{
    QJsonArray lapArray;
    for (quint32 lap : laps){
        lapArray.append(int(lap));
    }

    QJsonObject obj;

    obj["teamId"]= teamID;
    obj["speedScore"]= totalScore;
    obj["speedBonusScore"]= totalScore;
    obj["speedTimes"]= lapArray;

    this->PostRequest(obj,"/api/speed/result");
}

void BSSCommunicator::SendQualificationResult(int teamID, int qualificationPoint)
{
    QJsonObject obj;

    obj["teamId"]= teamID;
    obj["qualificationScore"]= qualificationPoint;

    this->PostRequest(obj,"/api/scores/qualification");
}

void BSSCommunicator::SendAudienceResult(int teamID, int voteCount, int audiencePoint)
{
    QJsonObject obj;

    obj["teamId"]= teamID;
    obj["votes"]= voteCount;
    obj["audienceScore"]= audiencePoint;

    this->PostRequest(obj,"/api/scores/audience");
}

void BSSCommunicator::SendFinalResult(int teamID, int totalScore, int rank, int juniorRank)
{
    QJsonObject obj;

    obj["teamId"]= teamID;
    obj["totalScore"]= totalScore;
    obj["rank"]= rank;
    obj["juniorRank"]= juniorRank;

    this->PostRequest(obj,"/api/scores/endResult");
}

//Slots

void BSSCommunicator::finished(QNetworkReply *reply)
{
    QVariant statusCode = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
    if (statusCode.isValid() )
    {
        qDebug()<< "Status: " << statusCode.toInt();
    }
    qDebug()<< "Response: " << QString(reply->readAll());
}

void BSSCommunicator::PostRequest(QJsonObject &object, QString uri)
{
    QJsonDocument doc(object);
    QByteArray data = doc.toJson();

    QUrl url(serverUrlString + uri);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("RobonAuth-Api-Key", "BSS");

    networkManager->post(request,data);
}
