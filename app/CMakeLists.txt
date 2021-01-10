cmake_minimum_required(VERSION 3.14)

set(TARGET_NAME "app")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

file(GLOB TARGET_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

set(TARGET_TS_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/translations/app_en_US.ts
)

set(TARGET_RESOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/qml.qrc
)

add_executable(${TARGET_NAME} ${TARGET_SRC} ${TARGET_TS_FILES} ${TARGET_RESOURCES})

target_include_directories(${TARGET_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/include/app/
    ${CMAKE_SOURCE_DIR}/include/
)

target_compile_definitions(${TARGET_NAME} PRIVATE
    $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)

target_link_libraries(${TARGET_NAME}
PUBLIC
    "api-service"
    "database"
PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
)

qt5_create_translation(QM_FILES "${CMAKE_CURRENT_SOURCE_DIR}/translations" ${TARGET_TS_FILES})

if(WIN32)
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Qt5::Qml>
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}"
    )
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Qt5::Quick>
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}"
    )
endif()