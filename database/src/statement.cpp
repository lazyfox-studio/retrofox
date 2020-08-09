#include "statement.h"

namespace Database
{
    Statement::Statement(const Connection& connection, const std::string& query_string)
        : r_connection(connection)
    {
        if (int rc = sqlite3_prepare(connection.handler(), query_string.c_str(), static_cast<int>(query_string.length()) + 1, &p_handler, nullptr))
            throw std::exception(sqlite3_errmsg(r_connection.handler()));
    }

    Statement::~Statement()
    {
        sqlite3_finalize(p_handler);
    }

    bool Statement::fetchStep()
    {
        int result = sqlite3_step(p_handler);
        if (result == SQLITE_DONE)
            return false;
        if (result == SQLITE_ROW)
            return true;
        throw std::exception(sqlite3_errmsg(r_connection.handler()));
    }

    int Statement::columnCount()
    {
        return sqlite3_column_count(p_handler);
    }

    int Statement::columnBytes(int column_index)
    {
        return sqlite3_column_bytes(p_handler, column_index);
    }

    template<>
    char Statement::columnAs<char>(int column_index)
    {
        return static_cast<char>(sqlite3_column_int(p_handler, column_index));
    }

    template<>
    short Statement::columnAs<short>(int column_index)
    {
        return static_cast<short>(sqlite3_column_int(p_handler, column_index));
    }

    template<>
    int Statement::columnAs<int>(int column_index)
    {
        return sqlite3_column_int(p_handler, column_index);
    }

    template<>
    long Statement::columnAs<long>(int column_index)
    {
        return static_cast<long>(sqlite3_column_int64(p_handler, column_index));
    }

    template<>
    long long Statement::columnAs<long long>(int column_index)
    {
        return static_cast<long long>(sqlite3_column_int64(p_handler, column_index));
    }

    template<>
    unsigned char Statement::columnAs<unsigned char>(int column_index)
    {
        return static_cast<unsigned char>(sqlite3_column_int(p_handler, column_index));
    }

    template<>
    unsigned short Statement::columnAs<unsigned short>(int column_index)
    {
        return static_cast<unsigned short>(sqlite3_column_int(p_handler, column_index));
    }

    template<>
    unsigned int Statement::columnAs<unsigned int>(int column_index)
    {
        return static_cast<unsigned int>(sqlite3_column_int(p_handler, column_index));
    }

    template<>
    unsigned long Statement::columnAs<unsigned long>(int column_index)
    {
        return static_cast<unsigned long>(sqlite3_column_int64(p_handler, column_index));
    }

    template<>
    unsigned long long Statement::columnAs<unsigned long long>(int column_index)
    {
        return static_cast<unsigned long long>(sqlite3_column_int64(p_handler, column_index));
    }

    template<>
    float Statement::columnAs<float>(int column_index)
    {
        return static_cast<float>(sqlite3_column_double(p_handler, column_index));
    }

    template<>
    double Statement::columnAs<double>(int column_index)
    {
        return sqlite3_column_double(p_handler, column_index);
    }

    template<>
    const char* Statement::columnAs<const char*>(int column_index)
    {
        return reinterpret_cast<const char*>(sqlite3_column_text(p_handler, column_index));
    }

    template<>
    const unsigned char* Statement::columnAs<const unsigned char*>(int column_index)
    {
        return sqlite3_column_text(p_handler, column_index);
    }

    template<>
    const void* Statement::columnAs<const void*>(int column_index)
    {
        return sqlite3_column_blob(p_handler, column_index);
    }

    template<>
    std::string Statement::columnAs<std::string>(int column_index)
    {
        return std::string(columnAs<const char*>(column_index), columnBytes(column_index));
    }
}
