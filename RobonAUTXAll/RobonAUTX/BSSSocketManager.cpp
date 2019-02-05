#include "BSSSocketManager.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

BSSSocketManager::BSSSocketManager(QObject *parent) : QObject(parent)
{
    bool status = true;

    status = QObject::connect(&webSocket, &QWebSocket::aboutToClose, this, &BSSSocketManager::aboutToClose);
    status = QObject::connect(&webSocket, &QWebSocket::binaryFrameReceived, this, &BSSSocketManager::binaryFrameReceived);
    status = QObject::connect(&webSocket, &QWebSocket::binaryMessageReceived, this, &BSSSocketManager::binaryMessageReceived);
    status = QObject::connect(&webSocket, &QWebSocket::connected, this, &BSSSocketManager::connected);
    status = QObject::connect(&webSocket, SIGNAL(error(QAbsstractSocket::SocketError)), this, SLOT(error(QAbsstractSocket::SocketError)));
    status = QObject:: connect(&webSocket, &QWebSocket::pong, this, &BSSSocketManager::pong);
    status = connect(&webSocket, SIGNAL(proxyAuthenticationRequired(QNetworkProxy, QAuthenticator*)), this, SLOT(proxyAuthenticationRequired(QNetworkProxy,QAuthenticator*)));
    status = connect(&webSocket, &QWebSocket::readChannelFinished, this, &BSSSocketManager::readChannelFinished);
    status = connect(&webSocket, &QWebSocket::sslErrors, this, &BSSSocketManager::sslErrors);
    status = connect(&webSocket, &QWebSocket::stateChanged, this, &BSSSocketManager::stateChanged);
    status = connect(&webSocket, &QWebSocket::textFrameReceived, this, &BSSSocketManager::textFrameReceived);
    status = connect(&webSocket, &QWebSocket::textMessageReceived, this, &BSSSocketManager::textMessageReceived);

}

void BSSSocketManager::connectToServer(QUrl newServerURL)
{
    webSocket.close();

    this->serverUrl = newServerURL;
    webSocket.open(this->serverUrl);
}

void BSSSocketManager::sendSkillTimerStarted()
{

}

void BSSSocketManager::sendSkillTimerStopped()
{

}

void BSSSocketManager::sendSkillResultChanged(quint32 teamID, quint32 remainingTime, quint32 timeCredit, quint32 point, quint32 checkpointPoint)
{

}

void BSSSocketManager::sendSkillRaceFinished(quint32 teamID, quint32 point)
{

}

void BSSSocketManager::sendSpeedPointChanged(quint32 teamID, quint32 checkpointPoint, quint32 penaltyPoints)
{

}

/*
void BSSSocketManager::onClosed()
{

}

void BSSSocketManager::onConnected()
{
    connect(&webSocket, &QWebSocket::binaryMessageReceived, this, &BSSSocketManager::onBinaryMessageReceived);

    QJsonObject obj;

    obj["type"] = "getTeamsData";
    obj["year"] = "2018";



    //qDebug()<<strJson;

    QJsonDocument doc(obj);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    webSocket.sendTextMessage(strJson);
}*/

void  BSSSocketManager::sendStartTimer()
{
    QJsonObject obj;

    obj["type"] = "timerStart";

    webSocket.sendTextMessage(QString((QJsonDocument(obj).toJson(QJsonDocument::Compact))));
}

void  BSSSocketManager::sendStopTimer()
{
    QJsonObject obj;

    obj["type"] = "timerStop";

    webSocket.sendTextMessage(QString((QJsonDocument(obj).toJson(QJsonDocument::Compact))));
}

void BSSSocketManager::sendSpeedLapFinished(quint32 teamID, quint32 lap, quint32 time)
{

}

void BSSSocketManager::sendSpeedResults(QList<SpeedRaceResult> results)
{

}

void BSSSocketManager::sendQualificationPoints(QList<QualificationResult> results)
{

}

void BSSSocketManager::sendVotePoints(QList<VoteResult> results)
{

}

void BSSSocketManager::sendFinalResults(QList<FinalResult> results)
{

}

void BSSSocketManager::sendJuniorFinalResults(QList<FinalResult> results)
{

}
/*
void BSSSocketManager::sendSpeedResult(int teamID, int result, int lapID)
{
    QJsonObject obj;

    obj["type"] = "laptime";
    obj["year"] = "2018";
    obj["lap"] = lapID;
    obj["time"] = result;
    obj["teamId"] = teamID;

    webSocket.sendTextMessage(QString((QJsonDocument(obj).toJson(QJsonDocument::Compact))));
}

void BSSSocketManager::sendSkillResult(int teamID, int points)
{
    QJsonObject obj;

    obj["type"] = "skillPoint";
    obj["year"] = "2018";
    obj["score"] = points;
    obj["teamId"] = teamID;

    webSocket.sendTextMessage(QString((QJsonDocument(obj).toJson(QJsonDocument::Compact))));
}

void BSSSocketManager::sendSkillPenalty(int teamID, int penalty)
{
    QJsonObject obj;

    obj["type"] = "skillErrorPoint";
    obj["year"] = "2018";
    obj["penalty"] = penalty;
    obj["teamId"] = teamID;

    webSocket.sendTextMessage(QString((QJsonDocument(obj).toJson(QJsonDocument::Compact))));
}

void BSSSocketManager::sendPrePoints(vector<TeamDetailResult> teamResults)
{

    QJsonObject obj;
    obj["type"] = "scoreboard";
    obj["year"] = "2018";
    obj["round"] = "brought";

    QJsonArray array;

    for(int i=0; i<teamResults.size(); i++)
    {
        QJsonObject tObj;

        tObj["teamId"] = qint32(teamResults[i].teamid);
        tObj["score"] = qint32(teamResults[i].result);

        array.append(tObj);
    }

    obj["score"] = array;

    webSocket.sendTextMessage(QString((QJsonDocument(obj).toJson(QJsonDocument::Compact))));
}

void BSSSocketManager::sendAudiencePoints(vector<TeamDetailResult> teamResults)
{
    QJsonObject obj;
    obj["type"] = "scoreboard";
    obj["year"] = "2018";
    obj["round"] = "audiencePoint";

    QJsonArray array;

    for(int i=0; i<teamResults.size(); i++)
    {
        QJsonObject tObj;

        tObj["teamId"] = qint32(teamResults[i].teamid);
        tObj["score"] = qint32(teamResults[i].result);

        array.append(tObj);
    }

    obj["score"] = array;

    webSocket.sendTextMessage(QString((QJsonDocument(obj).toJson(QJsonDocument::Compact))));
}

void BSSSocketManager::sendTechResults(vector<TeamDetailResult> teamResults)
{
    QJsonObject obj;
    obj["type"] = "scoreboard";
    obj["year"] = "2018";
    obj["round"] = "skill";

    QJsonArray array;

    for(int i=0; i<teamResults.size(); i++)
    {
        QJsonObject tObj;

        tObj["teamId"] = qint32(teamResults[i].teamid);
        tObj["score"] = qint32(teamResults[i].result);
        tObj["penalty"] = qint32(teamResults[i].sub_result_3);
        tObj["rank"] = qint32(teamResults[i].index);

        array.append(tObj);
    }

    obj["score"] = array;

    webSocket.sendTextMessage(QString((QJsonDocument(obj).toJson(QJsonDocument::Compact))));
}

void BSSSocketManager::sendSpeedResults(vector<TeamDetailResult> teamResults)
{
    QJsonObject obj;
    obj["type"] = "scoreboard";
    obj["year"] = "2018";
    obj["round"] = "speed";

    QJsonArray array;

    for(int i=0; i<teamResults.size(); i++)
    {
        QJsonObject tObj;

        tObj["teamId"] = qint32(teamResults[i].teamid);
        tObj["score"] = qint32(teamResults[i].sub_result_1);
        tObj["penaltyPoint"] = qint32(teamResults[i].sub_result_2);
        tObj["bestTime"] = qint32(teamResults[i].result);
        tObj["rank"] = qint32(teamResults[i].index);

        array.append(tObj);
    }

    obj["score"] = array;

    webSocket.sendTextMessage(QString((QJsonDocument(obj).toJson(QJsonDocument::Compact))));

}

void BSSSocketManager::sendJuniorResults(vector<TeamDetailResult> teamResults)
{
    QJsonObject obj;
    obj["type"] = "juniorResult";

    QJsonArray array;

    for(int i=0; i<teamResults.size(); i++)
    {
        QJsonObject tObj;

        tObj["teamId"] = qint32(teamResults[i].teamid);
        tObj["TechnicalPoint"] = qint32(teamResults[i].sub_result_1);
        tObj["SpeedPoint"] = qint32(teamResults[i].sub_result_2);
        tObj["PrePoint"] = qint32(teamResults[i].sub_result_4);
        tObj["AudiencePoint"] = qint32(teamResults[i].sub_result_3);
        tObj["SumPoint"] = qint32(teamResults[i].result);
        tObj["Rank"] = qint32(teamResults[i].index);

        array.append(tObj);
    }

    obj["data"] = array;

    webSocket.sendTextMessage(QString((QJsonDocument(obj).toJson(QJsonDocument::Compact))));

}

void BSSSocketManager::sendAllResults(vector<TeamDetailResult> teamResults)
{
    QJsonObject obj;
    obj["type"] = "finalResult";

    QJsonArray array;

    for(int i=0; i<teamResults.size(); i++)
    {
        QJsonObject tObj;

        tObj["teamId"] = qint32(teamResults[i].teamid);
        tObj["TechnicalPoint"] = qint32(teamResults[i].sub_result_1);
        tObj["SpeedPoint"] = qint32(teamResults[i].sub_result_2);
        tObj["PrePoint"] = qint32(teamResults[i].sub_result_4);
        tObj["AudiencePoint"] = qint32(teamResults[i].sub_result_3);
        tObj["SumPoint"] = qint32(teamResults[i].result);
        tObj["Rank"] = qint32(teamResults[i].index);

        array.append(tObj);
    }

    obj["data"] = array;

    webSocket.sendTextMessage(QString((QJsonDocument(obj).toJson(QJsonDocument::Compact))));

}*/

//SLOTS for Debug

void  BSSSocketManager::aboutToClose(){

}
void  BSSSocketManager::binaryFrameReceived(const QByteArray &frame, bool isLastFrame){

}
void  BSSSocketManager::binaryMessageReceived(const QByteArray &message){

}
void  BSSSocketManager::bytesWritten(qint64 bytes){

}
void  BSSSocketManager::connected(){
    emit connectionActive(true);
}
void  BSSSocketManager::disconnected(){
    emit connectionActive(false);
}
void  BSSSocketManager::error(QAbstractSocket::SocketError error){
    this->webSocket.abort();
    emit connectionActive(false);
}
void  BSSSocketManager::pong(quint64 elapsedTime, const QByteArray &payload){

}
void  BSSSocketManager::proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator){

}
void  BSSSocketManager::readChannelFinished(){

}
void  BSSSocketManager::sslErrors(const QList<QSslError> &errors){

}
void  BSSSocketManager::stateChanged(QAbstractSocket::SocketState state){

}
void  BSSSocketManager::textFrameReceived(const QString &frame, bool isLastFrame){

}
void  BSSSocketManager::textMessageReceived(const QString &message){
    qDebug()<<message;
}
