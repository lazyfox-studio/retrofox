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

void PlatformEditDialog::load(const Database::Entities::Platform& platform, const std::vector<std::string>& extensions)
{
    m_platform = platform;
    ui->edit_name->setText(m_platform.name.c_str());
    if (m_platform.id < 1000000) //Prefix order
    {
        ui->edit_name->setReadOnly(true);
    }

    QString result_extensions = "";
    for (std::string extension : extensions)
    {
        result_extensions += extension.c_str();
        result_extensions += "; ";
    }
    ui->edit_extensions->setText(result_extensions);
}

Database::Entities::Platform PlatformEditDialog::resultPlatform()
{
    Database::Entities::Platform platform;

    platform.id = m_platform.id;
    platform.name = ui->edit_name->text().toStdString();
    platform.default_emulator_id = m_platform.default_emulator_id; //TODO: emulator select support

    return platform;
}

std::vector<std::string> PlatformEditDialog::resultExtensions()
{
    QString extesions = ui->edit_extensions->text();
    extesions.replace(" ", "");
    auto extensions_vector = extesions.split(';').toVector();
    std::vector<std::string> result_extensions;
    for (QString extension : extensions_vector)
    {
        result_extensions.push_back(extension.toStdString());
    }
    return result_extensions;
}
