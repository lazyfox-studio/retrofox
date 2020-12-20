#include "platformeditdialog.h"
#include "ui_platformeditdialog.h"

PlatformEditDialog::PlatformEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::PlatformEditDialog)
{
    ui->setupUi(this);
    p_emulator_list_model = new EmulatorListModel;
    ui->combobox_default_emulator->setModel(p_emulator_list_model);
}

PlatformEditDialog::~PlatformEditDialog()
{
    delete ui;
}

void PlatformEditDialog::load(const Entities::Platform& platform, const std::vector<Entities::Extension>& extensions)
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

Entities::Platform PlatformEditDialog::resultPlatform()
{
    Entities::Platform platform;

    platform.id = m_platform.id;
    platform.name = ui->edit_name->text().toStdString();
    platform.default_emulator_id = p_emulator_list_model->emulator(ui->combobox_default_emulator->currentIndex()).id;

    return platform;
}

std::vector<Entities::Extension> PlatformEditDialog::resultExtensions()
{
    QString extensions = ui->edit_extensions->text();
    extensions.replace(" ", "");
    if (extensions.endsWith(';'))
    {
        extensions.chop(1);
    }
    auto extensions_vector = extensions.split(';').toVector();
    std::vector<Entities::Extension> result_extensions;
    for (auto extension : extensions_vector)
    {
        Entities::Extension temp_extension;
        temp_extension.platform_id = m_platform.id;
        temp_extension.extension = extension.toStdString();
        result_extensions.push_back(temp_extension);
    }
    return result_extensions;
}
