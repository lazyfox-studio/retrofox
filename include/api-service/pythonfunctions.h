#pragma once

#include <string>
#include <vector>

#include "pythonenv.h"

/**
 * @ingroup api-service
 * @brief Wrappers for python functions to call from C++ code
 */
namespace PythonFunctions
{
    /// Name of module with embedded functions in 'scripts' folder
    constexpr const char* MODULE_NAME = "findgames";

    /**
     * @brief Fetches game data from API service and saves to database
     * @param api_key API key
     * @param game_id ID of game in 'games' table
     * @param path_to_db Path to SQLite database
     * @return Result code (0 on Success, 1 on Request error, 2 if Games not found, 3 on Database error)
     */
    std::vector<long> findGame(const std::string& api_key, long game_id, const std::string& path_to_db);

    /**
     * @brief Scans folder, finds ROM files, and saves info to database
     * @param roms_path Path to folder with ROMs
     * @param platform_id Platform ID
     * @param path_to_db Path to SQLite database
     */
    std::vector<long> findGamesInFolder(const std::string& roms_path, long platform_id, const std::string& path_to_db);

    /**
     * @brief Creates and configures all required tables for application database
     * @param path_to_db Path to SQLite database
     */
    int setUpTables(const std::string& path_to_db);

    std::vector<long> listTest(const std::string& roms_path, long platform_id, const std::string& path_to_db);
}
