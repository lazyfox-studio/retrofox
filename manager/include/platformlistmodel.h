#pragma once

#include <QAbstractListModel>

#include <database.h>

class PlatformListModel : public QAbstractListModel
{
protected:
    std::vector<Entities::Platform> platforms;

public:
    explicit PlatformListModel(QObject *parent = nullptr);
    ~PlatformListModel();

    Entities::Platform platform(int index);
    int findPlatformIndex(long platform_id);

protected:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};
