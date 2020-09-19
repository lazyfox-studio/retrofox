#pragma once

#include "database/row.h"
#include "database/statement.h"

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
}
