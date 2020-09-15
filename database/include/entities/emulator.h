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
            unsigned id;                     ///< Emulator ID (ROWID)
            std::string name;                ///< Emulator name
            unsigned platform_id;            ///< Emulator platform ID
            std::string emulator_path;       ///< Emulator path
            std::string execution_parameters; ///< Parameters for emulator execution

            /// Default constructor
            Emulator();

            /// Copy constructor
            Emulator(const Emulator&) = default;

            /// Move constructor
            Emulator(Emulator&&) = default;

            /// Copy-assignment operator
            Emulator& operator=(const Emulator&) = default;

            /// Move-assignment operator
            Emulator& operator=(Emulator&&) = default;

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
