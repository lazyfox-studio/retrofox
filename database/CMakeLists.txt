cmake_minimum_required(VERSION 2.8)

project(database)

find_package(SQLite3 REQUIRED)
if (NOT SQLITE3_FOUND)
    message(SEND_ERROR "Failed to find SQLITE3")
    return()
else()
    include_directories(${SQLITE3_INCLUDE_DIR})
endif()

include_directories(include)

set(DATABASE_SOURCE_FILES
    src/connection.cpp
    src/row.cpp
    src/statement.cpp
    src/entities/emulator.cpp
    src/entities/game.cpp
    src/entities/platform.cpp
    )

add_library(database STATIC ${DATABASE_SOURCE_FILES})
