cmake_minimum_required(VERSION 3.14)

project(retrofox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(SDL2_PATH
    "D:/Libraries/SDL"
    "E:/Libraries/SDL"
    "A:/libraries/SDL"
)
set(SDL2_TTF_PATH
    "D:/Libraries/SDL_ttf"
    "E:/Libraries/SDL_ttf"
    "A:/libraries/SDL_ttf"
)

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(SQLite3 REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick LinguistTools Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick LinguistTools Widgets REQUIRED)

add_subdirectory(api-service)
add_subdirectory(database)
add_subdirectory(app)
add_subdirectory(core)
add_subdirectory(manager)
