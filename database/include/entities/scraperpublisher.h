#pragma once

#include <string>
#include <vector>
#include <map>

#include "database/row.h"
#include "database/statement.h"

namespace Entities
{
    struct ScraperPublisher
    {
        long cache_id;
        long publisher_id;

        /// Default constructor
        ScraperPublisher();

        /// Copy constructor
        ScraperPublisher(const ScraperPublisher&) = default;

        /// Move constructor
        ScraperPublisher(ScraperPublisher&&) = default;

        /// Copy-assignment operator
        ScraperPublisher& operator=(const ScraperPublisher&) = default;

        /// Move-assignment operator
        ScraperPublisher& operator=(ScraperPublisher&&) = default;

        /**
            * @brief Typecast constructor
            * @param row Row with game info
            */
        ScraperPublisher(const Database::Row& row);

        /**
            * @brief Fetches all rows and extracts entities info from them into vector
            * @param stmt Statement with SELECT query
            * @return Vector of entities
            */
        static std::vector<ScraperPublisher> fetchEntities(Database::Statement& stmt);
    };
}
