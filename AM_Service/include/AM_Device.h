#ifndef AM_DEVICE_H
#define AM_DEVICE_H

#include "AM_Element.h"

class IDevice : public IElement {

public:
    IDevice(int pin = -1) : IElement(pin) {}
    virtual int am_write(int) = 0;
};

#endif
