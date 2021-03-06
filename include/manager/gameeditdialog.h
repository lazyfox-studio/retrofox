#pragma once

#include <QDialog>
#include <QFileDialog>

#include <database/database.h>

#include "manager/platformlistmodel.h"

namespace Ui {
class GameEditDialog;
}

/**
 * @ingroup manager
 * @brief The GameEditDialog class
 * @todo Docs
 */
class GameEditDialog : public QDialog
{
    Q_OBJECT

protected:
    PlatformListModel* p_platform_list_model;

    Entities::Game m_game;

public:
    explicit GameEditDialog(QWidget *parent = nullptr);
    ~GameEditDialog();

    void load(Entities::Game game,
              std::vector<Entities::Developer> developers,
              std::vector<Entities::Publisher> publishers,
              std::vector<Entities::Genre> genres
              );
    Entities::Game resultGame();

private:
    Ui::GameEditDialog *ui;

public slots:
    void pathSelectDialog();
};

