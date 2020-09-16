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
    auto base = Database::Connection("testbase.db");

    auto query = base.query("SELECT * from `platforms` WHERE id = ?;");
    query.bindMany(m_game.platform_id);
    Database::Entities::Platform platform = Database::Entities::Platform::fetchEntities(query)[0];

    query = base.query("SELECT * from `emulators` WHERE id = ?");
    query.bindMany(platform.default_emulator_id);
    Database::Entities::Emulator emulator = Database::Entities::Emulator::fetchEntities(query)[0];

    std::string command;
    command += emulator.emulator_path + ' ' + emulator.execution_parameters;
    command.replace(command.find("%ROM%"), std::string("%ROM%").length(), m_game.path);

    system(command.c_str());

    std::cout << command;
}
