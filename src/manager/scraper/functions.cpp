#include "manager/scraper/functions.h"

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
        Entities::ScraperGame scraper_game(query.fetchRow());

        query = base.query("UPDATE `games` SET `name` = ?, `release_date` = ?, `rating` = ?, `description` = ? WHERE `id` = ?;");
        query.bindMany(scraper_game.name.c_str(), scraper_game.release_date.c_str(), scraper_game.rating.c_str(),
                       scraper_game.description.c_str(), scraper_game.game_id);
        query.execute();

        //Copy developers
        query = base.query("SELECT * FROM `scraper_cache_developers` WHERE `cache_id` = ?;");
        query.bindMany(scraper_game_id);
        auto developers = Entities::fetchEntities<Entities::ScraperDeveloper>(query);
        for (auto developer : developers)
        {
            query = base.query("INSERT INTO `game_developers` (game_id, developer_id) VALUES (?,?)");
            query.bindMany(scraper_game.game_id, developer.developer_id);
            query.execute();
        }

        //Copy publishers
        query = base.query("SELECT * FROM `scraper_cache_publishers` WHERE `cache_id` = ?;");
        query.bindMany(scraper_game_id);
        auto publishers = Entities::fetchEntities<Entities::ScraperPublisher>(query);
        for (auto publisher : publishers)
        {
            query = base.query("INSERT INTO `game_publishers` (game_id, publisher_id) VALUES (?,?)");
            query.bindMany(scraper_game.game_id, publisher.publisher_id);
            query.execute();
        }

        //Copy genres
        query = base.query("SELECT * FROM `scraper_cache_genres` WHERE `cache_id` = ?;");
        query.bindMany(scraper_game_id);
        auto genres = Entities::fetchEntities<Entities::ScraperGenre>(query);
        for (auto genre : genres)
        {
            query = base.query("INSERT INTO `game_genres` (game_id, genre_id) VALUES (?,?)");
            query.bindMany(scraper_game.game_id, genre.genre_id);
            query.execute();
        }
    }
}
