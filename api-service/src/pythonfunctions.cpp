#include "pythonfunctions.h"

namespace PythonFunctions
{
    int findGame(const std::string& api_key, long game_id, const std::string& path_to_db)
    {
        constexpr const char* FUNC_NAME = "find_game";
        PythonRef ret_value = PythonEnv::instance().callFunction(MODULE_NAME, FUNC_NAME, api_key, game_id, path_to_db);
        return ret_value.cast<int>();
    }

    int findGamesInFolder(const std::string& roms_path, long platform_id, const std::string& path_to_db)
    {
        constexpr const char* FUNC_NAME = "find_games_in_folder";
        PythonRef ret_value = PythonEnv::instance().callFunction(MODULE_NAME, FUNC_NAME, roms_path, platform_id, path_to_db);
        return ret_value.cast<int>();
    }
}
