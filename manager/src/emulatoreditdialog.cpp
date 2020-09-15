#include "emulatoreditdialog.h"
#include "ui_emulatoreditdialog.h"

EmulatorEditDialog::EmulatorEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmulatorEditDialog)
{
    ui->setupUi(this);
}

EmulatorEditDialog::~EmulatorEditDialog()
{
    delete ui;
}
