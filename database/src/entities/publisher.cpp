#include "entities/publisher.h"

namespace Entities
{
    Publisher::Publisher()
    {
        id = 0;
    }

    Publisher::Publisher(const Database::Row& row)
    {
        id = row.column<long>("id");
        name = row.column<std::string>("name");
    }
}
