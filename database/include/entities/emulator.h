#pragma once

#include <string>
#include <vector>

#include "row.h"
#include "statement.h"

namespace Database
{
    namespace Entities
    {
        /// Emulator entity
        struct Emulator
        {
            unsigned id; ///< Emulator ID (ROWID)
            std::string name; ///< Emulator name
            unsigned platform_id; ///< Emulator platform ID
            std::string execution_command; ///< Execution command

            /**
             * @brief Typecast constructor
             * @param row Row with emulator info
             */
            Emulator(const Database::Row& row);

            /**
             * @brief Fetches all rows and extracts entities info from them into vector
             * @param stmt Statement with SELECT query
             * @return Vector of entities
             */
            static std::vector<Emulator> fetchEntities(Database::Statement& stmt);
        };
    }
}
