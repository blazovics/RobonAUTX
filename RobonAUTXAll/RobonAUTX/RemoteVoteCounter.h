/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef REMOTEVOTECOUNTER_H
#define REMOTEVOTECOUNTER_H

#include "IVoteCounter.h"
#include "RemoteDevice.h"

class RemoteVoteCounter: public IVoteCounter, public RemoteDevice {

    Q_OBJECT

public:
    explicit RemoteVoteCounter(CoreController* parentController, QTcpSocket *socket, QIODevice::OpenMode mode = QIODevice::WriteOnly);

    void EventReceived(Event& event);

public slots:

    void votesForTeamUpdated(quint32 teamID, quint32 voteCount);
};

#endif //_REMOTEVOTECOUNTER_H
