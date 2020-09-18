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

            /**
             * @brief Fetches all rows and extracts entities info from them into vector
             * @param stmt Statement with SELECT query
             * @return Vector of entities
             */
            static std::vector<GameGenre> fetchEntities(Database::Statement& stmt);
        };
    }
}