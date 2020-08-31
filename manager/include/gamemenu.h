#pragma once

#include <QLayout>

#include <list>
#include <memory>
#include <string>

#include "database.h"

#include "gamemenubutton.h"

class GameMenu : public QLayout
{
protected:
    std::list<std::shared_ptr<GameMenuButton>> game_buttons;

public:
    GameMenu(QWidget *parent = Q_NULLPTR);
    ~GameMenu();

    void loadGames(std::string db_path);
};
