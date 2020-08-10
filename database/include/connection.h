#pragma once

#include <sqlite3.h>

#include <string>
#include <vector>

#include "statement.h"

namespace Database
{
    class Connection
    {
    protected:
        sqlite3* p_db_handler;

    public:
        Connection() = delete;
        Connection(const Connection&) = delete;
        Connection(Connection&&) = default;
        Connection(const std::string& db_path);
        ~Connection();

        sqlite3* handler() const;
        const char* error() const;
        int errorCode() const;
        int changes() const;

        Statement query(const std::string& query_string);
        
        template<typename Value>
        std::vector<Value> getColumn(const std::string& query_string);

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
