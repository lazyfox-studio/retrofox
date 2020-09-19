#pragma once

#include <string>
#include <vector>
#include <map>

#include "database/row.h"
#include "database/statement.h"

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
    };
}
