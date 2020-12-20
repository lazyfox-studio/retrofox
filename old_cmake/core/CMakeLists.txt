cmake_minimum_required(VERSION 2.8)

project(core)


set(CORE_INCLUDE_DIRS
    core/include
    PARENT_SCOPE
    )

set(CORE_SOURCE_FILES
    core/src/gamemenu.cpp
    core/src/gamerunbutton.cpp
    core/src/main.cpp
    core/src/mainwindow.cpp
    core/src/scraper.cpp
    core/src/control/virtualgamepad.cpp
    core/src/graphics/font.cpp
    core/src/graphics/fontbuffer.cpp
    core/src/graphics/sprite.cpp
    core/src/graphics/text.cpp
    core/src/graphics/texture.cpp
    core/src/graphics/texturebuffer.cpp
    core/src/interface/button.cpp
    core/src/interface/label.cpp
    core/src/interface/labeledbutton.cpp
    core/src/interface/layout.cpp
    core/src/interface/menu.cpp
    core/src/interface/paragraph.cpp
    core/src/interface/widget.cpp
    core/src/interface/window.cpp
    PARENT_SCOPE
    )
