cmake_minimum_required(VERSION 2.8)

project(manager)

set(MANAGER_INCLUDE_DIRS
    manager/include
    manager/ui
    PARENT_SCOPE)

set(MANAGER_SOURCE_FILES
    manager/src/main.cpp
    manager/src/mainwindow.cpp
    PARENT_SCOPE
    )

set(MANAGER_UI_FILES
    manager/ui/mainwindow.ui
    )