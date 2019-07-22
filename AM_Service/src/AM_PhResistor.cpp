#include "AM_PhResistor.h"

#include <wiringPi.h>
#include <pcf8591.h>
#include <unistd.h>

S_PhResistor::S_PhResistor(int pin, int interval) : 
  ISensor(pin, interval) { 
    init_sensor(this, std::bind(&S_PhResistor::start_work, this));
}

S_PhResistor::~S_PhResistor() {
    worker.join();
}


bool S_PhResistor::init() {
    if (pcf8591Setup(pin, 0x48) < 0) {
        // TODO Add log
        return false;    
    }
    return true;
}

bool S_PhResistor::internal_read (float& value) {
	int analogVal;
    analogVal = analogRead(pin + 0);

    value = analogVal / VOLTAGE * 255;
    return true;
}

float S_PhResistor::am_read () {

    std::lock_guard<std::mutex> l_lock(lock);
    return luminosity;
}

void S_PhResistor::start_work() {
    int fd;
    float luminValue;

    while (running) {
        
        if (internal_read(luminValue)) {
            std::lock_guard<std::mutex> l_lock(lock);
            luminosity = luminValue;     
        }

            
        sleep(timeInterval);
    }
}
