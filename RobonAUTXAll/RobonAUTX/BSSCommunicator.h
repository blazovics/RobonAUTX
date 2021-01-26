#ifndef BSSCOMMUNICATOR_H
#define BSSCOMMUNICATOR_H

#include <QObject>
#include <QNetworkAccessManager>

class BSSCommunicator : public QObject
{
    Q_OBJECT

    QNetworkAccessManager networkManager;

public:
    explicit BSSCommunicator(QObject *parent = nullptr);

    void SendStartSkillTimer(quint32 offset);
    void SendStopSkillTimer(quint32 offset);
    void SendSkillScoreUpdated(quint32 teamID,quint32 bonusTime, quint32 timeLeft, quint32 newScore, quint32 totalScore);
    void SendSkillRaceFinished(quint32 teamID, quint32 totalScore);

    void SendStartSpeedTimer(quint32 offset);
    void SendStopSpeedimer(quint32 offset);
    void SendSafetyCarFollowed(quint32 teamID,  bool followed);
    void SendSafetyCarOvertaken(quint32 teamID, quint32 occurence);
    void SendSpeedLapAchieved(quint32 teamID, QList<quint32> laps);
    void SendSpeedRaceFinished(quint32 teamID, quint32 totalScore, QList<quint32> laps);

    void SendQualificationResult(quint32 teamID, quint32 qualificationPoint);
    void SendAudienceResult(quint32 teamID, quint32 voteCount, quint32 audiencePoint);
    void SendFinalResult(quint32 teamID, quint32 totalScore, quint32 rank, quint32 juniorRank);

signals:

public slots:
    void encrypted(QNetworkReply *reply);
    void finished(QNetworkReply *reply);
    void sslErrors(QNetworkReply *reply, const QList<QSslError> &errors);
};

#endif // BSSCOMMUNICATOR_H
