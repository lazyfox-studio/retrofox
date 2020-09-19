#include "database/statement.h"

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
            throw std::runtime_error("Library used incorrectly");
        throw std::runtime_error("SQL Error, check db connection");
    }

    int Statement::columnCount() const
    {
        return sqlite3_column_count(p_stmt_handler);
    }

    int Statement::columnBytes(int column_index) const
    {
        return sqlite3_column_bytes(p_stmt_handler, column_index);
    }

    void Statement::reset(bool clear_bindings)
    {
        sqlite3_reset(p_stmt_handler);
        if (clear_bindings)
            sqlite3_clear_bindings(p_stmt_handler);
    }

    void Statement::bindNull(int placeholder_index)
    {
        sqlite3_bind_null(p_stmt_handler, placeholder_index);
    }

    template<>
    void Statement::bind<char>(int placeholder_index, char binding_value)
    {
        sqlite3_bind_int(p_stmt_handler, placeholder_index, binding_value);
    }

    template<>
    void Statement::bind<short>(int placeholder_index, short binding_value)
    {
        sqlite3_bind_int(p_stmt_handler, placeholder_index, binding_value);
    }

    template<>
    void Statement::bind<int>(int placeholder_index, int binding_value)
    {
        sqlite3_bind_int(p_stmt_handler, placeholder_index, binding_value);
    }

    template<>
    void Statement::bind<long>(int placeholder_index, long binding_value)
    {
        sqlite3_bind_int64(p_stmt_handler, placeholder_index, binding_value);
    }

    template<>
    void Statement::bind<long long>(int placeholder_index, long long binding_value)
    {
        sqlite3_bind_int64(p_stmt_handler, placeholder_index, binding_value);
    }

    template<>
    void Statement::bind<unsigned int>(int placeholder_index, unsigned int binding_value)
    {
        sqlite3_bind_int(p_stmt_handler, placeholder_index, static_cast<int>(binding_value));
    }

    template<>
    void Statement::bind<unsigned long>(int placeholder_index, unsigned long binding_value)
    {
        sqlite3_bind_int64(p_stmt_handler, placeholder_index, static_cast<long>(binding_value));
    }

    template<>
    void Statement::bind<unsigned long long>(int placeholder_index, unsigned long long binding_value)
    {
        sqlite3_bind_int64(p_stmt_handler, placeholder_index, static_cast<long long>(binding_value));
    }

    template<>
    void Statement::bind<float>(int placeholder_index, float binding_value)
    {
        sqlite3_bind_double(p_stmt_handler, placeholder_index, binding_value);
    }

    template<>
    void Statement::bind<double>(int placeholder_index, double binding_value)
    {
        sqlite3_bind_double(p_stmt_handler, placeholder_index, binding_value);
    }

    template<>
    void Statement::bind<const char*>(int placeholder_index, const char* binding_value)
    {
        sqlite3_bind_text(p_stmt_handler, placeholder_index, binding_value, -1, nullptr);
    }

    template<>
    void Statement::bind<const std::string&>(int placeholder_index, const std::string& binding_value)
    {
        bind<const char*>(placeholder_index, binding_value.c_str());
    }
}
