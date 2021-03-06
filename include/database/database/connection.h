#pragma once

#include <sqlite3.h>

#include <string>
#include <vector>

#include "database/database/statement.h"

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
         * @brief Returns ROWID of last inserted row
         * @return Last inserted ROWID
         */
        long lastInsertId() const;

        /**
         * @brief Prepares query statement for performing
         * @param query_string SQL query string
         * @return Prepared statement
         */
        Statement query(const std::string& query_string);
        
        /**
         * @brief Returns single value
         * @details Helper method: performs query, then fetches first column of first row
         * @param query_string SQL query string
         * @return Column value
         */
        template<typename Value>
        Value getOne(const std::string& query_string);

        /**
         * @brief Returns pair of values
         * @details Helper method: performs query, then fetches first two columns of first row
         * @param query_string SQL query string
         * @return Pair of columns values
         */
        template<typename FValue, typename SValue>
        std::pair<FValue, SValue> getPair(const std::string& query_string);

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
    Value Connection::getOne(const std::string& query_string)
    {
        Database::Statement stmt = query(query_string);
        return stmt.getOne<Value>();
    }

    template<typename FValue, typename SValue>
    std::pair<FValue, SValue> Connection::getPair(const std::string& query_string)
    {
        Database::Statement stmt = query(query_string);
        return stmt.getPair<FValue, SValue>();
    }

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
