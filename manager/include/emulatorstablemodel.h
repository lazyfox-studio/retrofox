#pragma once

#include <QAbstractTableModel>

#include <vector>

#include <QVariant>

#include <database.h>

#include "additionalentities/extendedemulator.h"

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
        Name,
        Platform
    };

    std::vector<AdditionalEntities::ExtendedEmulator> m_emulators;

public:
    explicit EmulatorsTableModel(QObject *parent = nullptr);
    ~EmulatorsTableModel();

    Entities::Emulator emulator(const QModelIndex &index);

    void updateEmulator(Entities::Emulator emulator);

    void updateRow(const QModelIndex &index);

    bool insertRow(const Entities::Emulator& emulator);

    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

protected:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};
