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
class PlatformsTableModel : public QAbstractTableModel
{
    Q_OBJECT

    enum ColumnName
    {
        Name,
        Emulator
    };

    std::vector<Database::Entities::Platform> m_platforms;

public:
    explicit PlatformsTableModel(QObject *parent = nullptr);
    ~PlatformsTableModel();

    Database::Entities::Platform platform(const QModelIndex &index);
    std::vector<Database::Entities::Extension> extensions(const QModelIndex& index);

    void updatePlatform(Database::Entities::Platform platform);
    void updateExtensions(const std::vector<Database::Entities::Extension>& extensions, long platform_id);

    void updateRow(const QModelIndex &index);

     bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

protected:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};
