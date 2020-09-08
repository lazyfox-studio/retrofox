#include "gamesimportwizard/scrapertablemodel.h"

namespace GamesImportWizard
{
    ScraperTableModel::ScraperTableModel(QObject *parent) : QAbstractTableModel(parent)
    {

    }

   ScraperTableModel::~ScraperTableModel()
    {

    }

    Database::Entities::Game ScraperTableModel::game(const QModelIndex &index)
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
                case CollumnName::Name:
                    result = games[index.row()].name;
                    break;
                case CollumnName::Year:
                    result = games[index.row()].id; //TODO: Year support
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
            case CollumnName::Name:
                return tr("Name");
            case CollumnName::Year:
                return tr("Year");
        }
        throw std::runtime_error("Unexpected result");
    }
}
