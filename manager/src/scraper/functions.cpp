#include "scraper/functions.h"

namespace Scraper
{
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

    void updateGameFromScraper(long scraper_game_id, const std::string &db_path)
    {
        Database::Connection base(db_path);
        Database::Statement query;

        query = base.query("SELECT * FROM `scraper_cache_games` WHERE `id` = ?;");
        query.bind(1, scraper_game_id);
        Database::Entities::ScraperGame scraper_game(query.fetchRow());

        query = base.query("UPDATE `games` SET `name` = ?, `release_date` = ?, `rating` = ?, `description` = ? WHERE `id` = ?;");
        query.bindMany(scraper_game.name.c_str(), scraper_game.release_date.c_str(), scraper_game.rating.c_str(),
                       scraper_game.description.c_str(), scraper_game.game_id);
        query.execute();
    }

}
