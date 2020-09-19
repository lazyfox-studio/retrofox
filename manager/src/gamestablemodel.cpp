#include "gamestablemodel.h"

GamesTableModel::GamesTableModel(QObject *parent) : QAbstractTableModel(parent)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `games`");
    m_games = Entities::fetchEntities<Entities::Game>(query);
}

GamesTableModel::~GamesTableModel()
{

}

Entities::Game GamesTableModel::game(const QModelIndex &index)
{
    return m_games[index.row()];
}

std::vector<Entities::GameDeveloper> GamesTableModel::developers(const QModelIndex &index)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `game_developers` WHERE `game_id` = ?");
    query.bindMany(m_games[index.row()].id);
    return Entities::fetchEntities<Entities::GameDeveloper>(query);
}

std::vector<Entities::GamePublisher> GamesTableModel::publishers(const QModelIndex &index)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `game_publishers` WHERE `game_id` = ?");
    query.bindMany(m_games[index.row()].id);
    return Entities::fetchEntities<Entities::GamePublisher>(query);
}

std::vector<Entities::GameGenre> GamesTableModel::genres(const QModelIndex &index)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `game_genres` WHERE `game_id` = ?");
    query.bindMany(m_games[index.row()].id);
    return Entities::fetchEntities<Entities::GameGenre>(query);
}

void GamesTableModel::updateGame(Entities::Game game)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("UPDATE `games` SET name = ?, path = ?, platform_id = ? WHERE id = ?");
    query.bindMany(game.name.c_str(), game.path.c_str(), game.platform_id, game.id);
    query.execute();
}

void GamesTableModel::updateRow(const QModelIndex &index)
{
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("SELECT * FROM `games` WHERE id = ?");
    query.bindMany(m_games[index.row()].id);

    Entities::Game game(query.fetchRow());
    m_games[index.row()] = game;
}

bool GamesTableModel::insertRow(const Entities::Game& game)
{
    beginInsertRows(QModelIndex(), static_cast<int>(m_games.size()), static_cast<int>(m_games.size()));
    auto base = Database::Connection("../sln/core/testbase.db");
    auto query = base.query("INSERT INTO `games` (name, path, platform_id) VALUES (?, ?, ?);");
    query.bindMany(game.name.c_str(), game.path.c_str(), game.platform_id);
    query.execute();
    m_games.push_back(game);
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

    auto i_remove_start = m_games.begin() + row;
    auto i_remove_end = m_games.begin() + row + count;
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    for (size_t i = 0; i < static_cast<size_t>(count); i++)
    {
        // Delete game information
        auto query = base.query("DELETE FROM `games` WHERE id = ?");
        query.bindMany(m_games[row + i].id);
        query.execute();
        // Delete developers information
        query = base.query("DELETE FROM `game_developers` WHERE `game_id` = ?");
        query.bindMany(m_games[row+i].id);
        query.execute();
        // Delete publishers information
        query = base.query("DELETE FROM `game_publishers` WHERE `game_id` = ?");
        query.bindMany(m_games[row+i].id);
        query.execute();
        // Delete genres information
        query = base.query("DELETE FROM `game_genres` WHERE `game_id` = ?");
        query.bindMany(m_games[row+i].id);
        query.execute();
    }
    m_games.erase(i_remove_start, i_remove_end);
    endRemoveRows();
    return true;
}

int GamesTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_games.size());
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
                result = m_games[index.row()].name;
                break;
            case ColumnName::Path:
                result = m_games[index.row()].path;
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
