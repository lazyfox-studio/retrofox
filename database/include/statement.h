#pragma once

#include <sqlite3.h>

#include <string>

#include "row.h"

namespace Database
{
    class Statement
    {
    protected:
        friend class Connection;

        sqlite3_stmt* p_stmt_handler;

        explicit Statement(sqlite3_stmt* p_stmt_handler);

    public:
        Statement();
        ~Statement();

        Statement(Statement&& other);
        Statement& operator=(Statement&& other);

        Statement(const Statement&) = delete;
        Statement& operator=(const Statement&) = delete;

        void execute();
        Row fetchRow();
        
        int columnCount();
        int columnBytes(int column_index);
    };
}
