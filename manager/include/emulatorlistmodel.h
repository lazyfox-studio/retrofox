#pragma once

#include <QAbstractListModel>

#include <database.h>

class EmulatorListModel : public QAbstractListModel
{
protected:
    std::vector<Entities::Emulator> emulators;

public:
    explicit EmulatorListModel(QObject *parent = nullptr);
    ~EmulatorListModel();

    Entities::Emulator emulator(int index);
    int findEmulatorIndex(long emulator_id);

protected:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};
