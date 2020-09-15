cmake_minimum_required(VERSION 2.8)

project(api-service)


set(API_SERVICE_INCLUDE_DIRS
    api-service/include
    PARENT_SCOPE
    )

set(API_SERVICE_SOURCE_FILES
    api-service/src/pythonenv.cpp
    api-service/src/pythonref.cpp
    api-service/src/pythonmainthread.cpp
    api-service/src/pythonthread.cpp
    api-service/src/pythonthreadcontroller.cpp
    api-service/src/pythonfunctions.cpp
    PARENT_SCOPE
    )
