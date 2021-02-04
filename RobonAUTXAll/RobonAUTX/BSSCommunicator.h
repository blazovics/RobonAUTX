#ifndef BSSCOMMUNICATOR_H
#define BSSCOMMUNICATOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include "VoteResult.h"
#include "QualificationResult.h"
#include "FinalResult.h"
#include "SpeedRaceResult.h"
#include "Team.h"

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
    
    void SendJuniorSpeedRaceResult(int teamID, int totalScore, int bestSpeedTime, QList<int> laps);
    void SendSeniorSpeedRaceResult(int teamID, int totalScore, int bestSpeedTime, QList<int> laps);

    void SendJuniorSpeedRaceResults(QList<SpeedRaceResult> results);
    void SendSeniorSpeedRaceResults(QList<SpeedRaceResult> results);

    void SendVoteResult(QList<VoteResult> results);
    void SendQualificationResult(QList<QualificationResult> results);
    
    void SendSeniorFinalResults(QList<FinalResult> results);
    void SendJuniorFinalResults(QList<FinalResult> results);

    void SendTeams(QList<Team> teams);

    void SendQualificationResult(int teamID, int qualificationPoint);
    void SendAudienceResult(int teamID, int voteCount, int audiencePoint);
    void SendSeniorFinalResult(int teamID, int totalScore);
    void SendJuniorFinalResult(int teamID, int totalScore);

    void SendTeam(int teamID, QString name, bool isJunior, QList<QString> teamMembers);

signals:

public slots:
    void finished(QNetworkReply *reply);

private:
    void PostRequest(QJsonObject& object, QString uri);
};

#endif // BSSCOMMUNICATOR_H
