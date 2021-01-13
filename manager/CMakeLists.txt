cmake_minimum_required(VERSION 3.14)

set(TARGET_NAME "manager")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui" "${CMAKE_CURRENT_SOURCE_DIR}/ui/gamesimportwizard")

file(GLOB_RECURSE TARGET_HEADERS
    ${CMAKE_SOURCE_DIR}/include/manager/*.h
)

file(GLOB_RECURSE TARGET_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE TARGET_UI_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui
)

file(GLOB_RECURSE TARGET_RESOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/resources.qrc
)

add_executable(${TARGET_NAME} ${TARGET_SRC} ${TARGET_HEADERS} ${TARGET_UI_FILES} ${TARGET_RESOURCES})

target_include_directories(${TARGET_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/include/manager/
    ${CMAKE_SOURCE_DIR}/include/
)

target_link_libraries(${TARGET_NAME}
PUBLIC
    "api-service"
    "database"
PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)
