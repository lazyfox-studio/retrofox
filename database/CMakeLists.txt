cmake_minimum_required(VERSION 2.8)

project(database)


set(DATABASE_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    PARENT_SCOPE)

set(DATABASE_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/connection.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/row.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/developer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/emulator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/extension.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/game.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/gamedeveloper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/gamegenre.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/gamepublisher.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/genre.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/platform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/publisher.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/scraperdeveloper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/scrapergame.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/scrapergenre.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/scraperpublisher.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/functions.cpp
    PARENT_SCOPE
    )
