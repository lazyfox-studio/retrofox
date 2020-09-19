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

    std::vector<Entities::Game> m_games;

public:
    explicit GamesTableModel(QObject *parent = nullptr);
    ~GamesTableModel();

    Entities::Game game(const QModelIndex &index);

    std::vector<Entities::GameDeveloper> developers(const QModelIndex& index);

    std::vector<Entities::GamePublisher> publishers(const QModelIndex& index);

    std::vector<Entities::GameGenre> genres(const QModelIndex& index);

    void updateGame(Entities::Game game);

    void updateRow(const QModelIndex &index);

    bool insertRow(const Entities::Game& game);

    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

protected:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};
