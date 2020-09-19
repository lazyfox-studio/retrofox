#include "entities/scrapergenre.h"

namespace Entities
{
    ScraperGenre::ScraperGenre()
    {
        cache_id = 0;
        genre_id = 0;
    }

    ScraperGenre::ScraperGenre(const Database::Row& row)
    {
        cache_id = row.column<long>("cache_id");
        genre_id = row.column<long>("genre_id");
    }

    std::vector<ScraperGenre> ScraperGenre::fetchEntities(Database::Statement& stmt)
    {
        std::vector<ScraperGenre> entities;
        Database::Row row;
        while (row = stmt.fetchRow())
            entities.emplace_back(row);
        return entities;
    }
}
