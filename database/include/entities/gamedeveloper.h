#pragma once

#include <string>
#include <vector>
#include <map>

#include "database/row.h"
#include "database/statement.h"

namespace Entities
{
    struct GameDeveloper
    {
        long game_id;
        long developer_id;

        /// Default constructor
        GameDeveloper();

        /// Copy constructor
        GameDeveloper(const GameDeveloper&) = default;

        /// Move constructor
        GameDeveloper(GameDeveloper&&) = default;

        /// Copy-assignment operator
        GameDeveloper& operator=(const GameDeveloper&) = default;

        /// Move-assignment operator
        GameDeveloper& operator=(GameDeveloper&&) = default;

        /**
            * @brief Typecast constructor
            * @param row Row with game info
            */
        GameDeveloper(const Database::Row& row);
    };
}
