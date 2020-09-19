#include "entities/scraperdeveloper.h"

namespace Entities
{
    ScraperDeveloper::ScraperDeveloper()
    {
        cache_id = 0;
        developer_id = 0;
    }

    ScraperDeveloper::ScraperDeveloper(const Database::Row& row)
    {
        cache_id = row.column<long>("cache_id");
        developer_id = row.column<long>("developer_id");
    }

    std::vector<ScraperDeveloper> ScraperDeveloper::fetchEntities(Database::Statement& stmt)
    {
        std::vector<ScraperDeveloper> entities;
        Database::Row row;
        while (row = stmt.fetchRow())
            entities.emplace_back(row);
        return entities;
    }
}
