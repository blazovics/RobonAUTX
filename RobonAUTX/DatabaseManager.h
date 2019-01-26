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
    
    /**
 * @param name
 */
    Team getTeam(QString name);
    
    /**
 * @param id
 */
    Team getTeam(int id);
    
    /**
 * @param teamID
 * @param voteCount
 */
    void updateVoteForTeam(unsigned teamID, unsigned voteCount);
    
    /**
 * @param skillRace
 * @param aborted
 */
    void SaveSkillRace(SkillRace *skillRace, bool aborted);
    
    /**
 * @param speedRace
 * @param aborted
 */
    void SaveSpeedRace(SpeedRace *speedRace, bool aborted);
    
    QList<VoteResult> GetVoteResults();
    
    QList<SkillRaceResult> GetSkillRaceResults();
    
    /**
 * @param isJunior
 */
    QList<SpeedRaceResult> GetSpeedRaceResults(bool isJunior);
    
    QList<QualificationResult> GetQualificationResults();
    
    /**
 * @param isJunior
 */
    QList<FinalResult> GetFinalResults(bool isJunior);

private:
    void openDatabse();
};

#endif //_DATABASEMANAGER_H
