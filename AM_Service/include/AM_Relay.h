#ifndef AM_RELAY_H
#define AM_RELAY_H

#include "AM_Device.h"

class D_Relay : public IDevice {

private:
    int am_write(int voltage);
    bool init();
public:
    D_Relay(int pin);
    ~D_Relay();
};

#endif
