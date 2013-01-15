#!/bin/sh
# Used with jansson 2.4
d=${PWD}
if [ ! -d build ] ; then 
    mkdir build 
fi

cd jansson
./configure --prefix=${d}/build --enable-static CFLAGS="-arch i386"
make 
make install