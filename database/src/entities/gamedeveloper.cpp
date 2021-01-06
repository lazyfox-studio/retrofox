#include "database/entities/gamedeveloper.h"

namespace Entities
{
    GameDeveloper::GameDeveloper()
    {
        game_id = 0;
        developer_id = 0;
    }

    GameDeveloper::GameDeveloper(const Database::Row& row)
    {
        game_id = row.column<long>("game_id");
        developer_id = row.column<long>("developer_id");
    }
}
