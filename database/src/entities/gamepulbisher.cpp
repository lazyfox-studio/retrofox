#include "entities/gamepublisher.h"

namespace Database
{
    namespace Entities
    {
        GamePublisher::GamePublisher()
        {
            game_id = 0;
            publisher_id = 0;
        }

        GamePublisher::GamePublisher(const Database::Row& row)
        {
            game_id = row.column<long>("game_id");
            publisher_id = row.column<long>("publisher_id");
        }

        std::vector<GamePublisher> GamePublisher::fetchEntities(Database::Statement& stmt)
        {
            std::vector<GamePublisher> entities;
            Database::Row row;
            while (row = stmt.fetchRow())
                entities.emplace_back(row);
            return entities;
        }
    }
}
