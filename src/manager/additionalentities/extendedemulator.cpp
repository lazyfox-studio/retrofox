#include "manager/additionalentities/extendedemulator.h"

namespace AdditionalEntities
{
    ExtendedEmulator::ExtendedEmulator()
    {
        id = 0;
        platform_id = 0;
    }

    ExtendedEmulator::ExtendedEmulator(const Database::Row& row)
    {
        id = row.column<unsigned>("id");
        name = row.column<std::string>("name");
        platform_id = row.column<unsigned>("platform_id");
        platform_name = row.column<std::string>("platform_name");
        emulator_path = row.column<std::string>("emulator_path");
        execution_parameters = row.column<std::string>("execution_parameters");
    }

    Entities::Emulator ExtendedEmulator::toEmulator() const
    {
        Entities::Emulator result;
        result.id = id;
        result.name = name;
        result.platform_id = platform_id;
        result.emulator_path = emulator_path;
        result.execution_parameters = execution_parameters;
        return result;
    }

    const char *ExtendedEmulator::queryString()
    {
        return "SELECT emulators.id, emulators.name, emulators.platform_id, "
               "platforms.name AS platform_name, emulators.emulator_path, emulators.execution_parameters "
               "FROM emulators LEFT JOIN platforms ON emulators.platform_id = platforms.id";
    }

    const char *ExtendedEmulator::queryStringWithUnbindedId()
    {
        return "SELECT emulators.id, emulators.name, emulators.platform_id, "
               "platforms.name AS platform_name, emulators.emulator_path, emulators.execution_parameters "
               "FROM emulators LEFT JOIN platforms ON emulators.platform_id = platforms.id "
               "WHERE emulators.id = ?";
    }
}
