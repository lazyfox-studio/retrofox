#pragma once

#include <QAbstractTableModel>

#include <vector>

#include <QVariant>

#include <database.h>
#include <entities/game.h>

class GamesTableModel : public QAbstractTableModel
{
Q_OBJECT

    enum CollumnName
    {
        Name,
        Path
    };

    std::vector<Database::Entities::Game> games;

public:
    GamesTableModel(QObject *parent = nullptr);
    ~GamesTableModel();

    Database::Entities::Game game(const QModelIndex &index);

protected:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};
