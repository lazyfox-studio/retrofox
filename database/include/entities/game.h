#pragma once

#include <string>
#include <vector>
#include <map>

#include "database/row.h"
#include "database/statement.h"

namespace Entities
{
    /// Game entity
    struct Game
    {
        long        id;           ///< Game ID (ROWID)
        std::string path;         ///< Path to game executable
        std::string name;         ///< Game name
        long        platform_id;  ///< Platform ID
        //std::string developers; ///< Developer name
        //std::string publishers; ///< Publisher name
        std::string release_date; ///< Release date
        //std::string genre;      ///< Game genre
        std::string rating;       ///< Rating value
        std::string description;  ///< Game short description
        //std::string boxart;     ///< Game boxart image path

        /// Default constructor
        Game();

        /// Copy constructor
        Game(const Game&) = default;

        /// Move constructor
        Game(Game&&) = default;

        /// Copy-assignment operator
        Game& operator=(const Game&) = default;

        /// Move-assignment operator
        Game& operator=(Game&&) = default;

        /**
            * @brief Typecast constructor
            * @param row Row with game info
            */
        Game(const Database::Row& row);
    };
}
