#include "gamemenu.h"

GameMenu::GameMenu(int x, int y, unsigned height, unsigned width, unsigned button_height) :
    Interface::Menu(x, y, height, width, button_height)
{

}

GameMenu::~GameMenu()
{

}

void GameMenu::showGames(SDL_Renderer* renderer, std::string db_path)
{
    Database::Connection base(db_path);
    layout.clear();
    widgets.clear();

    auto games = base.getColumn<std::string>("SELECT `name` FROM `games`;");
    for (const auto& name : games)
    {
        Interface::LabeledButton* button = new Interface::LabeledButton //TODO: REMOVE MEMORY LEAK!!!!!!!!!!!!!!!!!!!
        (renderer, name, "../../core/data/testsprite.bmp", "../../core/data/testsprite.bmp",
            "../../core/data/testsprite2.bmp", "../../core/data/testsprite2.bmp");
        pushBack(*button);
    }
}
