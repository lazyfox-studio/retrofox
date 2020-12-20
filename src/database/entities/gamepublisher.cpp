#include "database/entities/gamepublisher.h"

namespace Entities
{
    GamePublisher::GamePublisher()
    {
        game_id = 0;
        publisher_id = 0;
    }

    GamePublisher::GamePublisher(const Database::Row& row)
    {
        game_id = row.column<long>("game_id");
        publisher_id = row.column<long>("publisher_id");
    }
}
