#pragma once

#include "database/row.h"
#include "database/statement.h"

namespace Entities
{
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
