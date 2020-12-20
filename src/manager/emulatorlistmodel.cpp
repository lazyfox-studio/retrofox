#include "manager/emulatorlistmodel.h"

EmulatorListModel::EmulatorListModel(QObject *parent) : QAbstractListModel(parent)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM emulators");
    emulators = Entities::fetchEntities<Entities::Emulator>(query);
}

EmulatorListModel::~EmulatorListModel()
{

}

Entities::Emulator EmulatorListModel::emulator(int index)
{
    return emulators[index];
}

int EmulatorListModel::findEmulatorIndex(long emulator_id)
{
    for (int i = 0; i < static_cast<int>(emulators.size()); i++)
    {
        if (emulators[i].id == emulator_id)
        {
            return i;
        }
    }
    return -1;
}

int EmulatorListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return static_cast<int>(emulators.size());
}

QVariant EmulatorListModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return QVariant(emulators[index.row()].name.c_str());
    }
    return QVariant();
}
