#include "database/database/connection.h"

namespace Database
{
    Connection::Connection(const std::string& db_path)
    {
        if (sqlite3_open(db_path.c_str(), &p_db_handler))
            throw std::runtime_error("Cannot open database");
    }

    Connection::~Connection()
    {
        sqlite3_close(p_db_handler);
    }

    sqlite3* Connection::handler() const
    {
        return p_db_handler;
    }

    const char* Connection::error() const
    {
        return sqlite3_errmsg(p_db_handler);
    }

    int Connection::errorCode() const
    {
        return sqlite3_errcode(p_db_handler);
    }

    int Connection::changes() const
    {
        return sqlite3_changes(p_db_handler);
    }

    long Connection::lastInsertId() const
    {
        return sqlite3_last_insert_rowid(p_db_handler);
    }

    Statement Connection::query(const std::string& query_string)
    {
        sqlite3_stmt* stmt_handler;
        if (sqlite3_prepare(p_db_handler, query_string.c_str(), static_cast<int>(query_string.length()) + 1, &stmt_handler, nullptr))
            throw std::runtime_error(error());
        return Statement(stmt_handler);
    }
}
