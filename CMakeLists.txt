cmake_minimum_required(VERSION 2.8)


add_subdirectory(api-service)
add_subdirectory(core)
add_subdirectory(database)

include_directories(${API_SERVICE_INCLUDE_DIRS})
include_directories(${CORE_INCLUDE_DIRS})
include_directories(${DATASE_INCLUDE_DIRS})

#Finding libraries
find_package(Python COMPONENTS Interpreter Development REQUIRED)
if (NOT Python_FOUND)
    message(SEND_ERROR "Failed to find Python")
    return()
else()
    include_directories(${Python_INCLUDE_DIRS})
    include_directories(${Python_LIBRARY_DIRS})
    set(Python_LIBRARIES ${Python_LIBRARIES} ${Python_LIBRARY_DIRS}/python38_d.lib)
endif()

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SQLite3 REQUIRED)
if (NOT SQLITE3_FOUND)
    message(SEND_ERROR "Failed to find SQLITE3")
    return()
else()
    include_directories(${SQLITE3_INCLUDE_DIRS})
endif()

set(SDL2_PATH "D:/Libraries/SDL")
find_package(SDL2 REQUIRED)
if (NOT SDL2_FOUND)
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

#Configuring projects
add_library(api-service STATIC ${API_SERVICE_SOURCE_FILES})
add_library(database STATIC ${DATABASE_SOURCE_FILES})

add_executable(retrofox ${CORE_SOURCE_FILES})

target_link_libraries(retrofox database)
target_link_libraries(retrofox api-service)
target_link_libraries(retrofox database ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARIES} ${SQLITE3_LIBRARIES} ${Python_LIBRARIES})