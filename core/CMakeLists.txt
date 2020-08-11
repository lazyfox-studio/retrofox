cmake_minimum_required(VERSION 2.8)

project(core)

find_package(SQLite3 REQUIRED)
if (NOT SQLite3_FOUND)
    message(SEND_ERROR "Failed to find SQLite3")
    return()
else()
    include_directories(${SQLite3_INCLUDE_DIR})
endif()

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${core_SOURCE_DIR}/cmake")

set(SDL2_PATH "D:/Libraries/SDL")
find_package(SDL2 REQUIRED)
if (NOT SQLite3_FOUND)
    message(SEND_ERROR "Failed to find SDL2")
    return()
else()
    include_directories(${SDL2_INCLUDE_DIR})
endif()

set(SDL2_TTF_PATH "D:/Libraries/SDL_ttf")
find_package(SDL2_ttf)
if (NOT SDL2_TTF_FOUND)
    message(SEND_ERROR "Failed to find SDL2_ttf")
    return()
else()
include_directories(${SDL2_TTF_INCLUDE_DIRS})
endif()

include_directories("../database/include")
add_library(database STATIC IMPORTED)
set_property(TARGET database PROPERTY
             IMPORTED_LOCATION D:/Source/retrofox/sln/x64/Debug/database.lib)

include_directories(include)

#source files
set(SOURCE_FILES src/main.cpp
    src/window.cpp
    src/gamemenu.cpp
    src/graphics/font.cpp
    src/graphics/fontbuffer.cpp
    src/graphics/sprite.cpp
    src/graphics/text.cpp
    src/graphics/texture.cpp
    src/graphics/texturebuffer.cpp
    src/interface/button.cpp
    src/interface/label.cpp
    src/interface/layout.cpp
    src/interface/menu.cpp
    src/interface/paragraph.cpp
    src/interface/widget.cpp
    ) 

add_executable(core ${SOURCE_FILES})

target_link_libraries(core database ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARIES})