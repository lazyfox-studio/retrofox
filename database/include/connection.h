#pragma once

#include <sqlite3.h>

#include <string>

namespace Database
{
    class Connection
    {
    protected:
        sqlite3* p_handler;

    public:
        Connection() = delete;
        Connection(const Connection&) = delete;
        Connection(Connection&&) = default;
        Connection(const std::string& db_path);
        ~Connection();

        sqlite3* handler() const;
    };
}
