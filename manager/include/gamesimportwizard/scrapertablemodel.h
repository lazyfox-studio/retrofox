#pragma once

#include <QAbstractTableModel>

#include <vector>

#include <QVariant>
#include <database.h>

namespace GamesImportWizard
{
    class ScraperTableModel : public QAbstractTableModel
    {
        Q_OBJECT

        enum ColumnName
        {
            Name,
            Year
        };

        std::vector<Entities::ScraperGame> games;

    public:
        explicit ScraperTableModel(QObject *parent = nullptr);
        ~ScraperTableModel();

        Entities::ScraperGame game(const QModelIndex &index);

        void load(long game_id, std::string path_to_db);
        Entities::ScraperGame game(QModelIndex& index);

    protected:
        int rowCount(const QModelIndex &parent) const;
        int columnCount(const QModelIndex &parent) const;
        QVariant data(const QModelIndex &index, int role) const;

        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    };
}
