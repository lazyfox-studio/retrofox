#include "database/qmlinterface.h"

namespace Database
{
    QVariantList QmlInterface::query(const QString& query_string)
    {
        auto base = QSqlDatabase::addDatabase("QSQLITE");
        base.setDatabaseName(db_path);
        base.open();

        QSqlQuery query(query_string);
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
        base.close();
        return result;
    }
}
