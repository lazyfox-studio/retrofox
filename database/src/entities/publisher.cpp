#include "entities/publisher.h"

namespace Entities
{
    Publisher::Publisher()
    {
        game_id = 0;
    }

    Publisher::Publisher(const Database::Row& row)
    {
        game_id = row.column<long>("id");
        name = row.column<long>("name");
    }
}
