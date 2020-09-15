#include "emulatorstablemodel.h"

EmulatorsTableModel::EmulatorsTableModel(QObject *parent) : QAbstractTableModel(parent)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `emulators`");
    m_emulators = Database::Entities::Emulator::fetchEntities(query);
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
    auto query = base.query("UPDATE `emulators` SET name = ?, execution_command = ? WHERE id = ?");
    query.bindMany(emulator.name.c_str(), emulator.execution_command.c_str(), emulator.id);
    query.execute();
}

void EmulatorsTableModel::updateRow(const QModelIndex &index)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `games` WHERE id = ?");
    query.bindMany(m_emulators[index.row()].id);

    Database::Entities::Emulator emulator(query.fetchRow());
    m_emulators[index.row()] = emulator;
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
