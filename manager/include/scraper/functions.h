#pragma once

#include <string>
#include <database.h>

namespace Scraper
{
    /**
     * @brief Cleans cache after scraping in database
     * @param db_path Path to SQLite database
     */
    void cleanCache(const std::string& db_path);

    void updateGameFromScraper(long scraper_game_id, const std::string& db_path);
}
