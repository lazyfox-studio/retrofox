#pragma once

#include <sqlite3.h>

#include <string>
#include <vector>
#include <map>

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

        template<typename Value>
        std::vector<Value> getColumn();

        template<typename Key, typename Value>
        std::map<Key, Value> getIndexedColumn();
        
        int columnCount() const;
        int columnBytes(int column_index) const;

        void reset(bool clear_bindings = true);

        void bindNull(int placeholder_index);

        template<typename Type>
        void bind(int placeholder_index, Type binding_value);

    };


    template<typename Value>
    std::vector<Value> Statement::getColumn()
    {
        std::vector<Value> result;
        Database::Row row;
        while (row = fetchRow())
            result.push_back(row.column<Value>(0));
        return result;
    }

    template<typename Key, typename Value>
    std::map<Key, Value> Statement::getIndexedColumn()
    {
        std::map<Key, Value> result;
        Database::Row row;
        while (row = fetchRow())
            result.insert(std::make_pair(row.column<Key>(0), row.column<Value>(1)));
        return result;
    }
}
