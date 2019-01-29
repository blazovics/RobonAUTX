#ifndef ISOCKETCONNECTIONDELEGATE_H
#define ISOCKETCONNECTIONDELEGATE_H

#include "Event.h"

class ISocketConnectionDelegate{

public:

    virtual void EventReceived(const Event& event) =0;

};

#endif // ISOCKETCONNECTIONDELEGATE_H
