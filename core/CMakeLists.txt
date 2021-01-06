cmake_minimum_required(VERSION 3.14)

set (TARGET_NAME "core")

file(GLOB TARGET_HEADERS
    ${CMAKE_SOURCE_DIR}/include/core/*.h
    ${CMAKE_SOURCE_DIR}/include/core/control/*.h
    ${CMAKE_SOURCE_DIR}/include/core/graphics/*.h
    ${CMAKE_SOURCE_DIR}/include/core/interface/*.h
)

file(GLOB TARGET_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/control/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/interface/*.cpp
)

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
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SQLite3 REQUIRED)

add_executable(${TARGET_NAME} ${TARGET_SRC} ${TARGET_HEADERS})

target_include_directories(${TARGET_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/include/core/
    ${CMAKE_SOURCE_DIR}/include/
    ${SDL2_INCLUDE_DIR}
    ${SDL2_TTF_INCLUDE_DIRS}
)

target_link_libraries(${TARGET_NAME} PUBLIC
    "api-service"
    "database"
    ${SDL2_LIBRARY}
    ${SDL2_TTF_LIBRARIES}
    ${SQLITE3_LIBRARIES}
)
