/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "DatabaseManager.h"
#include <exception>

/**
 * DatabaseManager implementation
 */


/**
 * @return QList<Team>
 */
DatabaseManager::DatabaseManager(QObject *parent):QObject (parent)
{

}

QList<Team> DatabaseManager::getTeamList() {
    QList<Team> teams;
    throw "myFunction is not implemented yet.";
    return teams;
}

/**
 * @param name
 * @return Team
 */
Team DatabaseManager::getTeam(QString name) {
    Team returnTeam;
    throw "myFunction is not implemented yet.";
    return returnTeam;
}

/**
 * @param id
 * @return Team
 */
Team DatabaseManager::getTeam(int id) {
    Team returnTeam;
    throw "myFunction is not implemented yet.";
    return returnTeam;
}

/**
 * @param teamID
 * @param voteCount
 */
void DatabaseManager::updateVoteForTeam(int teamID, int voteCount) {

}

/**
 * @param skillRace
 * @param aborted
 */
void DatabaseManager::SaveSkillRace(SkillRace skillRace, bool aborted) {

}

/**
 * @param speedRace
 * @param aborted
 */
void DatabaseManager::SaveSpeedRace(SpeedRace *speedRace, bool aborted) {

}

/**
 * @return QList<VoteResult>
 */
QList<VoteResult> DatabaseManager::GetVoteResults() {
    QList<VoteResult> returnResult;
    throw "myFunction is not implemented yet.";
    return returnResult;
}

/**
 * @return Qlist<SkillRaceResult>
 */
QList<SkillRaceResult> DatabaseManager::GetSkillRaceResults() {
    QList<SkillRaceResult> returnResult;
    throw "myFunction is not implemented yet.";
    return returnResult;
}

/**
 * @param isJunior
 * @return QList<SpeedRaceResult>
 */
QList<SpeedRaceResult> DatabaseManager::GetSpeedRaceResults(bool isJunior) {
    QList<SpeedRaceResult> returnResult;
    throw "myFunction is not implemented yet.";
    return returnResult;
}

/**
 * @return QList<QualificationResult>
 */
QList<QualificationResult> DatabaseManager::GetQualificationResults() {
    QList<QualificationResult> returnResult;
    throw "myFunction is not implemented yet.";
    return returnResult;
}

/**
 * @param isJunior
 * @return QList<FinalResult>
 */
QList<FinalResult> DatabaseManager::GetFinalResults(bool isJunior) {
    QList<FinalResult> returnResult;
    throw "myFunction is not implemented yet.";
    return returnResult;
}
