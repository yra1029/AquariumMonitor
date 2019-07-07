#ifndef AM_SENSOR_H
#define AM_SENSOR_H

#include "AM_Device.h"

class ISensor : public IDevice {

public:
    ISensor(int pin = -1) : IDevice(pin) { }
    virtual int am_read() = 0;
};


#endif
