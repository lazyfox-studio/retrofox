#include "entities/platform.h"

namespace Entities
{
    Platform::Platform()
    {
        id = 0;
        default_emulator_id = 0;
    }

    Platform::Platform(const Database::Row& row)
    {
        id = row.column<unsigned>("id");
        name = row.column<std::string>("name");
        default_emulator_id = row.column<unsigned>("default_emulator_id");
    }
}
