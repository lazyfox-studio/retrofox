#pragma once

#include <string>
#include <vector>
#include <map>

#include "row.h"
#include "statement.h"

namespace Database
{
    namespace Entities
    {
        struct Game
        {
            unsigned id;
            std::string path;
            std::string name;
            unsigned platform_id;
            std::string developer;
            std::string publisher;
            std::string release_date;
            std::string genre;
            float rating;
            std::string description;
            std::string boxart;

            Game(const Database::Row& row);

            static std::vector<Game> fetchEntities(Database::Statement& stmt);
        };
    }
}
