#include "AM_Sensor.h"

#include <functional>


ISensor::ISensor(int pin, int interval) : 
    IElement(pin), timeInterval(interval), running(false) { }

bool ISensor::init_sensor(ISensor* sensor, std::function<void()> startWork) {
    if (sensor->init()) {
        running = true;  
    }
    worker = std::thread(startWork);
}
