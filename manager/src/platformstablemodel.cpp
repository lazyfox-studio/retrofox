#include "platformstablemodel.h"

PlatformsTableModel::PlatformsTableModel(QObject *parent) : QAbstractTableModel(parent)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `platforms`");
    m_platforms = Database::Entities::Platform::fetchEntities(query);
}

PlatformsTableModel::~PlatformsTableModel()
{

}

Database::Entities::Platform PlatformsTableModel::platform(const QModelIndex &index)
{
    return m_platforms[index.row()];
}

void PlatformsTableModel::updatePlatform(Database::Entities::Platform platform)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("UPDATE `platforms` SET name = ?, `default_emulator_id` = ? WHERE id = ?");
    query.bindMany(platform.name.c_str(), platform.default_emulator_id, platform.id);
    query.execute();
}

void PlatformsTableModel::updateRow(const QModelIndex &index)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `platforms` WHERE id = ?");
    query.bindMany(m_platforms[index.row()].id);

    Database::Entities::Platform platform(query.fetchRow());
    m_platforms[index.row()] = platform;
}

int PlatformsTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_platforms.size());
}

int PlatformsTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant PlatformsTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        std::string result;
        switch(index.column())
        {
            case ColumnName::Name:
                result = m_platforms[index.row()].name;
                break;
            case ColumnName::Emulator:
                result = m_platforms[index.row()].default_emulator_id;
                break;
        }

        return QVariant(result.c_str());
    }
    return QVariant();
}

QVariant PlatformsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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
        case ColumnName::Emulator:
            return tr("Default emulator");
    }

    throw std::runtime_error("Unexpected result");
}
