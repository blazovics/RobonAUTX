#include "Event.h"

quint32 Event::getEventID() const
{
    return eventID;
}

void Event::setEventID(const quint32 &value)
{
    eventID = value;
}

quint32 Event::getRawDataSize() const
{
    return  quint32(rawData.size());
}

QByteArray Event::getRawData() const
{
    return rawData;
}

quint32 Event::extractQuint32FromRawData()
{
    quint32 value;
    *inStream >> value;
    return value;
}

quint64 Event::extractQuint64FromRawData()
{
    quint64 value;
    *inStream >> value;
    return value;
}

quint8 Event::extractQuint8FromRawData()
{
    quint8 value;
    *inStream >> value;
    return value;
}

bool Event::extractBoolFromRawData()
{
    bool value;
    *inStream >> value;
    return value;
}

QList<SpeedRaceResult> Event::extractSpeedRaceResultsFromRawData()
{
    QList<SpeedRaceResult> results;
    *inStream >> results;
    return results;
}

QList<SkillRaceResult> Event::extractSkillRaceResultFromRawData()
{
    QList<SkillRaceResult> results;
    *inStream >> results;
    return results;
}

QList<VoteResult> Event::extractVoteResultsFromRawData()
{
    QList<VoteResult> results;
    *inStream >> results;
    return results;
}

QList<QualificationResult> Event::extractQualificationResultsFromRawData()
{
    QList<QualificationResult> results;
    *inStream >> results;
    return results;
}

QList<FinalResult> Event::extractFinalResultsFromRawData()
{
    QList<FinalResult> results;
    *inStream >> results;
    return results;
}

QList<Team> Event::extractTeamsFromRawData()
{
    QList<Team> teams;
    *inStream >> teams;
    return teams;
}

CheckpointState Event::extractCheckpointStateFromRawData()
{
    quint32 state;
    *inStream >> state;
    return CheckpointState(state);
}

void Event::insertTeams(QList<Team> teams)
{
    *outStream << teams;
}

void Event::insertQuint8(quint8 value)
{
    *outStream << value;
}

void Event::insertQuint32(quint32 value)
{
    *outStream << value;
}

void Event::insertQuint64(quint64 value)
{
    *outStream << value;
}

void Event::insertBool(bool value)
{
    *outStream << value;
}

void Event::insertSpeedRaceResults(QList<SpeedRaceResult> results)
{
    *outStream << results;
}

void Event::insertVoteResults(QList<VoteResult> results)
{
    *outStream << results;
}

void Event::insertSkillRaceResults(QList<SkillRaceResult> results)
{
    *outStream << results;
}

void Event::insertQualificationResuls(QList<QualificationResult> results)
{
    *outStream << results;
}

void Event::insertFinalResults(QList<FinalResult> results)
{
    *outStream << results;
}

void Event::insertCheckpointState(CheckpointState state)
{
    *outStream << state;
}

void Event::insertCheckpointState8bit(CheckpointState state)
{
    quint8 state8 = state;
    *outStream << state8;
}

Event::Event():eventID(0)
{
    outStream = std::make_unique<QDataStream>(&this->rawData,QIODevice::WriteOnly);
    inStream = std::make_unique<QDataStream>(&this->rawData,QIODevice::ReadOnly);

    outStream->setByteOrder(QDataStream::LittleEndian);
    inStream->setByteOrder(QDataStream::LittleEndian);
}

Event::Event(quint32 eventID):eventID(eventID)
{
    outStream = std::make_unique<QDataStream>(&this->rawData,QIODevice::WriteOnly);
    inStream = std::make_unique<QDataStream>(&this->rawData,QIODevice::ReadOnly);
    outStream->setByteOrder(QDataStream::LittleEndian);
    inStream->setByteOrder(QDataStream::LittleEndian);
}

Event::Event(quint32 eventID, const QByteArray &rawData):eventID(eventID),rawData(rawData)
{
    outStream = std::make_unique<QDataStream>(&this->rawData,QIODevice::WriteOnly);
    inStream = std::make_unique<QDataStream>(&this->rawData,QIODevice::ReadOnly);
    outStream->setByteOrder(QDataStream::LittleEndian);
    inStream->setByteOrder(QDataStream::LittleEndian);
}
