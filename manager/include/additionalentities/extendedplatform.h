#pragma once

#include <string>
#include <vector>

#include "database.h"

namespace AdditionalEntities
{
    /// Platform entity
    struct ExtendedPlatform
    {
        unsigned id;                       ///< Platform ID (ROWID)
        std::string name;                  ///< Platform name
        unsigned default_emulator_id;      ///< Default emulator ID
        std::string default_emulator_name; ///<Default emulator name

        /// Default constructor
        ExtendedPlatform();

        /// Copy constructor
        ExtendedPlatform(const ExtendedPlatform&) = default;

        /// Move constructor
        ExtendedPlatform(ExtendedPlatform&&) = default;

        /// Copy-assignment operator
        ExtendedPlatform& operator=(const ExtendedPlatform&) = default;

        /// Move-assignment operator
        ExtendedPlatform& operator=(ExtendedPlatform&&) = default;

        /**
            * @brief Typecast constructor
            * @param row Row with platform info
            */
        ExtendedPlatform(const Database::Row& row);

        Entities::Platform toPlatform() const;

        static const char* queryString();
        static const char* queryStringWithUnbindedId();
    };
}
