#pragma once

#include <string>
#include <vector>

#include <database/database.h>

namespace AdditionalEntities
{
    /// Platform entity
    struct ExtendedEmulator
    {
        unsigned id;                      ///< Emulator ID (ROWID)
        std::string name;                 ///< Emulator name
        unsigned platform_id;             ///< Emulator platform ID
        std::string platform_name;         ///< Emulator platform name
        std::string emulator_path;        ///< Emulator path
        std::string execution_parameters; ///< Parameters for emulator execution

        /// Default constructor
        ExtendedEmulator();

        /// Copy constructor
        ExtendedEmulator(const ExtendedEmulator&) = default;

        /// Move constructor
        ExtendedEmulator(ExtendedEmulator&&) = default;

        /// Copy-assignment operator
        ExtendedEmulator& operator=(const ExtendedEmulator&) = default;

        /// Move-assignment operator
        ExtendedEmulator& operator=(ExtendedEmulator&&) = default;

        /**
            * @brief Typecast constructor
            * @param row Row with platform info
            */
        ExtendedEmulator(const Database::Row& row);

        Entities::Emulator toEmulator() const;

        static const char* queryString();
        static const char* queryStringWithUnbindedId();
    };
}
