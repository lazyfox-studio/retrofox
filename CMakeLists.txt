cmake_minimum_required(VERSION 3.9)

project(retrofox LANGUAGES CXX)

# Cofiguring build
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")


# Find modules =========================================================================================================
# Python
find_package(Python COMPONENTS Interpreter Development REQUIRED)
include_directories(${Python_INCLUDE_DIRS})
include_directories(${Python_LIBRARY_DIRS})

# SQlite 3
find_package(SQLite3 REQUIRED)
include_directories(${SQLITE3_INCLUDE_DIRS})

# SDL2
set(SDL2_PATH "D:/Libraries/SDL" "E:/Libraries/SDL")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# SDL2 TTF
set(SDL2_TTF_PATH "D:/Libraries/SDL_ttf" "E:/Libraries/SDL_ttf")
find_package(SDL2_ttf)
include_directories(${SDL2_TTF_INCLUDE_DIRS})

# Qt
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# api-service ==========================================================================================================
set(API_SERVICE_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/api-service
    )

set(API_SERVICE_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/api-service/pythonenv.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/api-service/pythonref.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/api-service/pythonmainthread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/api-service/pythonthread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/api-service/pythonthreadcontroller.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/api-service/pythonfunctions.cpp
    )

# core =================================================================================================================
set(CORE_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/core
    )

set(CORE_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/gamemenu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/gamerunbutton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/scraper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/control/virtualgamepad.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/font.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/fontbuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/sprite.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/text.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/texturebuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/button.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/label.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/labeledbutton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/layout.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/menu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/paragraph.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/widget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/interface/window.cpp
    )

# database =============================================================================================================
set(DATABASE_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/database/include
    )

set(DATABASE_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/database/connection.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/database/row.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/database/statement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/developer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/emulator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/extension.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/game.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/gamedeveloper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/gamegenre.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/gamepublisher.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/genre.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/platform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/publisher.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/scraperdeveloper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/scrapergame.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/scrapergenre.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/scraperpublisher.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database/entities/functions.cpp
    )

# manager ==============================================================================================================
set(MANAGER_INCLUDE_DIRS
    manager/include
    )

set(MANAGER_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/aboutdialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/additionalentities/extendedemulator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/additionalentities/extendedplatform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/emulatoreditdialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/emulatorlistmodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/emulatorstablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/gamesimportwizard/dataprocessingpage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/gamesimportwizard/finalpage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/gamesimportwizard/gameselectpage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/gamesimportwizard/pathselectpage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/gamesimportwizard/scrapertablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/gamesimportwizard/shareddata.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/gamesimportwizard/welcomepage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/gameeditdialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/gamesimportwizard/wizard.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/gamestablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/platformeditdialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/platformlistmodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/platformstablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/scraper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/scraper/findgamesinformation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/scraper/functions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manager/scraper/scanfolder.cpp
    )
    
set(MANAGER_HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/aboutdialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/additionalentities/extendedemulator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/additionalentities/extendedplatform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/emulatoreditdialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/emulatorlistmodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/emulatorstablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/gameeditdialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/gamesimportwizard/dataprocessingpage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/gamesimportwizard/finalpage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/gamesimportwizard/finalpage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/gamesimportwizard/gameselectpage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/gamesimportwizard/pages.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/gamesimportwizard/pathselectpage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/gamesimportwizard/scrapertablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/gamesimportwizard/shareddata.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/gamesimportwizard/welcomepage.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/gamesimportwizard/wizard.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/gamestablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/mainwindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/platformeditdialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/platformlistmodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/platformstablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/scraper.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/scraper/findgamesinformation.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/scraper/functions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/manager/scraper/scanfolder.h
    )
    
set(MANAGER_UI_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/manager/aboutdialog.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/manager/emulatoreditdialog.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/manager/gamesimportwizard/dataprocessingpage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/manager/gamesimportwizard/finalpage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/manager/gamesimportwizard/gameselectpage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/manager/gamesimportwizard/pathselectpage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/manager/gamesimportwizard/welcomepage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/manager/gameeditdialog.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/manager/mainwindow.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/manager/platformeditdialog.ui
    )
    
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui/manager" "${CMAKE_CURRENT_SOURCE_DIR}/ui/manager/gamesimportwizard")

set(MANAGER_RESOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/manager/resources.qrc
    )

# Link =================================================================================================================
add_library(api-service STATIC ${API_SERVICE_SOURCE_FILES})
add_library(database STATIC ${DATABASE_SOURCE_FILES})

target_link_libraries(api-service ${Python_LIBRARIES})
target_link_libraries(database ${SQLite3_LIBRARIES})

add_executable(retrofox ${CORE_SOURCE_FILES})
target_link_libraries(retrofox database)
target_link_libraries(retrofox api-service)
target_link_libraries(retrofox database ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARIES} ${SQLITE3_LIBRARIES} ${Python_LIBRARIES})

add_executable(manager ${MANAGER_SOURCE_FILES} ${MANAGER_HEADER_FILES} ${MANAGER_UI_FILES} ${MANAGER_RESOURCE_FILES})
target_link_libraries(manager api-service database Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)