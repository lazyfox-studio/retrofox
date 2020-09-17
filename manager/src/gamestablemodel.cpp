#include "gamestablemodel.h"

GamesTableModel::GamesTableModel(QObject *parent) : QAbstractTableModel(parent)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `games`");
    games = Database::Entities::Game::fetchEntities(query);
}

GamesTableModel::~GamesTableModel()
{

}

Database::Entities::Game GamesTableModel::game(const QModelIndex &index)
{
    return games[index.row()];
}

void GamesTableModel::updateGame(Database::Entities::Game game)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("UPDATE `games` SET name = ?, path = ? WHERE id = ?");
    query.bindMany(game.name.c_str(), game.path.c_str(), game.id);
    query.execute();
}

void GamesTableModel::updateRow(const QModelIndex &index)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `games` WHERE id = ?");
    query.bindMany(games[index.row()].id);

    Database::Entities::Game game(query.fetchRow());
    games[index.row()] = game;
}

bool GamesTableModel::insertRow(const Database::Entities::Game& game)
{
    beginInsertRows(QModelIndex(), static_cast<int>(games.size()), static_cast<int>(games.size()));
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("INSERT INTO `games` (name, path, platform_id) VALUES (?, ?, 10);");
    query.bindMany(game.name.c_str(), game.path.c_str());
    query.execute();
    games.push_back(game);
    endInsertRows();
    return true;
}

bool GamesTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);

    if (count == 0)
    {
        return false;
    }

    auto base = Database::Connection("../sln/core/testbase.db");

    auto i_remove_start = games.begin() + row;
    auto i_remove_end = games.begin() + row + count;
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    for (size_t i = 0; i < static_cast<size_t>(count); i++)
    {
        auto query = base.query("DELETE FROM `games` WHERE id = ?");
        query.bindMany(games[row + i].id);
        query.execute();
    }
    games.erase(i_remove_start, i_remove_end);
    endRemoveRows();
    return true;
}

int GamesTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(games.size());
}

int GamesTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

QVariant GamesTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        std::string result;
        switch(index.column())
        {
            case ColumnName::Name:
                result = games[index.row()].name;
                break;
            case ColumnName::Path:
                result = games[index.row()].path;
                break;
        }

        return QVariant(result.c_str());
    }
    return QVariant();
}

QVariant GamesTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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
        case ColumnName::Path:
            return tr("Path");
    }

    throw std::runtime_error("Unexpected result");
}
