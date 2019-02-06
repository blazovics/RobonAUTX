/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QString>
#include <QtSql/QSqlDatabase>

#include "Team.h"
#include "SkillRace.h"
#include "SpeedRace.h"
#include "VoteResult.h"
#include "SkillRaceResult.h"
#include "SpeedRaceResult.h"
#include "QualificationResult.h"
#include "FinalResult.h"

class DatabaseManager : public QObject {

    Q_OBJECT
    QSqlDatabase db;

public: 

    explicit DatabaseManager(QString defaultPath = "", QObject *parent = nullptr);
    
    QList<Team> getTeamList();
    Team getTeam(QString name);
    Team getTeam(int id);

    void updateVoteForTeam(unsigned teamID, unsigned voteCount);

    void SaveSkillRace(SkillRace *skillRace, bool aborted);
    void SaveSpeedRace(SpeedRace *speedRace, bool aborted);
    
    QList<VoteResult> GetVoteResults();
    
    QList<SkillRaceResult> GetSkillRaceResults();
    
    QList<SpeedRaceResult> GetSpeedRaceResults(bool isJunior);
    
    QList<QualificationResult> GetQualificationResults();

    QList<FinalResult> GetFinalResults(bool isJunior);

private:
    void openDatabse();

    void saveLap(const Lap &lap, int SpeedRaceID);
    QString getTeamName(int id);

    quint32 calculcateVotePointForPosition(quint32 position);
    quint32 calculcateSpeedPointForPosition(quint32 position);
};

#endif //_DATABASEMANAGER_H
