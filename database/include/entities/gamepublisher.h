#pragma once

#include <string>
#include <vector>
#include <map>

#include "row.h"
#include "statement.h"

namespace Database
{
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

            /**
             * @brief Fetches all rows and extracts entities info from them into vector
             * @param stmt Statement with SELECT query
             * @return Vector of entities
             */
            static std::vector<GamePublisher> fetchEntities(Database::Statement& stmt);
        };
    }
}