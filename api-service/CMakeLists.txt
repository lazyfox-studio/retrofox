cmake_minimum_required(VERSION 2.8)

project(api-service)


set(API_SERVICE_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    PARENT_SCOPE
    )

set(API_SERVICE_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pythonenv.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pythonref.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pythonmainthread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pythonthread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pythonthreadcontroller.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pythonfunctions.cpp
    PARENT_SCOPE
    )
