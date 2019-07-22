cmake_minimum_required(VERSION 2.8.9)
project(AM_Service)

set(Boost_USE_STATIC_LIBS        OFF)  # I've already tried ON
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)


find_package(Boost 1.61 COMPONENTS system filesystem REQUIRED)

include_directories(include ${Boost_INCLUDE_DIRS})

set(SOURCES main.cpp)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -std=c++11")

file(GLOB SOURCES "src/*.cpp")

add_executable(AM_Service ${SOURCES} main.cpp)

target_link_libraries(AM_Service pthread)
target_link_libraries(AM_Service wiringPi)
target_link_libraries(AM_Service ${Boost_LIBRARIES})


