#pragma once

#include <QDialog>

namespace Ui {
class GameEditDialog;
}

class GameEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameEditDialog(QWidget *parent = nullptr);
    ~GameEditDialog();

private:
    Ui::GameEditDialog *ui;
};

