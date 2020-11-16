cmake_minimum_required(VERSION 3.9)
 
project(manager LANGUAGES CXX)
 
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

include_directories("include")
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui" "${CMAKE_CURRENT_SOURCE_DIR}/ui/gamesimportwizard")

set(MANAGER_SOURCE_FILES
    src/aboutdialog.cpp
    src/additionalentities/extendedemulator.cpp
    src/additionalentities/extendedplatform.cpp
    src/emulatoreditdialog.cpp
    src/emulatorlistmodel.cpp
    src/emulatorstablemodel.cpp
    src/gamesimportwizard/dataprocessingpage.cpp
    src/gamesimportwizard/finalpage.cpp
    src/gamesimportwizard/gameselectpage.cpp
    src/gamesimportwizard/pathselectpage.cpp
    src/gamesimportwizard/scrapertablemodel.cpp
    src/gamesimportwizard/shareddata.cpp
    src/gamesimportwizard/welcomepage.cpp
    src/gameeditdialog.cpp
    src/gamesimportwizard/wizard.cpp
    src/gamestablemodel.cpp
    src/main.cpp
    src/mainwindow.cpp
    src/platformeditdialog.cpp
    src/platformlistmodel.cpp
    src/platformstablemodel.cpp
    src/scraper.cpp
    src/scraper/findgamesinformation.cpp
    src/scraper/functions.cpp
    src/scraper/scanfolder.cpp
    )
    
set(MANAGER_HEADER_FILES
    include/aboutdialog.h
    include/additionalentities/extendedemulator.h
    include/additionalentities/extendedplatform.h
    include/emulatoreditdialog.h
    include/emulatorlistmodel.h
    include/emulatorstablemodel.h
    include/gameeditdialog.h
    include/gamesimportwizard/dataprocessingpage.h
    include/gamesimportwizard/finalpage.h
    include/gamesimportwizard/finalpage.h
    include/gamesimportwizard/gameselectpage.h
    include/gamesimportwizard/pages.h
    include/gamesimportwizard/pathselectpage.h
    include/gamesimportwizard/scrapertablemodel.h
    include/gamesimportwizard/shareddata.h
    include/gamesimportwizard/welcomepage.h
    include/gamesimportwizard/wizard.h
    include/gamestablemodel.h
    include/mainwindow.h
    include/platformeditdialog.h
    include//platformlistmodel.h
    include/platformstablemodel.h
    include/scraper.h
    include/scraper/findgamesinformation.h
    include/scraper/functions.h
    include/scraper/scanfolder.h
    )
    
set(MANAGER_UI_FILES
    ui/aboutdialog.ui
    ui/emulatoreditdialog.ui
    ui/gamesimportwizard/dataprocessingpage.ui
    ui/gamesimportwizard/finalpage.ui
    ui/gamesimportwizard/gameselectpage.ui
    ui/gamesimportwizard/pathselectpage.ui
    ui/gamesimportwizard/welcomepage.ui
    ui/gameeditdialog.ui
    ui/mainwindow.ui
    ui/platformeditdialog.ui
    )

add_executable(manager ${MANAGER_SOURCE_FILES} ${MANAGER_HEADER_FILES} ${MANAGER_UI_FILES})

target_link_libraries(manager PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
