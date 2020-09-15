#include "entities/extension.h"

namespace Database
{
    namespace Entities
    {
        Extension::Extension()
        {
            platform_id = 0;
        }

        Extension::Extension(const Database::Row& row)
        {
            platform_id = row.column<long>("platform_id");
            extension = row.column<std::string>("extension");
        }

        std::vector<Extension> Extension::fetchEntities(Database::Statement& stmt)
        {
            std::vector<Extension> entities;
            Database::Row row;
            while (row = stmt.fetchRow())
                entities.emplace_back(row);
            return entities;
        }
    }
}