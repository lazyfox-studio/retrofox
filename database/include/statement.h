#pragma once

#include <sqlite3.h>

#include <string>

#include "connection.h"

namespace Database
{
    class Statement
    {
    protected:
        const Connection& r_connection;
        sqlite3_stmt* p_handler;

    public:
        Statement() = delete;
        Statement(const Statement&) = delete;
        Statement(Statement&&) = default;
        Statement(const Connection& connection, const std::string& query_string);
        ~Statement();

        bool fetchStep();
        int columnCount();
        int columnBytes(int column_index);

        template<typename RType>
        RType columnAs(int column_index);
    };
}
