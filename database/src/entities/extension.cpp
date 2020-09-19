#include "entities/extension.h"

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
}