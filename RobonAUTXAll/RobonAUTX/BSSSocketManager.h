#ifndef BSSSOCKETMANAGER_H
#define BSSSOCKETMANAGER_H

#include <QObject>
#include <QWebSocket>
#include <vector>

#include "QualificationResult.h"
#include "SpeedRaceResult.h"
#include "SkillRaceResult.h"
#include "FinalResult.h"
#include "VoteResult.h"

using namespace std;

class BSSSocketManager : public QObject
{
    Q_OBJECT

    QWebSocket webSocket;
    QUrl serverUrl;

public:
    explicit BSSSocketManager(QObject *parent = nullptr);

signals:

    void connectionActive(bool);

public slots:
    void connectToServer(QUrl newServerURL);

    void sendSkillTimerStarted();
    void sendSkillTimerStopped();
    void sendSkillResultChanged(quint32 teamID, quint32 remainingTime, quint32 timeCredit, quint32 point, quint32 checkpointPoint);
    void sendSkillRaceFinished(quint32 teamID, quint32 point);
    void sendSpeedPointChanged(quint32 teamID, quint32 checkpointPoint, quint32 penaltyPoints);

    void sendStartTimer();
    void sendStopTimer();
    void sendSpeedLapFinished(quint32 teamID, quint32 lap, quint32 time);
    void sendSpeedResults(QList<SpeedRaceResult> results);
    void sendQualificationPoints(QList<QualificationResult> results);
    void sendVotePoints(QList<VoteResult> results);
    void sendFinalResults(QList<FinalResult> results);
    void sendJuniorFinalResults(QList<FinalResult> results);

    /*
    void sendTechResults(QList<SkillRaceResult> results);
    void sendSkillResult(int teamID, int points);
    void sendSkillPenalty(int teamID, int penalty);
    void sendSpeedResult(int teamID, int result, int lapID = 1);

    */





private slots:

    void aboutToClose();
    void binaryFrameReceived(const QByteArray &frame, bool isLastFrame);
    void binaryMessageReceived(const QByteArray &message);
    void bytesWritten(qint64 bytes);
    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError error);
    void pong(quint64 elapsedTime, const QByteArray &payload);
    void proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    void readChannelFinished();
    void sslErrors(const QList<QSslError> &errors);
    void stateChanged(QAbstractSocket::SocketState state);
    void textFrameReceived(const QString &frame, bool isLastFrame);
    void textMessageReceived(const QString &message);
};

#endif // BSSSOCKETMANAGER_H
