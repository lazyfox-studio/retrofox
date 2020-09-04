#include "entities/emulator.h"

namespace Database
{
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
            execution_command = row.column<std::string>("execution_command");
        }

        std::vector<Emulator> Emulator::fetchEntities(Database::Statement& stmt)
        {
            std::vector<Emulator> entities;
            Database::Row row;
            while (row = stmt.fetchRow())
                entities.emplace_back(row);
            return entities;
        }
    }
}
