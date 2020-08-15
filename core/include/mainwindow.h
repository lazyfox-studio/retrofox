#pragma once

#include "interface/window.h"

#include <SDL.h>

#include "gamemenu.h"

class MainWindow : public Interface::Window
{
public:
    MainWindow() = delete;
    MainWindow(const std::string& title, int x, int y, int width, int height);
    ~MainWindow();

    virtual void initialize();
};
