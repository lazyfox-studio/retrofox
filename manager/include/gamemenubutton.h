#pragma once

#include <QPushButton>

class GameMenuButton : public QPushButton
{
protected:
    const long c_game_id;

public:
    GameMenuButton(long game_id);
    ~GameMenuButton();

    long gameId();

protected:


signals:
    void clicked(bool checked = false);

public slots:
    void showGameWindow();
};
