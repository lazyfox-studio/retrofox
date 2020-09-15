#pragma once

#include <QDialog>

namespace Ui {
    class EmulatorEditDialog;
}

class EmulatorEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmulatorEditDialog(QWidget *parent = nullptr);
    ~EmulatorEditDialog();

private:
    Ui::EmulatorEditDialog *ui;
};

