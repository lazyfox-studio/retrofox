cmake_minimum_required(VERSION 2.8)

project(database)


set(DATASE_INCLUDE_DIRS
    database/include
    PARENT_SCOPE)

set(DATABASE_SOURCE_FILES
    database/src/connection.cpp
    database/src/row.cpp
    database/src/statement.cpp
    database/src/entities/emulator.cpp
    database/src/entities/game.cpp
    database/src/entities/platform.cpp
    PARENT_SCOPE
    )
