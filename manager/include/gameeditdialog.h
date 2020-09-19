#pragma once

#include <QDialog>

#include <QFileDialog>

#include <database.h>

#include "platformlistmodel.h"

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
              std::vector<Entities::GameDeveloper> developers,
              std::vector<Entities::GamePublisher> publishers,
              std::vector<Entities::GameGenre> genres
              );
    Entities::Game resultGame();

private:
    Ui::GameEditDialog *ui;

public slots:
    void pathSelectDialog();
};

