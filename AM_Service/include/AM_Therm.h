#ifndef AM_THERM_H
#define AM_THERM_H

#include "AM_Sensor.h"

#define DEFAULT_INTERVAL 5000

class S_Therm : public ISensor {

private:
    const char* sensorFile = "/sys/bus/w1/devices/28-031467805fff/w1_slave";
    float temperature = 0.0f;
    int timeInterval;

    bool _am_read(int fd, float& value);
public:
    S_Therm(int pin = -1, int interval = DEFAULT_INTERVAL);
    ~S_Therm();
    void startWork();
    bool init();
    float am_read();
};


#endif
