#pragma once

#include <string>

#include "row.h"

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
        };
    }
}
