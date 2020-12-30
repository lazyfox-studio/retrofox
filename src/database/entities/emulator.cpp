#include "database/entities/emulator.h"

namespace Entities
{
    Emulator::Emulator()
    {
        id = 0;
        platform_id = 0;
    }

    Emulator::Emulator(const Database::Row& row)
    {
        id = row.column<unsigned>("id");
        name = row.column<std::string>("name");
        platform_id = row.column<unsigned>("platform_id");
        emulator_path = row.column<std::string>("emulator_path");
        execution_parameters = row.column<std::string>("execution_parameters");
    }
}
