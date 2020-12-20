#pragma once

#include <string>
#include <vector>

#include "database/database/row.h"
#include "database/database/statement.h"

namespace Entities
{
    /// Emulator entity
    struct Emulator
    {
        unsigned id;                      ///< Emulator ID (ROWID)
        std::string name;                 ///< Emulator name
        unsigned platform_id;             ///< Emulator platform ID
        std::string emulator_path;        ///< Emulator path
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
    };
}
