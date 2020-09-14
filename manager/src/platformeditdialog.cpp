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

void PlatformEditDialog::load(const Database::Entities::Platform& platform, const std::vector<Database::Entities::Extension>& extensions)
{
    m_platform = platform;
    ui->edit_name->setText(m_platform.name.c_str());
    if (m_platform.id < 1000000) //Prefix order
    {
        ui->edit_name->setReadOnly(true);
    }

    QString result_extensions = "";
    for (auto extension : extensions)
    {
        result_extensions += extension.extension.c_str();
        result_extensions += "; ";
    }
    ui->edit_extensions->setText(result_extensions.trimmed());
}

Database::Entities::Platform PlatformEditDialog::resultPlatform()
{
    Database::Entities::Platform platform;

    platform.id = m_platform.id;
    platform.name = ui->edit_name->text().toStdString();
    platform.default_emulator_id = m_platform.default_emulator_id; //TODO: emulator select support

    return platform;
}

std::vector<Database::Entities::Extension> PlatformEditDialog::resultExtensions()
{
    QString extensions = ui->edit_extensions->text();
    extensions.replace(" ", "");
    if (extensions.endsWith(';'))
    {
        extensions.chop(1);
    }
    auto extensions_vector = extensions.split(';').toVector();
    std::vector<Database::Entities::Extension> result_extensions;
    for (auto extension : extensions_vector)
    {
        Database::Entities::Extension temp_extension;
        temp_extension.platform_id = m_platform.id;
        temp_extension.extension = extension.toStdString();
        result_extensions.push_back(temp_extension);
    }
    return result_extensions;
}
