#include "connection.h"

namespace Database
{
    Connection::Connection(const std::string& db_path)
    {
        if (sqlite3_open(db_path.c_str(), &p_handler))
            throw std::exception("Cannot open database");
    }

    Connection::~Connection()
    {
        sqlite3_close(p_handler);
    }

    sqlite3* Connection::handler() const
    {
        return p_handler;
    }
}
