#include "database/database/row.h"

namespace Database
{
    Row::Row()
        : p_stmt_handler(nullptr)
    {
    }

    Row::Row(sqlite3_stmt* stmt_handler)
        : p_stmt_handler(stmt_handler)
    {
    }

    int Row::columnCount() const
    {
        return sqlite3_column_count(p_stmt_handler);;
    }

    int Row::columnBytes(int column_index) const
    {
        return sqlite3_column_bytes(p_stmt_handler, column_index);
    }

    int Row::columnType(int column_index) const
    {
        return sqlite3_column_type(p_stmt_handler, column_index);
    }

    const char* Row::columnName(int column_index) const
    {
        return sqlite3_column_name(p_stmt_handler, column_index);
    }

    int Row::findColumnByName(const std::string& column_name) const
    {
        int column_count = columnCount();
        for (int i = 0; i < column_count; i++)
            if (column_name == columnName(i))
                return i;
        return -1;
    }

    Row::operator bool() const
    {
        return p_stmt_handler != nullptr;
    }

    template<>
    char Row::column<char>(int column_index) const
    {
        return static_cast<char>(sqlite3_column_int(p_stmt_handler, column_index));
    }

    template<>
    short Row::column<short>(int column_index) const
    {
        return static_cast<short>(sqlite3_column_int(p_stmt_handler, column_index));
    }

    template<>
    int Row::column<int>(int column_index) const
    {
        return sqlite3_column_int(p_stmt_handler, column_index);
    }

    template<>
    long Row::column<long>(int column_index) const
    {
        return static_cast<long>(sqlite3_column_int64(p_stmt_handler, column_index));
    }

    template<>
    long long Row::column<long long>(int column_index) const
    {
        return static_cast<long long>(sqlite3_column_int64(p_stmt_handler, column_index));
    }

    template<>
    unsigned char Row::column<unsigned char>(int column_index) const
    {
        return static_cast<unsigned char>(sqlite3_column_int(p_stmt_handler, column_index));
    }

    template<>
    unsigned short Row::column<unsigned short>(int column_index) const
    {
        return static_cast<unsigned short>(sqlite3_column_int(p_stmt_handler, column_index));
    }

    template<>
    unsigned int Row::column<unsigned int>(int column_index) const
    {
        return static_cast<unsigned int>(sqlite3_column_int(p_stmt_handler, column_index));
    }

    template<>
    unsigned long Row::column<unsigned long>(int column_index) const
    {
        return static_cast<unsigned long>(sqlite3_column_int64(p_stmt_handler, column_index));
    }

    template<>
    unsigned long long Row::column<unsigned long long>(int column_index) const
    {
        return static_cast<unsigned long long>(sqlite3_column_int64(p_stmt_handler, column_index));
    }

    template<>
    float Row::column<float>(int column_index) const
    {
        return static_cast<float>(sqlite3_column_double(p_stmt_handler, column_index));
    }

    template<>
    double Row::column<double>(int column_index) const
    {
        return sqlite3_column_double(p_stmt_handler, column_index);
    }

    template<>
    const char* Row::column<const char*>(int column_index) const
    {
        return reinterpret_cast<const char*>(sqlite3_column_text(p_stmt_handler, column_index));
    }

    template<>
    const unsigned char* Row::column<const unsigned char*>(int column_index) const
    {
        return sqlite3_column_text(p_stmt_handler, column_index);
    }

    template<>
    const void* Row::column<const void*>(int column_index) const
    {
        return sqlite3_column_blob(p_stmt_handler, column_index);
    }

    template<>
    std::string Row::column<std::string>(int column_index) const
    {
        return std::string(column<const char*>(column_index), columnBytes(column_index));
    }
}
