#pragma once

#include <string>
#include <vector>
#include <map>

#include "database/row.h"
#include "database/statement.h"

namespace Entities
{
    struct Developer
    {
        long id;
        std::string name;

        /// Default constructor
        Developer();

        /// Copy constructor
        Developer(const Developer&) = default;

        /// Move constructor
        Developer(Developer&&) = default;

        /// Copy-assignment operator
        Developer& operator=(const Developer&) = default;

        /// Move-assignment operator
        Developer& operator=(Developer&&) = default;

        /**
            * @brief Typecast constructor
            * @param row Row with game info
            */
        Developer(const Database::Row& row);
    };
}