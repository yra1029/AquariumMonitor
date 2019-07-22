#include "AM_Therm.h"

#include <wiringPi.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <functional>

#define BUFSIZE 128
#define RESSIZE   5

S_Therm::S_Therm(int pin, int interval) : 
  ISensor(pin, interval){
    init_sensor(this, std::bind(&S_Therm::start_work, this));
}

S_Therm::~S_Therm() {
    worker.join();
}


bool S_Therm::init() {
    
    // add dynamic /sys/device name finder
    
    return true;
}

bool S_Therm::internal_read (int fd, float& value) {
	int  ret;
	char readBuf[BUFSIZE];
	char resBuf[RESSIZE];


	while(1){
		ret = read(fd, readBuf, BUFSIZE);
		if(ret == 0){
			break;	
		}
		if(ret == -1){
			if(errno == EINTR) {
				continue;	
			}
			perror("read()");
			close(fd);
			return false;
		}
	}

	for(auto i = 0; i < sizeof(readBuf); i++) {
		if(readBuf[i] == 't'){
			for(auto j = 0; j < sizeof(resBuf); j++) {
				resBuf[j] = readBuf[i + 2 + j];	
			}
		}	
	}

	value = static_cast<float>(atoi(resBuf)) / 1000;
    return true;
}

float S_Therm::am_read () {
    std::lock_guard<std::mutex> l_lock(lock);
    return temperature;
}

void S_Therm::start_work() {
    int fd;
    float temperValue;

    while (running) {
        fd = open(sensorFile.c_str(), O_RDONLY);
        if(fd == -1) {
	    	perror("open device file error");
	    	running = false;
            break;
	    }
        
        if (internal_read(fd, temperValue)) {
            std::lock_guard<std::mutex> l_lock(lock);
            temperature = temperValue;     
        }

        close(fd);
            
        sleep(timeInterval);
    }
}
