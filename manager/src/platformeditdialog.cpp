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

void PlatformEditDialog::load(const Database::Entities::Platform &platform)
{
    m_platform = platform;
    ui->edit_name->setText(m_platform.name.c_str());
    if (m_platform.id < 1000000) //Prefix order
    {
        ui->edit_name->setReadOnly(true);
    }
}

Database::Entities::Platform PlatformEditDialog::resultPlatform()
{
    Database::Entities::Platform platform;

    platform.id = m_platform.id;
    platform.name = ui->edit_name->text().toStdString();
    platform.default_emulator_id = m_platform.default_emulator_id; //TODO: emulator select support

    return platform;
}
