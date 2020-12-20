#include "database/entities/functions.h"

namespace Entities
{
    std::vector<Developer> findDevelopers(std::vector<GameDeveloper> game_developers, std::string path_to_db)
    {
        std::vector<Developer> result;
        auto base = Database::Connection(path_to_db);
        for (auto game_developer : game_developers)
        {
            auto query = base.query("SELECT * FROM `developers` WHERE `id` = ?");
            query.bindMany(game_developer.developer_id);
            result.push_back(Developer(query.fetchRow()));
        }
        return result;
    }
    std::vector<Genre> findGenres(std::vector<GameGenre> game_genres, std::string path_to_db)
    {
        std::vector<Genre> result;
        auto base = Database::Connection(path_to_db);
        for (auto game_genre : game_genres)
        {
            auto query = base.query("SELECT * FROM `genres` WHERE `id` = ?");
            query.bindMany(game_genre.genre_id);
            result.push_back(Genre(query.fetchRow()));
        }
        return result;
    }
    std::vector<Publisher> findPublishers(std::vector<GamePublisher> game_publishers, std::string path_to_db)
    {
        std::vector<Publisher> result;
        auto base = Database::Connection(path_to_db);
        for (auto game_publisher : game_publishers)
        {
            auto query = base.query("SELECT * FROM `publishers` WHERE `id` = ?");
            query.bindMany(game_publisher.publisher_id);
            result.push_back(Publisher(query.fetchRow()));
        }
        return result;
    }
}