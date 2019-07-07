#ifndef AM_SENSOR_H
#define AM_SENSOR_H

#include "AM_Element.h"

#include <thread>

class ISensor : public IElement {

protected:
    std::thread worker;
    bool running;   
public:
    ISensor(int pin = -1) : IElement(pin), running(false) { }
    virtual void startWork() = 0;
    virtual float am_read() = 0;
};


#endif
