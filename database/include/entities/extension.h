#pragma once

#include <string>
#include <vector>

#include "row.h"
#include "statement.h"

namespace Database
{
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

            /**
             * @brief Fetches all rows and extracts entities info from them into vector
             * @param stmt Statement with SELECT query
             * @return Vector of entities
             */
            static std::vector<Extension> fetchEntities(Database::Statement& stmt);
        };
    }
}
