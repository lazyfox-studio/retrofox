#include "api-service/pythonfunctions.h"

namespace PythonFunctions
{
    std::vector<long> findGame(const std::string& api_key, long game_id, const std::string& path_to_db)
    {
        constexpr const char* FUNC_NAME = "find_game";
        PythonRef ret_value = PythonEnv::instance().callFunction(MODULE_NAME, FUNC_NAME, api_key, game_id, path_to_db);
        return ret_value.list<long>();
    }

    std::vector<long> findGamesInFolder(const std::string& roms_path, long platform_id, const std::string& path_to_db)
    {
        constexpr const char* FUNC_NAME = "find_games_in_folder";
        PythonRef ret_value = PythonEnv::instance().callFunction(MODULE_NAME, FUNC_NAME, roms_path, platform_id, path_to_db);
        return ret_value.list<long>();
    }

    int setUpTables(const std::string& path_to_db)
    {
        constexpr const char* FUNC_NAME = "set_up_tables";
        PythonRef ret_value = PythonEnv::instance().callFunction(MODULE_NAME, FUNC_NAME, path_to_db);
        return ret_value.cast<int>();
    }

    std::vector<long> listTest(const std::string& roms_path, long platform_id, const std::string& path_to_db)
    {
        constexpr const char* FUNC_NAME = "list_test";
        PythonRef ret_value = PythonEnv::instance().callFunction(MODULE_NAME, FUNC_NAME, roms_path, platform_id, path_to_db);
        return ret_value.list<long>();
    }
}
