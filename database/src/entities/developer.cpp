#include "entities/developer.h"

namespace Entities
{
    Developer::Developer()
    {
        game_id = 0;
    }

    Developer::Developer(const Database::Row& row)
    {
        game_id = row.column<long>("id");
        name = row.column<long>("name");
    }
}
