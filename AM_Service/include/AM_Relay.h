#ifndef AM_RELAY_H
#define AM_RELAY_H

#include "AM_Device.h"

class D_Relay : IDevice {

public:
    D_Relay(int pin) : IDevice(pin) { }
    ~D_Relay();
    int init();
    int am_write ();
};

#endif
