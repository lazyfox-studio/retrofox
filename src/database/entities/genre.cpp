#include "entities/genre.h"

namespace Entities
{
    Genre::Genre()
    {
        id = 0;
    }

    Genre::Genre(const Database::Row& row)
    {
        id = row.column<long>("id");
        name = row.column<std::string>("name");
    }
}
