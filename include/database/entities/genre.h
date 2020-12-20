#pragma once

#include <string>
#include <vector>
#include <map>

#include "database/database/row.h"
#include "database/database/statement.h"

namespace Entities
{
    struct Genre
    {
        long id;
        std::string name;

        /// Default constructor
        Genre();

        /// Copy constructor
        Genre(const Genre&) = default;

        /// Move constructor
        Genre(Genre&&) = default;

        /// Copy-assignment operator
        Genre& operator=(const Genre&) = default;

        /// Move-assignment operator
        Genre& operator=(Genre&&) = default;

        /**
            * @brief Typecast constructor
            * @param row Row with game info
            */
        Genre(const Database::Row& row);
    };
}