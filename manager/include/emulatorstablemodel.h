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
class EmulatorsTableModel : public QAbstractTableModel
{
    Q_OBJECT

    enum ColumnName
    {
        Name
    };

    std::vector<Database::Entities::Emulator> m_emulators;

public:
    explicit EmulatorsTableModel(QObject *parent = nullptr);
    ~EmulatorsTableModel();

    Database::Entities::Emulator emulator(const QModelIndex &index);

    void updateEmulator(Database::Entities::Emulator emulator);

    void updateRow(const QModelIndex &index);

protected:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};
