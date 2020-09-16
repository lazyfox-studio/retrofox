#include "gamerunbutton.h"

GameRunButton::GameRunButton(
    SDL_Renderer* renderer,
    Database::Entities::Game game,
    const std::string& path_default,
    const std::string& path_clicked,
    const std::string& path_hovered,
    const std::string& path_disabled
) : LabeledButton(renderer, game.name, path_default, path_clicked, path_hovered, path_disabled), m_game(game)
{

}

GameRunButton::GameRunButton(SDL_Renderer* renderer, Database::Entities::Game game, const std::string& path_default,
    const std::string& path_clicked) : LabeledButton(renderer, game.name, path_default, path_clicked), m_game(game)
{

}

void GameRunButton::onClick()
{
    std::cout << "do magick!";
}
