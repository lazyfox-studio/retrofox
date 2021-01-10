cmake_minimum_required(VERSION 3.14)

set(TARGET_NAME "api-service")

file(GLOB TARGET_HEADERS
    ${CMAKE_SOURCE_DIR}/include/api-service/*.h
)

file(GLOB TARGET_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(${TARGET_NAME} STATIC ${TARGET_SRC} ${TARGET_HEADERS})

target_include_directories(${TARGET_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/include/api-service/
    ${CMAKE_SOURCE_DIR}/include/
    ${Python3_INCLUDE_DIRS}
    ${Python_INCLUDE_DIRS}
    ${Python_LIBRARY_DIRS}
)

if(WIN32)
    target_link_libraries(${TARGET_NAME} PRIVATE Python3::Python)
else(WIN32)
    target_link_libraries(${TARGET_NAME} PRIVATE ${Python_LIBRARIES})
endif(WIN32)
