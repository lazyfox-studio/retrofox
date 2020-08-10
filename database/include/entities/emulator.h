#pragma once

#include <string>
#include <vector>

#include "row.h"
#include "statement.h"

namespace Database
{
    namespace Entities
    {
        struct Emulator
        {
            unsigned id;
            std::string name;
            unsigned platform_id;
            std::string execution_command;

            Emulator(const Database::Row& row);

            static std::vector<Emulator> fetchEntities(Database::Statement& stmt);
        };
    }
}
