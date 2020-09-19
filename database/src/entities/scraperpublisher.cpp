#include "entities/scraperpublisher.h"

namespace Entities
{
    ScraperPublisher::ScraperPublisher()
    {
        cache_id = 0;
        publisher_id = 0;
    }

    ScraperPublisher::ScraperPublisher(const Database::Row& row)
    {
        cache_id = row.column<long>("cache_id");
        publisher_id = row.column<long>("publisher_id");
    }
}
