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

    query = base.query("SELECT `id` `path` FROM games ORDER BY `path` ASC");
    query.execute();
    while (row = query.fetchRow())
    {
        auto game_button = std::make_shared<GameMenuButton>(row.column<long>("id"));
        game_button->setText(row.column<std::string>("path").c_str());
        addWidget(game_button.get());
        game_buttons.push_back(game_button);
    }
}
