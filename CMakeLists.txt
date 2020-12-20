cmake_minimum_required(VERSION 3.9)

project(retrofox LANGUAGES CXX)

# Cofiguring build
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")


# Find modules =========================================================================================================
find_package(Python COMPONENTS Interpreter Development REQUIRED)
include_directories(${Python_INCLUDE_DIRS})
include_directories(${Python_LIBRARY_DIRS})

find_package(SQLite3 REQUIRED)
include_directories(${SQLITE3_INCLUDE_DIRS})

set(SDL2_PATH "D:/Libraries/SDL" "E:/Libraries/SDL")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SDL2_TTF_PATH "D:/Libraries/SDL_ttf" "E:/Libraries/SDL_ttf")
find_package(SDL2_ttf)
include_directories(${SDL2_TTF_INCLUDE_DIRS})


# api-service ==========================================================================================================
set(API_SERVICE_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/api-service
    )

set(API_SERVICE_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/api-service/pythonenv.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/api-service/pythonref.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/api-service/pythonmainthread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/api-service/pythonthread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/api-service/pythonthreadcontroller.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/api-service/pythonfunctions.cpp
    )

# core =================================================================================================================
set(CORE_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/core
    )

set(CORE_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/gamemenu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/gamerunbutton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/scraper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/control/virtualgamepad.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/font.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/fontbuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/sprite.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/text.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/texturebuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/button.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/label.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/labeledbutton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/layout.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/menu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/paragraph.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/widget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/window.cpp
    )

# database =============================================================================================================
set(DATABASE_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/database/include
    )

set(DATABASE_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/database/connection.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/database/row.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/database/statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/developer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/emulator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/extension.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/game.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/gamedeveloper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/gamegenre.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/gamepublisher.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/genre.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/platform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/publisher.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/scraperdeveloper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/scrapergame.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/scrapergenre.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/scraperpublisher.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/functions.cpp
    )


# Link =================================================================================================================
add_library(api-service STATIC ${API_SERVICE_SOURCE_FILES})
add_library(database STATIC ${DATABASE_SOURCE_FILES})

target_link_libraries(api-service ${Python_LIBRARIES})
target_link_libraries(database ${SQLITE3_LIBRARIES})

add_executable(retrofox ${CORE_SOURCE_FILES})
target_link_libraries(retrofox database)
target_link_libraries(retrofox api-service)
target_link_libraries(retrofox database ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARIES} ${SQLITE3_LIBRARIES} ${Python_LIBRARIES})