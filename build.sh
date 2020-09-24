#!/bin/bash

# Building api-service, core, database
cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=gcc -DCMAKE_CXX_COMPILER:FILEPATH=g++ -B./build -G "Unix Makefiles"
cmake --build ./build --config Debug --target all -- -j 6

# Building manager
