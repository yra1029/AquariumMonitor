#include "AM_Relay.h"
#include "AM_Therm.h"
#include "AM_PhResistor.h"

#include <wiringPi.h>
#include <iostream>
#include <boost/filesystem.hpp>
using namespace boost::filesystem;

int main(int argc, char*argv[]) {
   /* try
  {
    std::cout << current_path() << '\n';
    current_path("/usr/local");
    std::cout << current_path() << '\n';
  }
  catch (filesystem_error &e)
  {
    std::cerr << e.what() << '\n';
  }*/
    wiringPiSetup();
    IDevice* relay = new D_Relay(0);
    ISensor* therm = new S_Therm(7);
    ISensor* phRes = new S_PhResistor();

    std::cout << therm->am_read() << std::endl;
    std::cout << phRes->am_read() << std::endl;

    while (1) {
    relay->am_write(HIGH);
    delay(1000);
    relay->am_write(LOW);
    delay(1000);
    std::cout << therm->am_read() << std::endl;
    std::cout << phRes->am_read() << std::endl;
    }
    delete relay;
    delete therm;
    return 0;
}
