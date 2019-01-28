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

    query.exec();

    db.close();
}

/**
 * @param skillRace
 * @param aborted
 */
void DatabaseManager::SaveSkillRace(SkillRace *skillRace, bool aborted) {
    openDatabse();
    throw "myFunction is not implemented yet.";
    db.close();
}

/**
 * @param speedRace
 * @param aborted
 */
void DatabaseManager::SaveSpeedRace(SpeedRace *speedRace, bool aborted) {
    openDatabse();
    throw "myFunction is not implemented yet.";
    db.close();
}

/**
 * @return QList<VoteResult>
 */
QList<VoteResult> DatabaseManager::GetVoteResults() {
    QList<VoteResult> returnResult;
    openDatabse();
    throw "myFunction is not implemented yet.";
    db.close();
    return returnResult;
}

/**
 * @return Qlist<SkillRaceResult>
 */
QList<SkillRaceResult> DatabaseManager::GetSkillRaceResults() {
    QList<SkillRaceResult> returnResult;
    openDatabse();
    throw "myFunction is not implemented yet.";
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
    throw "myFunction is not implemented yet.";
    db.close();
    return returnResult;
}

/**
 * @return QList<QualificationResult>
 */
QList<QualificationResult> DatabaseManager::GetQualificationResults() {
    QList<QualificationResult> returnResult;
    openDatabse();
    throw "myFunction is not implemented yet.";
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
