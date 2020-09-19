#include "entities/gamegenre.h"

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

    std::vector<GameGenre> GameGenre::fetchEntities(Database::Statement& stmt)
    {
        std::vector<GameGenre> entities;
        Database::Row row;
        while (row = stmt.fetchRow())
            entities.emplace_back(row);
        return entities;
    }
}
