/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef IVOTECOUNTER_H
#define IVOTECOUNTER_H

#include <QObject>


class IVoteCounter {
public: 
    virtual ~IVoteCounter() = 0;
    /**
 * @param teamID
 * @param voteCount
 */
    virtual void updateVotesForTeam(quint32 teamID, int voteCount) = 0;
    
    /**
 * @param teamID
 * @param voteCount
 */
    virtual void votesForTeamUpdated(quint32 teamID, int voteCount) = 0;
};

#endif //_IVOTECOUNTER_H
