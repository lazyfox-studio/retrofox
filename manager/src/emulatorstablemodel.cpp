#include "emulatorstablemodel.h"

EmulatorsTableModel::EmulatorsTableModel(QObject *parent) : QAbstractTableModel(parent)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `emulators`");
    m_emulators = Database::Entities::fetchEntities<Database::Entities::Emulator>(query);
}

EmulatorsTableModel::~EmulatorsTableModel()
{

}

Database::Entities::Emulator EmulatorsTableModel::emulator(const QModelIndex &index)
{
    return m_emulators[index.row()];
}

void EmulatorsTableModel::updateEmulator(Database::Entities::Emulator emulator)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("UPDATE `emulators` SET name = ?, platform_id = ?, emulator_path = ?, execution_parameters = ? WHERE id = ?");
    query.bindMany(emulator.name.c_str(), emulator.platform_id, emulator.emulator_path.c_str(), emulator.execution_parameters.c_str(), emulator.id);
    query.execute();
}

void EmulatorsTableModel::updateRow(const QModelIndex &index)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `emulators` WHERE id = ?");
    query.bindMany(m_emulators[index.row()].id);

    Database::Entities::Emulator emulator(query.fetchRow());
    m_emulators[index.row()] = emulator;
}

bool EmulatorsTableModel::insertRow(const Database::Entities::Emulator &emulator)
{
    beginInsertRows(QModelIndex(), static_cast<int>(m_emulators.size()), static_cast<int>(m_emulators.size()));
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("INSERT INTO `emulators` (name, platform_id, emulator_path, execution_parameters) VALUES (?, ?, ?, ?);");
    query.bindMany(emulator.name.c_str(), emulator.platform_id, emulator.emulator_path.c_str(), emulator.execution_parameters.c_str());
    query.execute();
    m_emulators.push_back(emulator);
    endInsertRows();
    return true;
}

bool EmulatorsTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);

    if (count == 0)
    {
        return false;
    }

    auto base = Database::Connection("../sln/core/testbase.db");

    auto i_remove_start = m_emulators.begin() + row;
    auto i_remove_end = m_emulators.begin() + row + count;
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    for (size_t i = 0; i < static_cast<size_t>(count); i++)
    {
        auto query = base.query("DELETE FROM `emulators` WHERE id = ?");
        query.bindMany(m_emulators[row + i].id);
        query.execute();
    }
    m_emulators.erase(i_remove_start, i_remove_end);
    endRemoveRows();
    return true;
}

int EmulatorsTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_emulators.size());
}

int EmulatorsTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 1;
}

QVariant EmulatorsTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        std::string result;
        switch(index.column())
        {
            case ColumnName::Name:
                result = m_emulators[index.row()].name;
                break;
        }

        return QVariant(result.c_str());
    }
    return QVariant();
}

QVariant EmulatorsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (orientation == Qt::Vertical)
    {
        return section;
    }

    switch (section)
    {
        case ColumnName::Name:
            return tr("Name");
    }

    throw std::runtime_error("Unexpected result");
}
