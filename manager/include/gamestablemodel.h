#pragma once

#include <QAbstractTableModel>

#include <QVariant>

class GamesTableModel : public QAbstractTableModel
{
Q_OBJECT

public:
    GamesTableModel(QObject *parent = nullptr);
    ~GamesTableModel();

protected:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};
