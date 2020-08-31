#include "gamemenubutton.h"

GameMenuButton::GameMenuButton(long game_id) : QPushButton(), c_game_id(game_id)
{

}

GameMenuButton::~GameMenuButton()
{

}

long GameMenuButton::gameId()
{
    return c_game_id;
}

void GameMenuButton::showGameWindow()
{
    //Show;
}
