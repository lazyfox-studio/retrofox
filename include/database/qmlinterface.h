#pragma once

#include <QObject>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QString>
#include <QVariantList>
#include <QVariantMap>

namespace Database
{
    class QmlInterface : public QObject {
        Q_OBJECT
        Q_PROPERTY(QString db_name MEMBER db_name)

    public:
        QString db_name;

        /**
         * @brief Create SQLite3 database connection
         * @param db_path Path to database file
         * @param db_name Name of connection
         * @note Can be called only after QApplication initialized
         */
        Q_INVOKABLE static void addDatabase(const QString& db_path,
                                            const QString& db_name = QSqlDatabase::defaultConnection);

        /**
         * @brief Remove SQLite3 database connection
         * @param db_name Name of connection
         */
        Q_INVOKABLE static void removeDatabase(const QString& db_name);

        Q_INVOKABLE QVariantList query(const QString& query_string);
    };
}
