cmake_minimum_required(VERSION 2.8)

project(api-service)

find_package(Python COMPONENTS Interpreter Development REQUIRED)
if (NOT Python_FOUND)
    message(SEND_ERROR "Failed to find Python")
    return()
else()
    include_directories(${Python_INCLUDE_DIRS})
    include_directories(${Python_LIBRARY_DIRS})
endif()

include_directories(include)

set(API_SERVICE_SOURCE_FILES
    src/pythonenv.cpp
    src/pythonref.cpp
    )

add_library(api-service STATIC ${API_SERVICE_SOURCE_FILES})
