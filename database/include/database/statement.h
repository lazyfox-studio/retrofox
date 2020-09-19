#pragma once

#include <sqlite3.h>

#include <string>
#include <vector>
#include <map>

#include "database/row.h"

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
         * @brief Returns single value
         * @details Helper method: fetches first column of first row
         * @return Column value
         */
        template<typename Value>
        Value getOne();

        /**
         * @brief Returns pair of values
         * @details Helper method: fetches first two columns of first row
         * @return Pair of columns values
         */
        template<typename FValue, typename SValue>
        std::pair<FValue, SValue> getPair();

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

        /**
         * @brief Binds one value to placeholder
         * @param binding_value1 Value to bind
         */
        template<typename Type1>
        void bindMany(Type1 binding_value1);

        /**
         * @brief Binds two values to placeholders one-by-one
         * @param binding_value1 First value to bind
         * @param binding_value2 Second value to bind
         */
        template<typename Type1, typename Type2>
        void bindMany(Type1 binding_value1, Type2 binding_value2);

        /**
         * @brief Binds three values to placeholders one-by-one
         * @param binding_value1 First value to bind
         * @param binding_value2 Second value to bind
         * @param binding_value3 Third value to bind
         */
        template<typename Type1, typename Type2, typename Type3>
        void bindMany(Type1 binding_value1, Type2 binding_value2, Type3 binding_value3);

        /**
         * @brief Binds four values to placeholders one-by-one
         * @param binding_value1 First value to bind
         * @param binding_value2 Second value to bind
         * @param binding_value3 Third value to bind
         * @param binding_value4 Fourth value to bind
         */
        template<typename Type1, typename Type2, typename Type3, typename Type4>
        void bindMany(Type1 binding_value1, Type2 binding_value2, Type3 binding_value3, Type4 binding_value4);

        /**
         * @brief Binds five values to placeholders one-by-one
         * @param binding_value1 First value to bind
         * @param binding_value2 Second value to bind
         * @param binding_value3 Third value to bind
         * @param binding_value4 Fourth value to bind
         * @param binding_value5 Fifth value to bind
         */
        template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5>
        void bindMany(Type1 binding_value1, Type2 binding_value2, Type3 binding_value3, Type4 binding_value4, Type5 binding_value5);
    };


    template<typename Value>
    Value Statement::getOne()
    {
        Database::Row row = fetchRow();
        return row.column<Value>(0);
    }

    template<typename FValue, typename SValue>
    std::pair<FValue, SValue> Statement::getPair()
    {
        Database::Row row = fetchRow();
        return std::make_pair(row.column<FValue>(0), row.column<SValue>(1));
    }

    template<typename Value>
    std::vector<Value> Statement::getColumn()
    {
        std::vector<Value> result;
        Database::Row row;
        while ((row = fetchRow()))
            result.push_back(row.column<Value>(0));
        return result;
    }

    template<typename Key, typename Value>
    std::map<Key, Value> Statement::getIndexedColumn()
    {
        std::map<Key, Value> result;
        Database::Row row;
        while ((row = fetchRow()))
            result.insert(std::make_pair(row.column<Key>(0), row.column<Value>(1)));
        return result;
    }

    template<typename Type1>
    void Statement::bindMany(Type1 binding_value1)
    {
        bind(1, binding_value1);
    }

    template<typename Type1, typename Type2>
    void Statement::bindMany(Type1 binding_value1, Type2 binding_value2)
    {
        bind(1, binding_value1);
        bind(2, binding_value2);
    }

    template<typename Type1, typename Type2, typename Type3>
    void Statement::bindMany(Type1 binding_value1, Type2 binding_value2, Type3 binding_value3)
    {
        bind(1, binding_value1);
        bind(2, binding_value2);
        bind(3, binding_value3);
    }

    template<typename Type1, typename Type2, typename Type3, typename Type4>
    void Statement::bindMany(Type1 binding_value1, Type2 binding_value2, Type3 binding_value3, Type4 binding_value4)
    {
        bind(1, binding_value1);
        bind(2, binding_value2);
        bind(3, binding_value3);
        bind(4, binding_value4);
    }

    template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5>
    void Statement::bindMany(Type1 binding_value1, Type2 binding_value2, Type3 binding_value3, Type4 binding_value4, Type5 binding_value5)
    {
        bind(1, binding_value1);
        bind(2, binding_value2);
        bind(3, binding_value3);
        bind(4, binding_value4);
        bind(5, binding_value5);
    }
}
