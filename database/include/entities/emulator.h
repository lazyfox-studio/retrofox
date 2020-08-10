#pragma once

#include <string>

#include "row.h"

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
        };
    }
}
