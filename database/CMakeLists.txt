cmake_minimum_required(VERSION 3.14)

set (TARGET_NAME "database")

file(GLOB TARGET_HEADERS
    ${CMAKE_SOURCE_DIR}/include/database/*.h
    ${CMAKE_SOURCE_DIR}/include/database/entities/*.h
)

file(GLOB TARGET_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entities/*.cpp
)

find_package(SQLite3 REQUIRED)

add_library(${TARGET_NAME} STATIC ${TARGET_SRC} ${TARGET_HEADERS})

target_include_directories(${TARGET_NAME} 
PUBLIC
    ${CMAKE_SOURCE_DIR}/include/database/
    ${CMAKE_SOURCE_DIR}/include/
    ${SQLite3_INCLUDE_DIRS}
)

target_link_libraries(${TARGET_NAME}
    ${SQLITE3_LIBRARIES}
)
