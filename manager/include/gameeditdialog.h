#pragma once

#include <QDialog>

#include <database.h>

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

    void load(Database::Entities::Game game);
    Database::Entities::Game resultGame();

private:
    Ui::GameEditDialog *ui;
};

