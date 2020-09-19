#pragma once

#include <string>
#include <vector>
#include <map>

#include "database/row.h"
#include "database/statement.h"

namespace Entities
{
    struct GamePublisher
    {
        long game_id;
        long publisher_id;

        /// Default constructor
        GamePublisher();

        /// Copy constructor
        GamePublisher(const GamePublisher&) = default;

        /// Move constructor
        GamePublisher(GamePublisher&&) = default;

        /// Copy-assignment operator
        GamePublisher& operator=(const GamePublisher&) = default;

        /// Move-assignment operator
        GamePublisher& operator=(GamePublisher&&) = default;

        /**
            * @brief Typecast constructor
            * @param row Row with game info
            */
        GamePublisher(const Database::Row& row);
    };
}
