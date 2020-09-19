#include "gamesimportwizard/scrapertablemodel.h"

namespace GamesImportWizard
{
    ScraperTableModel::ScraperTableModel(QObject *parent) : QAbstractTableModel(parent)
    {

    }

   ScraperTableModel::~ScraperTableModel()
    {

    }

    Database::Entities::ScraperGame ScraperTableModel::game(const QModelIndex &index)
    {
        return games[index.row()];
    }

    void ScraperTableModel::load(long game_id, std::string path_to_db)
    {
        auto base = Database::Connection(path_to_db);
        auto query = base.query("SELECT * FROM `scraper_cache_games` WHERE `game_id` = ?");
        query.bindMany(game_id);
        games = Database::Entities::fetchEntities<Database::Entities::ScraperGame>(query);
    }

    Database::Entities::ScraperGame ScraperTableModel::game(QModelIndex &index)
    {
        return games[index.row()];
    }


    int ScraperTableModel::rowCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent)
        return static_cast<int>(games.size());
    }

    int ScraperTableModel::columnCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent)
        return 2;
    }

    QVariant ScraperTableModel::data(const QModelIndex &index, int role) const
    {
        if (role == Qt::DisplayRole)
        {
            std::string result;
            switch(index.column())
            {
                case ColumnName::Name:
                    result = games[index.row()].name;
                    break;
                case ColumnName::Year:
                    result = games[index.row()].release_date;
                    break;
            }
            return QVariant(result.c_str());
        }
        return QVariant();
    }

    QVariant ScraperTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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
            case ColumnName::Year:
                return tr("Year");
        }
        throw std::runtime_error("Unexpected result");
    }
}
