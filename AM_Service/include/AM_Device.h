#ifndef AM_DEVICE_H
#define AM_DEVICE_H

class IDevice {

private:
    int pin;

public:
    IDevice(int tpin) : pin(tpin) {}
    virtual ~IDevice() {};
    virtual void init() = 0;
    virtual int  am_write() = 0;
    int getPin() { return pin; }
};

#endif
