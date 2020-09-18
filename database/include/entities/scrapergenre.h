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
        struct ScraperGenre
        {
            long cache_id;
            long genre_id;

            /// Default constructor
            ScraperGenre();

            /// Copy constructor
            ScraperGenre(const ScraperGenre&) = default;

            /// Move constructor
            ScraperGenre(ScraperGenre&&) = default;

            /// Copy-assignment operator
            ScraperGenre& operator=(const ScraperGenre&) = default;

            /// Move-assignment operator
            ScraperGenre& operator=(ScraperGenre&&) = default;

            /**
             * @brief Typecast constructor
             * @param row Row with game info
             */
            ScraperGenre(const Database::Row& row);

            /**
             * @brief Fetches all rows and extracts entities info from them into vector
             * @param stmt Statement with SELECT query
             * @return Vector of entities
             */
            static std::vector<ScraperGenre> fetchEntities(Database::Statement& stmt);
        };
    }
}