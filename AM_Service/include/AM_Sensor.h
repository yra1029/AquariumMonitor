#ifndef AM_SENSOR_H
#define AM_SENSOR_H

#include "AM_Element.h"

#include <thread>
#include <mutex>
#include <atomic>
#define DEFAULT_INTERVAL 5
class ISensor : public IElement {

protected:
    std::thread worker;
    bool running;
    int timeInterval;
    std::mutex lock;
    std::atomic<bool> readyToRead{false};

public:
    ISensor(int pin = -1, int interval=DEFAULT_INTERVAL);
    virtual void start_work() = 0;
    virtual float am_read() = 0;
    bool init_sensor(ISensor* sensor, std::function<void()> startWork);
};

#endif
