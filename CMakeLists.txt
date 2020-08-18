cmake_minimum_required(VERSION 2.8)

add_subdirectory(core)


find_package(SQLite3 REQUIRED)
if (NOT SQLite3_FOUND)
    message(SEND_ERROR "Failed to find SQLite3")
    return()
else()
    include_directories(${SQLite3_INCLUDE_DIRS})
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

add_subdirectory(database)
include_directories("database/include")

#source files
include_directories(core/include)
set(SOURCE_FILES
    core/src/main.cpp
    core/src/window.cpp
    core/src/gamemenu.cpp
    core/src/graphics/font.cpp
    core/src/graphics/fontbuffer.cpp
    core/src/graphics/sprite.cpp
    core/src/graphics/text.cpp
    core/src/graphics/texture.cpp
    core/src/graphics/texturebuffer.cpp
    core/src/interface/button.cpp
    core/src/interface/label.cpp
    core/src/interface/labeledbutton.cpp
    core/src/interface/layout.cpp
    core/src/interface/menu.cpp
    core/src/interface/paragraph.cpp
    core/src/interface/widget.cpp
    )

add_executable(core ${SOURCE_FILES})

target_link_libraries(core database)
target_link_libraries(core database ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARIES} ${SQLite3_LIBRARIES})