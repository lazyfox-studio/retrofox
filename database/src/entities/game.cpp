#include "entities/game.h"

namespace Entities
{
    Game::Game()
    {
        id = 0;
        platform_id  = 0;
    }

    Game::Game(const Database::Row& row)
    {
        id           = row.column<long>("id");
        path         = row.column<std::string>("path");
        name         = row.column<std::string>("name");
        platform_id  = row.column<long>("platform_id");
        release_date = row.column<std::string>("release_date");
        rating       = row.column<std::string>("rating");
        description  = row.column<std::string>("description");
    }
}
