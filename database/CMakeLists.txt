cmake_minimum_required(VERSION 3.14)

set(TARGET_NAME "database")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

file(GLOB_RECURSE TARGET_HEADERS
    ${CMAKE_SOURCE_DIR}/include/database/*.h
)

file(GLOB_RECURSE TARGET_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(${TARGET_NAME} STATIC ${TARGET_SRC} ${TARGET_HEADERS})

target_include_directories(${TARGET_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/include/database/
    ${CMAKE_SOURCE_DIR}/include/
    ${SQLite3_INCLUDE_DIRS}
)

target_link_libraries(${TARGET_NAME} PRIVATE
    ${SQLite3_LIBRARIES}
PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Sql
)
