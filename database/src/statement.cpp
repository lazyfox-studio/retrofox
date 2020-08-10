#include "statement.h"

namespace Database
{
    Statement::Statement()
        : p_stmt_handler(nullptr)
    {
    }

    Statement::Statement(sqlite3_stmt* stmt_handler)
        : p_stmt_handler(stmt_handler)
    {
    }

    Statement::~Statement()
    {
        if (p_stmt_handler != nullptr)
            sqlite3_finalize(p_stmt_handler);
    }

    Statement::Statement(Statement&& other)
        : p_stmt_handler(other.p_stmt_handler)
    {
        other.p_stmt_handler = nullptr;
    }

    Statement& Statement::operator=(Statement&& other)
    {
        if (p_stmt_handler != nullptr)
            sqlite3_finalize(p_stmt_handler);
        p_stmt_handler = other.p_stmt_handler;
        other.p_stmt_handler = nullptr;
        return *this;
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
        throw std::exception("SQL Error, check db connection");
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
