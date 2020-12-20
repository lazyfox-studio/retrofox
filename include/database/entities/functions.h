#pragma once

#include <string>

#include "database/database/connection.h"
#include "database/database/row.h"
#include "database/database/statement.h"
#include "database/entities/developer.h"
#include "database/entities/gamedeveloper.h"
#include "database/entities/gamegenre.h"
#include "database/entities/gamepublisher.h"
#include "database/entities/genre.h"
#include "database/entities/publisher.h"

namespace Entities
{
    /**
     * @brief Fetches all rows and extracts entities data from them into vector
     * @param stmt Statement with SELECT query
     * @return Vector with entities of EntityType
     */
    template<typename EntityType>
    std::vector<EntityType> fetchEntities(Database::Statement& stmt)
    {
        std::vector<EntityType> entities;
        Database::Row row;
        while (row = stmt.fetchRow())
            entities.emplace_back(row);
        return entities;
    }

    std::vector<Developer> findDevelopers(std::vector<GameDeveloper> game_developers, std::string path_to_db);

    std::vector<Genre> findGenres(std::vector<GameGenre> game_genres, std::string path_to_db);

    std::vector<Publisher> findPublishers(std::vector<GamePublisher> game_publishers, std::string path_to_db);
}
