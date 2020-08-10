#pragma once

#include "interface/menu.h"

class GameMenu : public Interface::Menu
{
protected:

public:
    GameMenu() = delete;
    GameMenu(int x, int y, unsigned height, unsigned width, unsigned button_height);
    ~GameMenu();
};