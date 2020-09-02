#pragma once

#include <QDialog>

#include <entities/game.h>

namespace Ui {
class GameEditDialog;
}

class GameEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameEditDialog(QWidget *parent = nullptr);
    ~GameEditDialog();

    void loadGameData(Database::Entities::Game game);

private:
    Ui::GameEditDialog *ui;
};

