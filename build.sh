#!/bin/bash

gyp --depth=. build.gyp
make

rm -f *Makefile*
rm -f *.target.mk
