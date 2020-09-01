#include "gameeditdialog.h"
#include "ui_gameeditdialog.h"

GameEditDialog::GameEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::GameEditDialog)
{
    ui->setupUi(this);
}

GameEditDialog::~GameEditDialog()
{
    delete ui;
}
