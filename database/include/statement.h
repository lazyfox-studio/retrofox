#pragma once

#include <sqlite3.h>

#include <string>
#include <vector>
#include <map>

#include "row.h"

namespace Database
{
    /**
     * @brief SQLite3 statement
     * @details Class to represent prepared statement
     */
    class Statement
    {
    protected:
        friend class Connection;

        /// Statement handler
        sqlite3_stmt* p_stmt_handler;

        /**
         * @brief Internal constructor-initializer
         * @param stmt_handler Statement handler
         */
        explicit Statement(sqlite3_stmt* stmt_handler);

    public:
        /// Default constructor
        Statement();

        /// Destructor
        ~Statement();

        /// Move constructor
        Statement(Statement&& other);

        /// Move assignment operator
        Statement& operator=(Statement&& other);

        /// Copy constructor is not provided
        Statement(const Statement&) = delete;

        /// Copy assignment operator is not provided
        Statement& operator=(const Statement&) = delete;


        /// Executes query (fetches rows as many times as possible)
        void execute();

        /**
         * @brief Fetches sequential row (executes single step) 
         * @return Row
         */
        Row fetchRow();


        /**
         * @brief Returns single column values as vector
         * @details Helper method: fetches first columns of all rows into vector
         * @return Vector with column values
         */
        template<typename Value>
        std::vector<Value> getColumn();

        /**
         * @brief Returns two columns values as map
         * @details Helper method: fetches first two columns of all rows (as key-value) into map
         * @return Map with columns values
         */
        template<typename Key, typename Value>
        std::map<Key, Value> getIndexedColumn();
        

        /**
         * @brief Returns number of columns
         * @return Number of columns
         */
        int columnCount() const;

        /**
         * @brief Returns size of column data
         * @param column_index Column index
         * @return Number of bytes
         */
        int columnBytes(int column_index) const;

        /**
         * @brief Resets statement so it could be preformed anew
         * @param clear_bindings If true, also clears binded values
         */
        void reset(bool clear_bindings = true);

        /**
         * @brief Binds SQL NULL value to placeholder
         * @param placeholder_index Placeholder index
         */
        void bindNull(int placeholder_index);

        /**
         * @brief Binds value in preferred type (Type) to placeholder
         * @param placeholder_index Placeholder index
         * @param binding_value Value to bind
         */
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
