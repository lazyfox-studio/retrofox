#include "scraper.h"

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

        //TODO: ADD KEY GET FROM SERVER
        std::string stolen_api_key = "445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600";

        for (const auto& id : games)
        {
            PythonFunctions::findGame(stolen_api_key, std::stol(id), db_path);

            auto query = base.query("SELECT * FROM `scraper_cache_games` WHERE `game_id` = ?;");
            query.bind(1, std::stoi(id));
            query.execute();

            //TODO: REWORK
            size_t count = 0;
            Database::Row row;
            while (row = query.fetchRow())
            { 
                count++;
            }
            if (count == 1)
            {
                auto query2 = base.query("UPDATE `games` SET `name` = ? WHERE `id` = ?;");
                //query.bind(1, row.column<std::string>("name"));
                query2.bind(1, "I FIND ONLY ONE");
                query2.bind(2, std::stoi(id)); 
                query2.execute();
            }
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

