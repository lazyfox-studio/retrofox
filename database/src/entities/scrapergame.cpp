#include "entities/scrapergame.h"

namespace Database
{
    namespace Entities
    {
        ScraperGame::ScraperGame()
        {
            id = 0;
            game_id = 0;
            platform_id = 0;
        }

        ScraperGame::ScraperGame(const Database::Row& row)
        {
            id = row.column<long>("id");
            game_id = row.column<long>("game_id");
            path = row.column<std::string>("path");
            name = row.column<std::string>("name");
            platform_id = row.column<long>("platform_id");
            release_date = row.column<std::string>("release_date");
            rating = row.column<std::string>("rating");
            description = row.column<std::string>("description");
        }

        std::vector<ScraperGame> ScraperGame::fetchEntities(Database::Statement& stmt)
        {
            std::vector<ScraperGame> entities;
            Database::Row row;
            while (row = stmt.fetchRow())
                entities.emplace_back(row);
            return entities;
        }
    }
}