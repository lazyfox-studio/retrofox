cmake_minimum_required(VERSION 2.8)

project(database)


set(DATABASE_INCLUDE_DIRS
    database/include
    PARENT_SCOPE)

set(DATABASE_SOURCE_FILES
    database/src/database/connection.cpp
    database/src/database/row.cpp
    database/src/database/statement.cpp
    database/src/entities/emulator.cpp
    database/src/entities/extension.cpp
    database/src/entities/game.cpp
    database/src/entities/gamedeveloper.cpp
    database/src/entities/gamegenre.cpp
    database/src/entities/gamepublisher.cpp
    database/src/entities/platform.cpp
    database/src/entities/scraperdeveloper.cpp
    database/src/entities/scrapergame.cpp
    database/src/entities/scrapergenre.cpp
    database/src/entities/scraperpublisher.cpp
    database/src/entities/functions.cpp
    PARENT_SCOPE
    )
