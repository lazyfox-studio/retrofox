#include  "gamemenu.h"

GameMenu::GameMenu(QWidget *parent) : QLayout(parent)
{

}

GameMenu::~GameMenu()
{

}

void GameMenu::loadGames(std::string db_path)
{
    Database::Connection base(db_path);
    Database::Statement query;
    Database::Row row;

    query = base.query("SELECT `id`, `path` FROM games ORDER BY `path` ASC");
    while (row = query.fetchRow())
    {
        auto game_button = std::make_shared<GameMenuButton>(row.column<long>("id"));
        game_button->setText(row.column<const char*>("path"));
        addWidget(game_button.get());
        game_buttons.push_back(game_button);
    }
}

void GameMenu::showGameWindow(long game_id)
{
    std::string db_path = "testbase.db";

    Database::Connection base(db_path);
    Database::Statement query;

    query = base.query("SELECT `path`, `name` FROM games WHERE id = ?");
    query.bind(0, game_id);
    Database::Row row = query.fetchRow();

    //Show window;
}
