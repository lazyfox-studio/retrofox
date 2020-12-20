cmake_minimum_required(VERSION 3.9)
 
project(manager LANGUAGES CXX)
 
# Configuring build
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../database database_build)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../api-service api-service_build)

include_directories(${API_SERVICE_INCLUDE_DIRS})
include_directories(${DATABASE_INCLUDE_DIRS})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

# Configuring files 
set(MANAGER_INCLUDE_DIRS
    include
    )

set(MANAGER_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/aboutdialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/additionalentities/extendedemulator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/additionalentities/extendedplatform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/emulatoreditdialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/emulatorlistmodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/emulatorstablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gamesimportwizard/dataprocessingpage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gamesimportwizard/finalpage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gamesimportwizard/gameselectpage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gamesimportwizard/pathselectpage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gamesimportwizard/scrapertablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gamesimportwizard/shareddata.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gamesimportwizard/welcomepage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gameeditdialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gamesimportwizard/wizard.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gamestablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platformeditdialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platformlistmodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platformstablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/scraper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/scraper/findgamesinformation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/scraper/functions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/scraper/scanfolder.cpp
    )
    
set(MANAGER_HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/aboutdialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/additionalentities/extendedemulator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/additionalentities/extendedplatform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/emulatoreditdialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/emulatorlistmodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/emulatorstablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gameeditdialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gamesimportwizard/dataprocessingpage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gamesimportwizard/finalpage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gamesimportwizard/finalpage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gamesimportwizard/gameselectpage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gamesimportwizard/pages.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gamesimportwizard/pathselectpage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gamesimportwizard/scrapertablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gamesimportwizard/shareddata.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gamesimportwizard/welcomepage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gamesimportwizard/wizard.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gamestablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/mainwindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/platformeditdialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include//platformlistmodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/platformstablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/scraper.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/scraper/findgamesinformation.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/scraper/functions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/scraper/scanfolder.h
    )
    
set(MANAGER_UI_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/aboutdialog.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/emulatoreditdialog.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/gamesimportwizard/dataprocessingpage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/gamesimportwizard/finalpage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/gamesimportwizard/gameselectpage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/gamesimportwizard/pathselectpage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/gamesimportwizard/welcomepage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/gameeditdialog.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/mainwindow.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/platformeditdialog.ui
    )
    
set(MANAGER_RESOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/resources.qrc
    )

# Configuring directories
include_directories(${MANAGER_INCLUDE_DIRS})
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui" "${CMAKE_CURRENT_SOURCE_DIR}/ui/gamesimportwizard")

# Finding SQLite3
find_package(SQLite3 REQUIRED)
if (NOT SQLITE3_FOUND)
    message(SEND_ERROR "Failed to find SQLITE3")
    return()
else()
    include_directories(${SQLITE3_INCLUDE_DIRS})
endif()

# Finding Python
find_package(Python COMPONENTS Interpreter Development REQUIRED)
if (NOT Python_FOUND)
    message(SEND_ERROR "Failed to find Python")
    return()
else()
    include_directories(${Python_INCLUDE_DIRS})
    include_directories(${Python_LIBRARY_DIRS})
endif()

# Finding Qt
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# Configuring libraries
add_library(api-service STATIC ${API_SERVICE_SOURCE_FILES})
add_library(database STATIC ${DATABASE_SOURCE_FILES})

target_link_libraries(api-service ${Python_LIBRARIES})
target_link_libraries(database ${SQLITE3_LIBRARIES})


# Configuring manager
add_executable(manager ${MANAGER_SOURCE_FILES} ${MANAGER_HEADER_FILES} ${MANAGER_UI_FILES} ${MANAGER_RESOURCE_FILES})
target_link_libraries(manager api-service database Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)
