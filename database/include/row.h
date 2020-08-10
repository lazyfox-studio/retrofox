#pragma once

#include <sqlite3.h>

#include <string>

namespace Database
{
    class Row
    {
    protected:
        sqlite3_stmt* p_stmt_handler;

    public:
        Row();
        Row(sqlite3_stmt* stmt_handler);

        Row(Row&&) = default;
        Row(const Row&) = delete;
        ~Row() = default;

        Row& operator=(const Row&) = delete;
        Row& operator=(Row&&) = default;
        
        int columnCount();
        int columnBytes(int column_index);

        operator bool() const;

        template<typename RType>
        RType column(int column_index);

    };
}
