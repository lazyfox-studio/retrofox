#pragma once

#include <string>

#include "pythonenv.h"

namespace PythonFunctions
{
    constexpr const char* MODULE_NAME = "findgames";

    int findGame(const std::string& api_key, long game_id, const std::string& path_to_db);

    int findGamesInFolder(const std::string& roms_path, long platform_id, const std::string& path_to_db);
}
