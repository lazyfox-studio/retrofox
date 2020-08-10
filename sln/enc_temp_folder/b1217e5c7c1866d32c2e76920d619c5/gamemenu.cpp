#include "gamemenu.h"

GameMenu::GameMenu(int x, int y, unsigned height, unsigned width, unsigned button_height) :
    Interface::Menu(x, y, height, width, button_height)
{

}

GameMenu::~GameMenu()
{

}

void GameMenu::showGames(SDL_Renderer* renderer, std::string base_path)
{
    Database::Connection base(base_path);
    layout.clear();
    widgets.clear();
    Database::Statement query = base.query("SELECT name FROM 'games';");
    Database::Row row;
    
    while (row = query.fetchRow())
    {
        Interface::LabeledButton* button = new Interface::LabeledButton
            (renderer, row.column<std::string>(0), "../../core/data/testsprite.bmp", "../../core/data/testsprite2.bmp");
        pushBack(*button);
    }
}