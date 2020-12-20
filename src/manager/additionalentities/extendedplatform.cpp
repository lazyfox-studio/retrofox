#include "manager/additionalentities/extendedplatform.h"

namespace AdditionalEntities
{
    ExtendedPlatform::ExtendedPlatform()
    {
        id = 0;
        default_emulator_id = 0;
    }

    ExtendedPlatform::ExtendedPlatform(const Database::Row& row)
    {
        id = row.column<unsigned>("id");
        name = row.column<std::string>("name");
        default_emulator_id = row.column<unsigned>("default_emulator_id");
        default_emulator_name = row.column<std::string>("default_emulator_name");
    }

    Entities::Platform ExtendedPlatform::toPlatform() const
    {
        Entities::Platform result;
        result.id = id;
        result.name = name;
        result.default_emulator_id = default_emulator_id;
        return result;
    }

    const char *ExtendedPlatform::queryString()
    {
        return "SELECT platforms.id, platforms.name, platforms.default_emulator_id, emulators.name AS default_emulator_name "
               "FROM platforms LEFT JOIN emulators ON platforms.default_emulator_id = emulators.id";
    }

    const char *ExtendedPlatform::queryStringWithUnbindedId()
    {
        return "SELECT platforms.id, platforms.name, platforms.default_emulator_id, emulators.name AS default_emulator_name "
                            "FROM platforms LEFT JOIN emulators ON platforms.default_emulator_id = emulators.id WHERE platforms.id = ?";
    }
}
