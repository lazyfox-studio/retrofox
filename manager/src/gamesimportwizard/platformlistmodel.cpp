#include "gamesimportwizard/platformlistmodel.h"

namespace GamesImportWizard
{

    PlatformListModel::PlatformListModel(QObject *parent) : QAbstractListModel(parent)
    {
        auto base = Database::Connection("../sln/core/testbase.db");
        auto query = base.query("SELECT * FROM platforms");
        platforms = Database::Entities::Platform::fetchEntities(query);
    }

    PlatformListModel::~PlatformListModel()
    {

    }

    Database::Entities::Platform PlatformListModel::platform(int index)
    {
        return platforms[index];
    }

    int PlatformListModel::rowCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return static_cast<int>(platforms.size());
    }

    QVariant PlatformListModel::data(const QModelIndex &index, int role) const
    {
        if (role == Qt::DisplayRole)
        {
            return QVariant(platforms[index.row()].name.c_str());
        }
        return QVariant();
    }

}
