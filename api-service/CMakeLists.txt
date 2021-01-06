cmake_minimum_required(VERSION 3.14)

set (TARGET_NAME "api-service")

file(GLOB TARGET_HEADERS
    ${CMAKE_SOURCE_DIR}/include/api-service/*.h
)

file(GLOB TARGET_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

find_package(Python COMPONENTS Interpreter Development REQUIRED)

add_library(${TARGET_NAME} STATIC ${TARGET_SRC} ${TARGET_HEADERS})

target_include_directories(${TARGET_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/include/api-service/
    ${CMAKE_SOURCE_DIR}/include/
    ${Python_INCLUDE_DIRS}
    ${Python_LIBRARY_DIRS}
)

target_link_libraries(${TARGET_NAME} PUBLIC
    ${Python_LIBRARIES}
)
