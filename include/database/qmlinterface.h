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
        Q_PROPERTY(QString db_path MEMBER db_path)

    public:
        QString db_path;

        Q_INVOKABLE QVariantList query(const QString& query_string);
    };
}
