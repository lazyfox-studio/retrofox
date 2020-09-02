#include "entities/platform.h"

namespace Database
{
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
            extensions = row.column<std::string>("extensions");
            default_emulator_id = row.column<unsigned>("default_emulator_id");
        }

        std::vector<Platform> Platform::fetchEntities(Database::Statement& stmt)
        {
            std::vector<Platform> entities;
            Database::Row row;
            while (row = stmt.fetchRow())
                entities.emplace_back(row);
            return entities;
        }
    }
}
