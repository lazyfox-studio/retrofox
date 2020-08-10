#include "entities/emulator.h"

namespace Database
{
    namespace Entities
    {
        Emulator::Emulator(const Database::Row& row)
        {
            id = row.column<unsigned>("id");
            name = row.column<std::string>("name");
            platform_id = row.column<unsigned>("platform_id");
            execution_command = row.column<std::string>("execution_command");
        }
    }
}
