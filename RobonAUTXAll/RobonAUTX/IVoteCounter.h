/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef IVOTECOUNTER_H
#define IVOTECOUNTER_H

#include <QObject>

//FIXME: put it somewhere else to be moe robust!
#define Event_updateVotesForTeam 26
#define Event_fetchVotesForTeam 28
#define Event_votesForTeamUpdated 27

class IVoteCounter : public QObject {

    Q_OBJECT

signals:
    void updateVotesForTeam(quint32 teamID, quint32 voteCount);
    void fetchVotesForTeam(quint32 teamID);
    
public slots:
    virtual void votesForTeamUpdated(quint32 teamID, quint32 voteCount) = 0;
};

#endif //_IVOTECOUNTER_H
