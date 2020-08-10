#pragma once

#include <string>
#include <vector>

#include "row.h"
#include "statement.h"

namespace Database
{
    namespace Entities
    {
        struct Platform
        {
            unsigned id;
            std::string name;
            std::string extensions;
            unsigned default_emulator_id;

            Platform(const Database::Row& row);

            static std::vector<Platform> fetchEntities(Database::Statement& stmt);
        };
    }
}
