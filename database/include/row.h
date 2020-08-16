#pragma once

#include <sqlite3.h>

#include <string>

namespace Database
{
    /**
     * @brief Single row of database table
     * @details Service class to represent a row
     */
    class Row
    {
    protected:
        /// Statement handler
        sqlite3_stmt* p_stmt_handler;

    public:
        /// Default constructor
        Row();

        /**
         * @brief Typecast constructor
         * @param stmt_handler Statement handler
         */
        Row(sqlite3_stmt* stmt_handler);

        /// Move constructor (defaulted)
        Row(Row&&) = default;

        /// Copy constructor is not provided
        Row(const Row&) = delete;

        /// Default destructor
        ~Row() = default;

        /// Copy assignment operator is not provided
        Row& operator=(const Row&) = delete;

        /// Move assignment operator (defaulted)
        Row& operator=(Row&&) = default;
        

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
         * @brief Returns type of column data
         * @param column_index Column index
         * @return Type of column data
         */
        int columnType(int column_index) const;

        /**
         * @brief Returns column name
         * @param column_index Column index
         * @return Column name
         */
        const char* columnName(int column_index) const;

        /**
         * @brief Finds column index by its name
         * @param column_name Column name
         * @return Column index or -1 if not found
         */
        int findColumnByName(const std::string& column_name) const;

        /// Typecast to bool
        operator bool() const;

        /**
         * @brief Returns column value in preferred type (RType) by index
         * @param column_index Column index
         * @return Column value
         */
        template<typename RType>
        RType column(int column_index) const;

        /**
         * @brief Returns column value in preferred type (RType) by name
         * @param column_name Column name
         * @return Column value
         */
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
