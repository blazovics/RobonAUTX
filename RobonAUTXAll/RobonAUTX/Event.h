#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include "Team.h"
#include "SpeedRaceResult.h"
#include "SkillRaceResult.h"
#include "VoteResult.h"
#include "QualificationResult.h"
#include "FinalResult.h"
#include "SkillRace.h"
#include "memory"

class Event
{
    quint32 eventID;
    QByteArray rawData;
    std::unique_ptr<QDataStream> outStream;
    std::unique_ptr<QDataStream> inStream;

public:
    Event();
    Event(quint32 eventID);
    Event(quint32 eventID, const QByteArray &rawData);
    quint32 getEventID() const;
    void setEventID(const quint32 &value);
    quint32 getRawDataSize()const;
    QByteArray getRawData() const;

    quint32 extractQuint32FromRawData();
    quint64 extractQuint64FromRawData();
    quint8 extractQuint8FromRawData();
    bool extractBoolFromRawData();
    QList<SpeedRaceResult> extractSpeedRaceResultsFromRawData();
    QList<SkillRaceResult> extractSkillRaceResultFromRawData();
    QList<VoteResult> extractVoteResultsFromRawData();
    QList<QualificationResult> extractQualificationResultsFromRawData();
    QList<FinalResult> extractFinalResultsFromRawData();
    QList<Team> extractTeamsFromRawData();
    CheckpointState extractCheckpointStateFromRawData();

    void insertTeams(QList<Team> teams);
    void insertQuint8(quint8 value);
    void insertQuint32(quint32 value);
    void insertQuint64(quint64 value);
    void insertBool(bool value);
    void insertSpeedRaceResults(QList<SpeedRaceResult> results);
    void insertVoteResults(QList<VoteResult> results);
    void insertSkillRaceResults(QList<SkillRaceResult> results);
    void insertQualificationResuls(QList<QualificationResult> results);
    void insertFinalResults(QList<FinalResult> results);
    void insertCheckpointState(CheckpointState state);
    void insertCheckpointState8bit(CheckpointState state);



};

#endif // EVENT_H
