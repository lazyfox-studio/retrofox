#pragma once

#include <string>
#include <vector>
#include <map>

#include "database/row.h"
#include "database/statement.h"

namespace Entities
{
    struct Publisher
    {
        long game_id;
        std::string name;

        /// Default constructor
        Publisher();

        /// Copy constructor
        Publisher(const Publisher&) = default;

        /// Move constructor
        Publisher(Publisher&&) = default;

        /// Copy-assignment operator
        Publisher& operator=(const Publisher&) = default;

        /// Move-assignment operator
        Publisher& operator=(Publisher&&) = default;

        /**
            * @brief Typecast constructor
            * @param row Row with game info
            */
        Publisher(const Database::Row& row);
    };
}