#pragma once

#include <string>
#include <vector>
#include <map>

#include "database/row.h"
#include "database/statement.h"

namespace Entities
{
    struct GameGenre
    {
        long game_id;
        long genre_id;

        /// Default constructor
        GameGenre();

        /// Copy constructor
        GameGenre(const GameGenre&) = default;

        /// Move constructor
        GameGenre(GameGenre&&) = default;

        /// Copy-assignment operator
        GameGenre& operator=(const GameGenre&) = default;

        /// Move-assignment operator
        GameGenre& operator=(GameGenre&&) = default;

        /**
            * @brief Typecast constructor
            * @param row Row with game info
            */
        GameGenre(const Database::Row& row);
    };
}
