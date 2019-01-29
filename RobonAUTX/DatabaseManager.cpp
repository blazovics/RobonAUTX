/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "DatabaseManager.h"
#include <exception>
#include <QDir>
#include <stdexcept>
#include <QRegExp>
#include "Configuration.h"

#include <QDebug>

#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
/**
 * DatabaseManager implementation
 */


/**
 * @return QList<Team>
 */
DatabaseManager::DatabaseManager(QString path, QObject *parent):QObject (parent)
{
    const Configuration& config = Configuration::GetInstance();

    QString settingsPath = "";

    if(config.IsKeyAvailable("MainSystemSettings","DatabasePath"))
    {
        settingsPath = QString::fromStdString(config.GetStringValue("MainSystemSettings","DatabasePath"));
    }

    QString defaultPath(QDir::home().path());
    defaultPath.append(QDir::separator()).append("robonaut.sqlite");
    defaultPath = QDir::toNativeSeparators(defaultPath);

    if(path.length() != 0 && QFileInfo::exists(path) && path.contains(QRegExp("*.sqlite")))
    {
        db.setDatabaseName(path);
    }
    else if(QFileInfo::exists(settingsPath)) {

        db.setDatabaseName(settingsPath);
    }
    else if(QFileInfo::exists(defaultPath)) {

        db.setDatabaseName(defaultPath);
    }
    else {
        throw std::runtime_error("Unable to load Database file is missing!");
    }
}

QList<Team> DatabaseManager::getTeamList() {
    QList<Team> teams;

    openDatabse();

    QSqlQuery query(QString("SELECT * FROM team ORDER BY TeamID"));

    int teamIDPos = query.record().indexOf("TeamID");
    int namePos = query.record().indexOf("Name");
    int isJuniorPos = query.record().indexOf("IsJunior");
    int audienceVoteCountPos = query.record().indexOf("AudienceVoteCount");
    int qualificationPointPos = query.record().indexOf("QualificationPoint");

    while(query.next()) {
        Team teamItem;

        teamItem.setName(query.value(namePos).toString());
        teamItem.setTeamID(query.value(teamIDPos).toUInt());
        teamItem.setIsJunior(query.value(isJuniorPos).toBool());
        teamItem.setAudienceVoteCount(query.value(audienceVoteCountPos).toUInt());
        teamItem.setQualificationPoint(query.value(qualificationPointPos).toUInt());

        teams.push_back(teamItem);
    }

    db.close();

    return teams;
}

/**
 * @param name
 * @return Team
 */
Team DatabaseManager::getTeam(QString name) {
    Team returnTeam;
    openDatabse();

    QSqlQuery query(QString("SELECT * FROM Team WHERE Name LIKE '%1'").arg(name));

    int teamIDPos = query.record().indexOf("TeamID");
    int namePos = query.record().indexOf("Name");
    int isJuniorPos = query.record().indexOf("IsJunior");
    int audienceVoteCountPos = query.record().indexOf("AudienceVoteCount");
    int qualificationPointPos = query.record().indexOf("QualificationPoint");

    while(query.next()) {
        returnTeam.setName(query.value(namePos).toString());
        returnTeam.setTeamID(query.value(teamIDPos).toUInt());
        returnTeam.setIsJunior(query.value(isJuniorPos).toBool());
        returnTeam.setAudienceVoteCount(query.value(audienceVoteCountPos).toUInt());
        returnTeam.setQualificationPoint(query.value(qualificationPointPos).toUInt());
    }

    db.close();
    return returnTeam;
}

/**
 * @param id
 * @return Team
 */
Team DatabaseManager::getTeam(int id) {
    Team returnTeam;
    openDatabse();

    QSqlQuery query(QString("SELECT * FROM Team WHERE TeamID=%1").arg(id));

    int teamIDPos = query.record().indexOf("TeamID");
    int namePos = query.record().indexOf("Name");
    int isJuniorPos = query.record().indexOf("IsJunior");
    int audienceVoteCountPos = query.record().indexOf("AudienceVoteCount");
    int qualificationPointPos = query.record().indexOf("QualificationPoint");

    while(query.next()) {
        returnTeam.setName(query.value(namePos).toString());
        returnTeam.setTeamID(query.value(teamIDPos).toUInt());
        returnTeam.setIsJunior(query.value(isJuniorPos).toBool());
        returnTeam.setAudienceVoteCount(query.value(audienceVoteCountPos).toUInt());
        returnTeam.setQualificationPoint(query.value(qualificationPointPos).toUInt());
    }

    db.close();
    return returnTeam;
}

/**
 * @param teamID
 * @param voteCount
 */
void DatabaseManager::updateVoteForTeam(unsigned teamID, unsigned voteCount) {
    openDatabse();
    QSqlQuery query;

    query.prepare("UPDATE Team SET AudienceVoteCount = :voteCount WHERE TeamID = :teamid");
    query.bindValue(":voteCount", voteCount);
    query.bindValue(":teamid", teamID);

    if(!query.exec())
    {
        //TODO: EasyLogging
        qDebug()<<"Updating votes failed";
    }

    db.close();
}

/**
 * @param skillRace
 * @param aborted
 */
void DatabaseManager::SaveSkillRace(SkillRace *skillRace, bool aborted) {
    openDatabse();

    db.transaction();

    QSqlQuery query;

    query.prepare("INSERT INTO SkillRace (TeamID, StartSucceeded, LaneChangeSucceeded, CheckpointState, Time, Points, IsAborted)"
                  "VALUES (:TeamID, :StartSucceeded, :LaneChangeSucceeded, :CheckpointState, :Time, :Points, :IsAborted)");

    query.bindValue(":TeamID",skillRace->getTeamID());
    query.bindValue(":StartSucceeded",quint32(skillRace->GetStartSucceeded()));
    query.bindValue(":LaneChangeSucceeded",quint32(skillRace->GetLaneChangeSucceeded()));
    query.bindValue(":CheckpointState",skillRace->GetSerializedCheckpointStates());
    query.bindValue(":Time",skillRace->getRaceTime());
    query.bindValue("Points", skillRace->GetRacePoint());
    query.bindValue(":IsAborted", quint32(aborted));

    if(!query.exec())
    {
        //TODO: EasyLogging
        qDebug()<<"Saving Skill Race failed";
    }
    db.commit();

    db.close();
}

/**
 * @param speedRace
 * @param aborted
 */
void DatabaseManager::SaveSpeedRace(SpeedRace *speedRace, bool aborted) {
    openDatabse();

    db.transaction();

    QSqlQuery query;

    query.prepare("INSERT INTO SpeedRace (TeamID, SafetyCarFollowed, SafetyCarOvertaken, BestLapTime, IsAborted)"
                  "VALUES (:TeamID, :SafetyCarFollowed, :SafetyCarOvertaken, :BestLapTime, :IsAborted)");

    query.bindValue(":TeamID",speedRace->getTeamID());
    query.bindValue(":SafetyCarFollowed",quint32(speedRace->GetSafetyCarFollowed()));
    query.bindValue(":SafetyCarOvertaken",quint32(speedRace->GetSafetyCarOvertaken()));
    query.bindValue(":BestLapTime",speedRace->GetBestLapTime());
    query.bindValue(":IsAborted", quint32(aborted));

    if(!query.exec())
    {
        //TODO: EasyLogging
        qDebug()<<"Saving Speed Race failed";
    }

    int SpeedRaceID = query.lastInsertId().toInt();

    saveLap(speedRace->GetWarmUpLap(),SpeedRaceID);
    const QList<Lap> & laps = speedRace->GetCompletedLaps();

    for(const Lap& lap : laps)
    {
        saveLap(lap, SpeedRaceID);
    }

    db.commit();

    db.close();
}

void DatabaseManager::saveLap(const Lap &lap, int SpeedRaceID)
{
    QSqlQuery query;

    query.prepare("INSERT INTO Lap (SpeedRaceID, LaserTime, ManualTime, SelectedTime, IsWarmUp)"
                  "VALUES (:SpeedRaceID, :LaserTime, :ManualTime, :SelectedTime, :IsWarmUp)");

    query.bindValue(":SpeedRaceID",SpeedRaceID);
    query.bindValue(":LaserTime",lap.laserTime);
    query.bindValue(":ManualTime",lap.manualTime);
    query.bindValue(":SelectedTime",int(lap.choosenLapType));
    query.bindValue(":IsWarmUp", quint32(lap.isWarmUp));

    if(!query.exec())
    {
        //TODO: EasyLogging
        qDebug()<<"Saving Lap failed";
    }
}

quint32 DatabaseManager::calculcateVotePointForPosition(quint32 position)
{
    //TODO: Make it more static
    switch (position) {
    case 1:
        return 10;
    case 2:
        return 7;
    case 3:
        return  4;
    default:
        return  0;
    }
}

/**
 * @return QList<VoteResult>
 */
QList<VoteResult> DatabaseManager::GetVoteResults() {
    QList<VoteResult> returnResult;
    openDatabse();

    QSqlQuery query(QString("SELECT  TeamID, AudienceVoteCount FROM Team ORDER BY AudienceVoteCount DESC"));

    while (query.next()) {
        VoteResult result;
        result.teamID = query.value(0).toUInt();
        result.voteCount = query.value(1).toUInt();
        returnResult.push_back(result);
    }


    for(int i=0, pos = 1; i<returnResult.size(); i++)
    {
        if(i>0 && returnResult[i].voteCount != returnResult[i-1].voteCount)
        {
            pos++;
        }
        returnResult[i].position = quint32(pos);
        returnResult[i].votePoint = this->calculcateVotePointForPosition(returnResult[i].position);
    }

    db.close();
    return returnResult;
}

/**
 * @return Qlist<SkillRaceResult>
 */
QList<SkillRaceResult> DatabaseManager::GetSkillRaceResults() {
    QList<SkillRaceResult> returnResult;
    openDatabse();

    QSqlQuery query(QString("SELECT  TeamID, MAX(Points) As Result FROM SkillRace WHERE IsAborted = 0 GROUP BY teamID ORDER BY Result DESC"));

    while (query.next()) {
        SkillRaceResult result;
        result.teamID = query.value(0).toUInt();
        result.skillPoint = query.value(1).toUInt();
    }


    for(int i=0, pos = 1; i<returnResult.size(); i++)
    {
        if(i>0 && returnResult[i].skillPoint != returnResult[i-1].skillPoint)
        {
            pos++;
        }
        returnResult[i].position = quint32(pos);
    }

    db.close();
    return returnResult;
}

/**
 * @param isJunior
 * @return QList<SpeedRaceResult>
 */
QList<SpeedRaceResult> DatabaseManager::GetSpeedRaceResults(bool isJunior) {
    QList<SpeedRaceResult> returnResult;
    openDatabse();

    QSqlQuery query(QString("SELECT  TeamID, MAX(BestLapTime) As Result FROM SpeedRace WHERE IsAborted = 0 AND TeamID IN (SELECT TeamID From Team WHERE IsJunior = %1) GROUP BY teamID ORDER BY Result DESC").arg(int(isJunior)));

    while (query.next()) {
        SkillRaceResult result;
        result.teamID = query.value(0).toUInt();
        result.skillPoint = query.value(1).toUInt();
    }


    for(int i=0, pos = 1; i<returnResult.size(); i++)
    {
        if(i>0 && returnResult[i].skillPoint != returnResult[i-1].skillPoint)
        {
            pos++;
        }
        returnResult[i].position = quint32(pos);
    }

    db.close();
    return returnResult;
}

/**
 * @return QList<QualificationResult>
 */
QList<QualificationResult> DatabaseManager::GetQualificationResults() {
    QList<QualificationResult> returnResult;
    openDatabse();

    QSqlQuery query(QString("SELECT  TeamID, QualificationPoint FROM Team ORDER BY QualificationPoint DESC"));

    while (query.next()) {
        QualificationResult result;
        result.teamID = query.value(0).toUInt();
        result.qualificationPoint = query.value(1).toUInt();
    }


    for(int i=0, pos = 1; i<returnResult.size(); i++)
    {
        if(i>0 && returnResult[i].qualificationPoint != returnResult[i-1].qualificationPoint)
        {
            pos++;
        }
        returnResult[i].position = quint32(pos);
    }

    db.close();
    return returnResult;
}

/**
 * @param isJunior
 * @return QList<FinalResult>
 */
QList<FinalResult> DatabaseManager::GetFinalResults(bool isJunior) {
    QList<FinalResult> returnResult;
    openDatabse();
    throw "myFunction is not implemented yet.";
    db.close();
    return returnResult;
}

void DatabaseManager::openDatabse()
{
    if(!db.open())
    {
        throw std::runtime_error("Unable to open Database!");
    }

#include <QDir>
}


