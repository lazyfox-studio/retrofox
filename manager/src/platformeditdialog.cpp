#include "platformeditdialog.h"
#include "ui_platformeditdialog.h"

PlatformEditDialog::PlatformEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlatformEditDialog)
{
    ui->setupUi(this);
}

PlatformEditDialog::~PlatformEditDialog()
{
    delete ui;
}
