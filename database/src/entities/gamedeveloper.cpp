#include "entities/gamedeveloper.h"

namespace Database
{
    namespace Entities
    {
        GameDeveloper::GameDeveloper()
        {
            game_id = 0;
            developer_id = 0;
        }

        GameDeveloper::GameDeveloper(const Database::Row& row)
        {
            game_id = row.column<long>("game_id");
            developer_id = row.column<long>("developer_id");
        }

        std::vector<GameDeveloper> GameDeveloper::fetchEntities(Database::Statement& stmt)
        {
            std::vector<GameDeveloper> entities;
            Database::Row row;
            while (row = stmt.fetchRow())
                entities.emplace_back(row);
            return entities;
        }
    }
}
