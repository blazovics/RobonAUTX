/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef IVOTECOUNTER_H
#define IVOTECOUNTER_H

#include <QObject>


class IVoteCounter : public QObject {

public: 

signals:
    void updateVotesForTeam(quint32 teamID, quint32 voteCount);
    
public slots:
    virtual void votesForTeamUpdated(quint32 teamID, quint32 voteCount) = 0;
};

#endif //_IVOTECOUNTER_H
