/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "RemoteVoteCounter.h"

/**
 * RemoteVoteCounter implementation
 */

RemoteVoteCounter::RemoteVoteCounter(CoreController *parentController, QTcpSocket *socket, QIODevice::OpenMode mode):RemoteDevice (parentController,socket,mode)
{

}

void RemoteVoteCounter::EventReceived(Event &event)
{
    switch (event.getEventID()) {

    case Event_updateVotesForTeam :
        emit updateVotesForTeam(event.extractQuint32FromRawData(),event.extractQuint32FromRawData());
        break;
    case Event_fetchVotesForTeam :
        emit fetchVotesForTeam(event.extractQuint32FromRawData());
        break;
    }
}

void RemoteVoteCounter::votesForTeamUpdated(quint32 teamID, quint32 voteCount)
{
    Event event(Event_votesForTeamUpdated);
    event.insertQuint32(teamID);
    event.insertQuint32(voteCount);
    sendEvent(event);
}
