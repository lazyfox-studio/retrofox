cmake_minimum_required(VERSION 2.8)

project(database)

find_package(SQLite3 REQUIRED)
if (NOT SQLite3_FOUND)
    message(SEND_ERROR "Failed to find")
    return()
else()
    include_directories(${SQLite3_INCLUDE_DIR})
endif()

include_directories(include)

add_library(database STATIC src/connection.cpp src/statement.cpp)
