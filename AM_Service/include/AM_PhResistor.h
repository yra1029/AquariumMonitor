#ifndef AM_PHOTO_RES_H
#define AM_PHOTO_RES_H

#include <mutex>
#include <atomic>

#include "AM_Sensor.h"

#define DEFAULT_INTERVAL 5
#define DEFAULT_PCF_PIN 120
#define VOLTAGE 3.3

class S_PhResistor : public ISensor {

private:
    float luminosity = 0.0f;
    
    bool internal_read(float& value);
public:
    S_PhResistor(int pin = DEFAULT_PCF_PIN, int interval = DEFAULT_INTERVAL);
    ~S_PhResistor();
    void start_work();
    bool init();
    float am_read();
};


#endif
