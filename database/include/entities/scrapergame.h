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
        /// Game entity
        struct ScraperGame
        {
            long        id;           ///< Game ID (ROWID)
            long        game_id;
            std::string name;         ///< Game name
            //std::string developers; ///< Developer name
            //std::string publishers; ///< Publisher name
            std::string release_date; ///< Release date
            //std::string genre;      ///< Game genre
            std::string rating;       ///< Rating value
            std::string description;  ///< Game short description
            //std::string boxart;     ///< Game boxart image path

            /// Default constructor
            ScraperGame();

            /// Copy constructor
            ScraperGame(const ScraperGame&) = default;

            /// Move constructor
            ScraperGame(ScraperGame&&) = default;

            /// Copy-assignment operator
            ScraperGame& operator=(const ScraperGame&) = default;

            /// Move-assignment operator
            ScraperGame& operator=(ScraperGame&&) = default;

            /**
             * @brief Typecast constructor
             * @param row Row with game info
             */
            ScraperGame(const Database::Row& row);

            /**
             * @brief Fetches all rows and extracts entities info from them into vector
             * @param stmt Statement with SELECT query
             * @return Vector of entities
             */
            static std::vector<ScraperGame> fetchEntities(Database::Statement& stmt);
        };
    }
}