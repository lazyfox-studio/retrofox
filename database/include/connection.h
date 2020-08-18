#pragma once

#include <sqlite3.h>

#include <string>
#include <vector>

#include "statement.h"

namespace Database
{
    /**
     * @brief SQLite3 connection handler
     * @details Class to represent SQLite3 connector 
     */
    class Connection
    {
    protected:
        /// Database handler
        sqlite3* p_db_handler;

    public:
        /// Default constructor is not provided
        Connection() = delete;

        /// Copy constructor is not provided
        Connection(const Connection&) = delete;

        /// Move constructor (defaulted)
        Connection(Connection&&) = default;

        /**
         * @brief Constructor-initializer
         * @param db_path Path to SQLite3 database
         */
        explicit Connection(const std::string& db_path);

        /// Destructor
        ~Connection();


        /**
         * @brief Getter for database handler
         * @return Database handler
         */
        sqlite3* handler() const;

        /**
         * @brief Returns error message
         * @return Error message string
         */
        const char* error() const;

        /**
         * @brief Returns error code
         * @return Error code
         */
        int errorCode() const;

        /**
         * @brief Returns number of changes in last transaction
         * @return Number of changes
         */
        int changes() const;

        /**
         * @brief Prepares query statement for performing
         * @param query_string SQL query string
         * @return Prepared statement
         */
        Statement query(const std::string& query_string);
        
        /**
         * @brief Returns single column values as vector
         * @details Helper method: performs query, then fetches first columns of all rows into vector
         * @param query_string SQL query string
         * @return Vector with column values
         */
        template<typename Value>
        std::vector<Value> getColumn(const std::string& query_string);

        /**
         * @brief Returns two columns values as map
         * @details Helper method: performs query, then fetches first two columns of all rows (as key-value) into map
         * @param query_string SQL query string
         * @return Map with columns values
         */
        template<typename Key, typename Value>
        std::map<Key, Value> getIndexedColumn(const std::string& query_string);
    };

    template<typename Value>
    std::vector<Value> Connection::getColumn(const std::string& query_string)
    {
        Database::Statement stmt = query(query_string);
        return stmt.getColumn<Value>();
    }

    template<typename Key, typename Value>
    std::map<Key, Value> Connection::getIndexedColumn(const std::string& query_string)
    {
        Database::Statement stmt = query(query_string);
        return stmt.getIndexedColumn<Key, Value>();
    }
}
