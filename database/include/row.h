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
        
        int columnCount() const;
        int columnBytes(int column_index) const;
        int columnType(int column_index) const;
        const char* columnName(int column_index) const;
        int findColumnByName(const std::string& column_name) const;

        operator bool() const;

        template<typename RType>
        RType column(int column_index) const;

        template<typename RType>
        RType column(const std::string& column_name) const;
    };

    template<typename RType>
    RType Row::column(const std::string& column_name) const
    {
        int column_index = findColumnByName(column_name);
        if (column_index == -1)
            throw std::exception("Column not fount - cannot get value");
        return column<RType>(column_index);
    }
}
