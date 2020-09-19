#pragma once

#include <string>

#include "database/connection.h"
#include "database/row.h"
#include "database/statement.h"
#include "entities/developer.h"
#include "entities/gamedeveloper.h"
#include "entities/gamegenre.h"
#include "entities/gamepublisher.h"
#include "entities/genre.h"
#include "entities/publisher.h"

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

    std::vector<Genre> findGenres(std::vector<GameDeveloper> game_genres, std::string path_to_db);

    std::vector<Publisher> findPublishers(std::vector<GameDeveloper> game_publishers, std::string path_to_db);
}
