#include "core/scraper.h"

namespace Scraper
{
    void scanFloder(std::string path, long platform_id, const std::string& db_path)
    {
        PythonFunctions::findGamesInFolder(path, platform_id, db_path);
    }

    void findGamesInformation(const std::string& db_path)
    {
        Database::Connection base(db_path);
        auto games = base.getColumn<std::string>("SELECT `id` FROM `games`;");

        // TODO: ADD KEY GET FROM SERVER
        std::string stolen_api_key = "445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600";

        for (const auto& id : games)
        {
            PythonFunctions::findGame(stolen_api_key, std::stol(id), db_path);

            Database::Statement query;
            Database::Row row;

            // Check founded variants count
            query = base.query("SELECT COUNT(`id`) FROM scraper_cache_games WHERE `game_id` = ?;");
            query.bindMany(std::stol(id));
            if (query.getOne<size_t>() != 1)
            {
                // TODO: Game selecting dialog
                break;
            }

            // Read data from scraper_cache
            query = base.query("SELECT `name` FROM scraper_cache_games WHERE `game_id` = ?;");
            query.bindMany(std::stol(id));
            std::string name = query.getOne<std::string>();

            // Write data to games
            query = base.query("UPDATE `games` SET `name` = ? WHERE `id` = ?;");
            query.bindMany(name.c_str(), std::stol(id));
            query.execute();
        }
    }

    void cleanCache(const std::string& db_path)
    {
        Database::Connection base(db_path);
        Database::Statement query;
        query = base.query("DELETE FROM `scraper_cache_games`;");
        query.execute();
        query = base.query("DELETE FROM `scraper_cache_developers`;");
        query.execute();
        query = base.query("DELETE FROM `scraper_cache_publishers`;");
        query.execute();
        query = base.query("DELETE FROM `scraper_cache_genres`;");
        query.execute();
    }
}

