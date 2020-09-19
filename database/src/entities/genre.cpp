#include "entities/genre.h"

namespace Entities
{
    Genre::Genre()
    {
        game_id = 0;
    }

    Genre::Genre(const Database::Row& row)
    {
        game_id = row.column<long>("game_id");
        name = row.column<long>("name");
    }
}
