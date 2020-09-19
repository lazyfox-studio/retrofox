#include "platformstablemodel.h"

PlatformsTableModel::PlatformsTableModel(QObject *parent) : QAbstractTableModel(parent)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `platforms`");
    m_platforms = Database::Entities::fetchEntities<Database::Entities::Platform>(query);
}

PlatformsTableModel::~PlatformsTableModel()
{

}

Database::Entities::Platform PlatformsTableModel::platform(const QModelIndex &index)
{
    return m_platforms[index.row()];
}

std::vector<Database::Entities::Extension> PlatformsTableModel::extensions(const QModelIndex &index)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `extensions` WHERE `platform_id` = ?");
    query.bindMany(m_platforms[index.row()].id);
    return Database::Entities::fetchEntities<Database::Entities::Extension>(query);
}

void PlatformsTableModel::updatePlatform(Database::Entities::Platform platform)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("UPDATE `platforms` SET name = ?, `default_emulator_id` = ? WHERE id = ?");
    query.bindMany(platform.name.c_str(), platform.default_emulator_id, platform.id);
    query.execute();
}

void PlatformsTableModel::updateExtensions(const std::vector<Database::Entities::Extension> &extensions, long platform_id)
{
    auto base = Database::Connection("../sln/core/testbase.db");

    auto query = base.query("DELETE FROM `extensions` WHERE `platform_id` = ?");
    query.bindMany(platform_id);
    query.execute();

    for (auto extension : extensions)
    {
        query = base.query("INSERT INTO `extensions` (platform_id, extension) VALUES (?,?)");
        query.bindMany(extension.platform_id, extension.extension.c_str());
        query.execute();
    }
}

void PlatformsTableModel::updateRow(const QModelIndex &index)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `platforms` WHERE id = ?");
    query.bindMany(m_platforms[index.row()].id);

    Database::Entities::Platform platform(query.fetchRow());
    m_platforms[index.row()] = platform;
}

bool PlatformsTableModel::insertRow(const Database::Entities::Platform &platform)
{
    beginInsertRows(QModelIndex(), static_cast<int>(m_platforms.size()), static_cast<int>(m_platforms.size()));
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("INSERT INTO `platforms` (name, default_emulator_id) VALUES (?, ?);");
    query.bindMany(platform.name.c_str(), platform.default_emulator_id);
    query.execute();
    m_platforms.push_back(platform);
    endInsertRows();
    return true;
}

bool PlatformsTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);

    if (count == 0)
    {
        return false;
    }

    auto base = Database::Connection("../sln/core/testbase.db");

    auto i_remove_start = m_platforms.begin() + row;
    auto i_remove_end = m_platforms.begin() + row + count;
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    for (size_t i = 0; i < static_cast<size_t>(count); i++)
    {
        auto query = base.query("DELETE FROM `platforms` WHERE id = ?");
        query.bindMany(m_platforms[row + i].id);
        query.execute();
    }
    m_platforms.erase(i_remove_start, i_remove_end);
    endRemoveRows();
    return true;
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
