#include "AM_Relay.h"
#include <wiringPi.h>

D_Relay::D_Relay(int pin) : IDevice(pin) { 
    init();
}

D_Relay::~D_Relay() {

}


bool D_Relay::init() {
    if (pin == -1) {
        // here should be a log
        return -1;
    }
    pinMode(pin, OUTPUT);
}

int D_Relay::am_write (int voltage) {
    digitalWrite(pin, voltage);
}

