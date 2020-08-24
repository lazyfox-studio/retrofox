#pragma once

#include <string>

#include "pythonenv.h"

namespace PythonFunctions
{
    int findGame(const std::string& api_key, long game_id, const std::string& path_to_db);
}
