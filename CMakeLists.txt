cmake_minimum_required(VERSION 3.9)

project(retrofox LANGUAGES CXX)

# Cofiguring build
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Find modules
find_package(Python COMPONENTS Interpreter Development REQUIRED)

find_package(SQLite3 REQUIRED)

set(SDL2_PATH "D:/Libraries/SDL" "E:/Libraries/SDL")
find_package(SDL2 REQUIRED)

set(SDL2_TTF_PATH "D:/Libraries/SDL_ttf" "E:/Libraries/SDL_ttf")
find_package(SDL2_ttf)
