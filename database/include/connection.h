#pragma once

#include <sqlite3.h>

#include <string>

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
        const char* error();
        int errorCode();

        Statement query(const std::string& query_string);
    };
}
