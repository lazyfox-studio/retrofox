#pragma once

#include <QDialog>

#include <entities/game.h>

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

    Database::Entities::Game m_game;

public:
    explicit GameEditDialog(QWidget *parent = nullptr);
    ~GameEditDialog();

    void loadGameData(Database::Entities::Game game);
    Database::Entities::Game resultGameData();

private:
    Ui::GameEditDialog *ui;
};

