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

add_executable(${TARGET_NAME} ${TARGET_SRC} ${TARGET_HEADERS})

target_include_directories(${TARGET_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/include/core/
    ${CMAKE_SOURCE_DIR}/include/
    ${SDL2_INCLUDE_DIR}
    ${SDL2_TTF_INCLUDE_DIRS}
)

target_link_libraries(${TARGET_NAME}
PUBLIC
    "api-service"
    "database"
PRIVATE
    ${SDL2_LIBRARY}
    ${SDL2_TTF_LIBRARIES}
)
