#ifndef BSSCOMMUNICATOR_H
#define BSSCOMMUNICATOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

class BSSCommunicator : public QObject
{
    Q_OBJECT

    QNetworkAccessManager *networkManager;

    QList<QNetworkRequest*> ongoingRequests;

    const QString serverUrlString;

public:
    explicit BSSCommunicator(QString serverUrlString, QObject *parent = nullptr);
    ~BSSCommunicator();

    void SendStartSkillTimer(int offset);
    void SendStopSkillTimer(int offset);
    void SendSkillScoreUpdated(int teamID,int bonusTime, int timeLeft, int newScore, int totalScore);
    void SendSkillRaceFinished(int teamID, int totalScore);

    void SendStartSpeedTimer(int offset);
    void SendStopSpeedimer(int offset);
    void SendSafetyCarFollowed(int teamID,  bool followed);
    void SendSafetyCarOvertaken(int teamID, int occurence);
    void SendSpeedLapAchieved(int teamID, QList<quint32> laps);
    void SendSpeedRaceFinished(int teamID, int totalScore, QList<int> laps);

    void SendQualificationResult(int teamID, int qualificationPoint);
    void SendAudienceResult(int teamID, int voteCount, int audiencePoint);
    void SendFinalResult(int teamID, int totalScore, int rank, int juniorRank);

signals:

public slots:
    void finished(QNetworkReply *reply);

private:
    void PostRequest(QJsonObject& object, QString uri);
};

#endif // BSSCOMMUNICATOR_H
