#include "database/qmlinterface.h"
#include <QDebug>
namespace Database
{
    void QmlInterface::addDatabase(const QString& db_path, const QString& db_name)
    {
        auto base = QSqlDatabase::addDatabase("QSQLITE", db_name);
        base.setDatabaseName(db_path);
    }

    void QmlInterface::removeDatabase(const QString& db_name)
    {
        QSqlDatabase::removeDatabase(db_name);
    }

    QVariantList QmlInterface::query(const QString& query_string)
    {
        auto base = QSqlDatabase::database(db_name);
        qDebug() << base.isValid();
        base.open();
        QSqlQuery query(base);
        query.prepare(query_string);
        query.exec();

        QVariantList result;
        while (query.next())
        {
            QVariantMap local_result;
            for (int i = 0; i < query.record().count(); i++)
            {
                local_result.insert(query.record().fieldName(i), query.value(i));
            }
            result.push_back(local_result);
        }
        base.commit();
        base.close();
        return result;
    }
}
