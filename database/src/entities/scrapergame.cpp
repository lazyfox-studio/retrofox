#include "entities/scrapergame.h"

namespace Database
{
    namespace Entities
    {
        ScraperGame::ScraperGame()
        {
            id = 0;
            game_id = 0;
        }

        ScraperGame::ScraperGame(const Database::Row& row)
        {
            id = row.column<long>("id");
            game_id = row.column<long>("game_id");
            name = row.column<std::string>("name");
            release_date = row.column<std::string>("release_date");
            rating = row.column<std::string>("rating");
            description = row.column<std::string>("description");
        }

        std::vector<ScraperGame> ScraperGame::fetchEntities(Database::Statement& stmt)
        {
            std::vector<ScraperGame> entities;
            Database::Row row;
            while (row = stmt.fetchRow())
                entities.emplace_back(ScraperGame(row));
            return entities;
        }
    }
}