#include "database/entities/developer.h"

namespace Entities
{
    Developer::Developer()
    {
        id = 0;
    }

    Developer::Developer(const Database::Row& row)
    {
        id = row.column<long>("id");
        name = row.column<std::string>("name");
    }
}
