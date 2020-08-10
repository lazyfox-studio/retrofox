#include "connection.h"

namespace Database
{
    Connection::Connection(const std::string& db_path)
    {
        if (sqlite3_open(db_path.c_str(), &p_db_handler))
            throw std::exception("Cannot open database");
    }

    Connection::~Connection()
    {
        sqlite3_close(p_db_handler);
    }

    sqlite3* Connection::handler() const
    {
        return p_db_handler;
    }

    const char* Connection::error()
    {
        return sqlite3_errmsg(p_db_handler);
    }

    int Connection::errorCode()
    {
        return sqlite3_errcode(p_db_handler);
    }

    Statement Connection::query(const std::string& query_string)
    {
        return Statement(p_db_handler, query_string);
    }
}
