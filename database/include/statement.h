#pragma once

#include <sqlite3.h>

#include <string>

#include "row.h"

namespace Database
{
    class Statement
    {
    protected:
        sqlite3* p_db_handler;
        sqlite3_stmt* p_stmt_handler;

    public:
        Statement();
        Statement(sqlite3* db_handler, const std::string& query_string);
        ~Statement();

        Statement(Statement&& other);
        Statement& operator=(Statement&& other);

        Statement(const Statement&) = delete;
        Statement& operator=(const Statement&) = delete;

        void execute();
        Row fetchRow();

        const char* error();
        int errorCode();
        int columnCount();
        int columnBytes(int column_index);
    };
}
