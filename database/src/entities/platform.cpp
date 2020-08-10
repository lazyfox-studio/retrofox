#include "entities/platform.h"

namespace Database
{
    namespace Entities
    {
        Platform::Platform(const Database::Row& row)
        {
            id = row.column<unsigned>("id");
            name = row.column<std::string>("name");
            extensions = row.column<std::string>("extensions");
            default_emulator_id = row.column<unsigned>("default_emulator_id");
        }
    }
}
