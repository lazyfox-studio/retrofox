#pragma once

#include <string>
#include <vector>

#include "database/database/row.h"
#include "database/database/statement.h"

namespace Entities
{
    /// Platform entity
    struct Extension
    {
        long platform_id;      ///< Platform ID (ROWID)
        std::string extension; ///< Extension

        /// Default constructor
        Extension();

        /// Copy constructor
        Extension(const Extension&) = default;

        /// Move constructor
        Extension(Extension&&) = default;

        /// Copy-assignment operator
        Extension& operator=(const Extension&) = default;

        /// Move-assignment operator
        Extension& operator=(Extension&&) = default;

        /**
            * @brief Typecast constructor
            * @param row Row with platform info
            */
        Extension(const Database::Row& row);
    };
}
