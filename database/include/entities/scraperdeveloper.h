#pragma once

#include <string>
#include <vector>
#include <map>

#include "database/row.h"
#include "database/statement.h"

namespace Entities
{
    struct ScraperDeveloper
    {
        long cache_id;
        long developer_id;

        /// Default constructor
        ScraperDeveloper();

        /// Copy constructor
        ScraperDeveloper(const ScraperDeveloper&) = default;

        /// Move constructor
        ScraperDeveloper(ScraperDeveloper&&) = default;

        /// Copy-assignment operator
        ScraperDeveloper& operator=(const ScraperDeveloper&) = default;

        /// Move-assignment operator
        ScraperDeveloper& operator=(ScraperDeveloper&&) = default;

        /**
            * @brief Typecast constructor
            * @param row Row with game info
            */
        ScraperDeveloper(const Database::Row& row);
    };
}
