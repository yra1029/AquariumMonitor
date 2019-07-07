#include "AM_Device.h"
#include "AM_Sensor.h"

#include <thread>
#include <iostream>


void func() {
    std::cout << "Thread worked!!!" << std::endl;
}

int main(int argc, char*argv[]) {
    std::thread t(func);
    t.join();
    return 0;
}
