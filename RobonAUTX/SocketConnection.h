/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef SOCKETCONNECTION_H
#define SOCKETCONNECTION_H

class SocketConnection {
public: 
    
/**
 * @param event
 */
void sendEvent(Event event);
    
/**
 * @param event
 */
void messageReceived(Event event);
};

#endif //_SOCKETCONNECTION_H