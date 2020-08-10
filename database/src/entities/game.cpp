#include "entities/game.h"

namespace Database
{
    namespace Entities
    {
        Game::Game(const Database::Row& row)
        {
            id = row.column<unsigned>("id");
            path = row.column<std::string>("path");
            name = row.column<std::string>("name");
            platform_id = row.column<unsigned>("platform_id");
            developer = row.column<std::string>("developer");
            publisher = row.column<std::string>("publisher");
            release_date = row.column<std::string>("release_date");
            genre = row.column<std::string>("genre");
            rating = row.column<float>("rating");
            description = row.column<std::string>("description");
            boxart = row.column<std::string>("boxart");
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
