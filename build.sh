#!/bin/bash

PROJECT_DIR=`pwd`

if [ ! -d "$PROJECT_DIR"/build ]; then
    mkdir build
fi

export BOOST_ROOT=/home/pi/project/AquariumMonitor/thirdparty/boost_1_61_0

cmake -B./build -H./AM_Service
cd build
make
