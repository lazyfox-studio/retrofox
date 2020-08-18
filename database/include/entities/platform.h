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
            std::string extensions; ///< File extensions supported by platform
            unsigned default_emulator_id; ///< Default emulator ID

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
