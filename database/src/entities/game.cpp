#include "entities/game.h"

namespace Database
{
    namespace Entities
    {
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

        std::vector<Game> Game::fetchEntities(Database::Statement& stmt)
        {
            std::vector<Game> entities;
            Database::Row row;
            while (row = stmt.fetchRow())
                entities.emplace_back(row);
            return entities;
        }
    }
}
