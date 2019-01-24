/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef ISAFETYCAR_H
#define ISAFETYCAR_H


class ISafetyCar{
public: 
    virtual ~ISafetyCar() = 0;

    virtual void startSafetyCar() = 0;
    
    virtual void stopSafetyCar() = 0;
};

#endif //_ISAFETYCAR_H
