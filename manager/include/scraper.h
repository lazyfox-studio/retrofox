#pragma once

#include <string>

#include <database.h>
#include <pythonfunctions.h>

/**
 * @ingroup manager
 * @brief Scraping utilities
 */
namespace Scraper
{
    /**
     * @brief Scans folder, finds ROM files, and saves info to database
     * @param path Path to folder to scan
     * @param platform_id Platform ID
     * @param db_path Path to SQLite database
     */
    void scanFloder(std::string path, long platform_id, const std::string& db_path);

    /**
     * @brief Fetches metadata for games in previously scanned folder and saves to database
     * @param db_path Path to SQLite database
     */
    void findGamesInformation(const std::string& db_path);

    /**
     * @brief Cleans cache after scraping in database
     * @param db_path Path to SQLite database
     */
    void cleanCache(const std::string& db_path);
};
