cmake_minimum_required(VERSION 3.9)


# Configuring build
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(api-service)
add_subdirectory(core)
add_subdirectory(database)
add_subdirectory(manager)

include_directories(${API_SERVICE_INCLUDE_DIRS})
include_directories(${CORE_INCLUDE_DIRS})
include_directories(${DATABASE_INCLUDE_DIRS})
include_directories(${MANAGER_INCLUDE_DIRS})

set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/manager/ui" "${CMAKE_CURRENT_SOURCE_DIR}/manager/ui/gamesimportwizard")

# Finding libraries
find_package(Python COMPONENTS Interpreter Development REQUIRED)
if (NOT Python_FOUND)
    message(SEND_ERROR "Failed to find Python")
    return()
else()
    include_directories(${Python_INCLUDE_DIRS})
    include_directories(${Python_LIBRARY_DIRS})
endif()

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SQLite3 REQUIRED)
if (NOT SQLITE3_FOUND)
    message(SEND_ERROR "Failed to find SQLITE3")
    return()
else()
    include_directories(${SQLITE3_INCLUDE_DIRS})
endif()

set(SDL2_PATH "D:/Libraries/SDL" "E:/Libraries/SDL")
find_package(SDL2 REQUIRED)
if (NOT SDL2_FOUND)
    message(SEND_ERROR "Failed to find SDL2")
    return()
else()
    include_directories(${SDL2_INCLUDE_DIR})
endif()

set(SDL2_TTF_PATH "D:/Libraries/SDL_ttf" "E:/Libraries/SDL_ttf")
find_package(SDL2_ttf)
if (NOT SDL2_TTF_FOUND)
    message(SEND_ERROR "Failed to find SDL2_ttf")
    return()
else()
include_directories(${SDL2_TTF_INCLUDE_DIRS})
endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


# Configuring libraries
add_library(api-service STATIC ${API_SERVICE_SOURCE_FILES})
add_library(database STATIC ${DATABASE_SOURCE_FILES})

# Configuring retrofox
add_executable(retrofox ${CORE_SOURCE_FILES})

target_link_libraries(retrofox database)
target_link_libraries(retrofox api-service)
target_link_libraries(retrofox database ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARIES} ${SQLITE3_LIBRARIES} ${Python_LIBRARIES})

# Configuring manager
#add_executable(manager ${MANAGER_SOURCE_FILES} ${MANAGER_HEADER_FILES} ${MANAGER_UI_FILES})
#target_link_libraries(manager database api-service Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)
