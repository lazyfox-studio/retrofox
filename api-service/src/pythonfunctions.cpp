#include "pythonfunctions.h"

int PythonFunctions::findGame(const std::string& api_key, long game_id, const std::string& path_to_db)
{
    PythonRef ret_value = PythonEnv::instance().callFunction("findgames", "find_game", api_key, game_id, path_to_db);
    return ret_value.cast<int>();
}
