#include "statement.h"

namespace Database
{
    Statement::Statement()
        : p_db_handler(nullptr), p_stmt_handler(nullptr)
    {
    }

    Statement::Statement(sqlite3* db_handler, const std::string& query_string)
        : p_db_handler(db_handler)
    {
        if (sqlite3_prepare(p_db_handler, query_string.c_str(), static_cast<int>(query_string.length()) + 1, &p_stmt_handler, nullptr))
            throw std::exception(error());
    }

    Statement::~Statement()
    {
        if (p_stmt_handler != nullptr)
            sqlite3_finalize(p_stmt_handler);
    }
    
    void Statement::execute()
    {
        while (fetchRow())
            continue;
    }

    Row Statement::fetchRow()
    {
        int result = sqlite3_step(p_stmt_handler);
        if (result == SQLITE_DONE)
            return Row();
        if (result == SQLITE_ROW)
            return Row(p_stmt_handler);
        if (result == SQLITE_MISUSE)
            throw std::exception("Library used incorrectly");
        throw std::exception(error());
    }

    const char* Statement::error()
    {
        return sqlite3_errmsg(p_db_handler);
    }

    int Statement::errorCode()
    {
        return sqlite3_errcode(p_db_handler);
    }

    int Statement::columnCount()
    {
        return sqlite3_column_count(p_stmt_handler);
    }

    int Statement::columnBytes(int column_index)
    {
        return sqlite3_column_bytes(p_stmt_handler, column_index);
    }
}
