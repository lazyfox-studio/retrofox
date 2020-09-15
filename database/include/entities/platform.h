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
        struct Platform
        {
            unsigned id; ///< Platform ID (ROWID)
            std::string name; ///< Platform name
            unsigned default_emulator_id; ///< Default emulator ID

            /// Default constructor
            Platform();

            /// Copy constructor
            Platform(const Platform&) = default;

            /// Move constructor
            Platform(Platform&&) = default;

            /// Copy-assignment operator
            Platform& operator=(const Platform&) = default;

            /// Move-assignment operator
            Platform& operator=(Platform&&) = default;

            /**
             * @brief Typecast constructor
             * @param row Row with platform info
             */
            Platform(const Database::Row& row);

            /**
             * @brief Fetches all rows and extracts entities info from them into vector
             * @param stmt Statement with SELECT query
             * @return Vector of entities
             */
            static std::vector<Platform> fetchEntities(Database::Statement& stmt);
        };
    }
}
