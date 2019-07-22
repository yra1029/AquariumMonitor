#ifndef AM_THERM_H
#define AM_THERM_H

#include <mutex>
#include <atomic>
#include <string>

#include "AM_Sensor.h"

#define DEFAULT_INTERVAL 5

class S_Therm : public ISensor {

private:
    const char* sensorFile1 = "/sys/bus/w1/devices/28-00000a29da2b/w1_slave";
    std::string sensorFile;
    float temperature = 0.0f;

    bool internal_read(int fd, float& value);
    std::string get_sensor_file();
public:
    S_Therm(int pin = -1, int interval = DEFAULT_INTERVAL);
    ~S_Therm();
    void start_work();
    bool init();
    float am_read();
};


#endif
