#!/bin/sh
git clone https://github.com/google/googletest.git
mkdir build_debug/
cd build_debug/
cmake -DCMAKE_BUILD_TYPE=Debug ..