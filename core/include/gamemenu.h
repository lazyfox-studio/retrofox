#pragma once

#include "interface/menu.h"

#include <memory>
#include <string>

#include <database.h>

#include "interface/labeledbutton.h"

class GameMenu : public Interface::Menu
{
protected:

public:
    GameMenu() = delete;
    GameMenu(int x, int y, unsigned height, unsigned width, unsigned button_height);
    ~GameMenu();

    void showGames(SDL_Renderer* renderer, std::string db_path);
};
