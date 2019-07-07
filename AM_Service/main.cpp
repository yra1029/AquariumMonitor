#include "AM_Relay.h"

#include <wiringPi.h>


int main(int argc, char*argv[]) {
    wiringPiSetup();
    IDevice* relay = new D_Relay(0);
    while (1) {
    relay->am_write(HIGH);
    delay(1000);
    relay->am_write(LOW);
    delay(1000);
    }
    delete relay;
    return 0;
}
