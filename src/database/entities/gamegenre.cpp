#include "database/entities/gamegenre.h"

namespace Entities
{
    GameGenre::GameGenre()
    {
        game_id = 0;
        genre_id = 0;
    }

    GameGenre::GameGenre(const Database::Row& row)
    {
        game_id = row.column<long>("game_id");
        genre_id = row.column<long>("genre_id");
    }
}
