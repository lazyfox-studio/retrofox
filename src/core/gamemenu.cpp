#include "core/gamemenu.h"

GameMenu::GameMenu(int x, int y, unsigned height, unsigned width, unsigned button_height) 
    : Interface::Menu(x, y, height, width, button_height)
{

}

GameMenu::~GameMenu()
{

}

void GameMenu::showGames(SDL_Renderer* renderer, const std::string& db_path)
{
    Database::Connection base(db_path);
    layout.clear();
    widgets.clear();

    auto query = base.query("SELECT * FROM `games`;");

    auto games = Entities::fetchEntities<Entities::Game>(query);
    for (const auto& game : games)
    {
        auto button = std::make_shared<GameRunButton>
        (renderer, game, "../../core/data/testsprite.bmp", "../../core/data/testsprite.bmp",
            "../../core/data/testsprite2.bmp", "../../core/data/testsprite2.bmp");
        pushBack(button);
    }
}
