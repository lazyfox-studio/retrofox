#pragma once

#include <QAbstractTableModel>

#include <vector>

#include <QVariant>

#include <database.h>
#include <entities/game.h>

namespace GamesImportWizard
{
    class ScraperTableModel : public QAbstractTableModel
    {
        Q_OBJECT

        enum CollumnName
        {
            Name,
            Year
        };

        std::vector<Database::Entities::Game> games;

    public:
        explicit ScraperTableModel(QObject *parent = nullptr);
        ~ScraperTableModel();

        Database::Entities::Game game(const QModelIndex &index);

        void load(std::vector<long> scraper_game_ids);

    protected:
        int rowCount(const QModelIndex &parent) const;
        int columnCount(const QModelIndex &parent) const;
        QVariant data(const QModelIndex &index, int role) const;

        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    };
}
