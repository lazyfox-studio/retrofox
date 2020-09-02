#include "gamestablemodel.h"

GamesTableModel::GamesTableModel(QObject *parent) : QAbstractTableModel(parent)
{
    auto base = Database::Connection("D:/Source/retrofox/sln/core/testbase.db");
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

int GamesTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return games.size();
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
            case CollumnName::Name:
                result = games[index.row()].name;
                break;
            case CollumnName::Path:
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
        case CollumnName::Name:
            return "name";
        case CollumnName::Path:
            return "path";
    }
}
