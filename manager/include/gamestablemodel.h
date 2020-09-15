#pragma once

#include <QAbstractTableModel>

#include <vector>

#include <QVariant>

#include <database.h>

/**
 * @ingroup manager
 * @brief The GamesTableModel class
 * @todo Docs
 */
class GamesTableModel : public QAbstractTableModel
{
    Q_OBJECT

    enum ColumnName
    {
        Name,
        Path
    };

    std::vector<Database::Entities::Game> games;

public:
    explicit GamesTableModel(QObject *parent = nullptr);
    ~GamesTableModel();

    Database::Entities::Game game(const QModelIndex &index);

    void updateGame(Database::Entities::Game game);

    void updateRow(const QModelIndex &index);

protected:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};
