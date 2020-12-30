#include "manager/emulatoreditdialog.h"
#include "ui_emulatoreditdialog.h"

EmulatorEditDialog::EmulatorEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::EmulatorEditDialog)
{
    ui->setupUi(this);
    p_platform_list_model = new PlatformListModel;
    ui->combobox_platform->setModel(p_platform_list_model);
    connect(ui->button_explore, &QPushButton::clicked, this, &EmulatorEditDialog::pathSelectDialog);
}

EmulatorEditDialog::~EmulatorEditDialog()
{
    delete ui;
}

void EmulatorEditDialog::load(const Entities::Emulator &emulator)
{
    m_emulator = emulator;
    ui->edit_name->setText(m_emulator.name.c_str());
    ui->combobox_platform->setCurrentIndex(p_platform_list_model->findPlatformIndex(m_emulator.platform_id));
    ui->edit_emulator_path->setText(m_emulator.emulator_path.c_str());
    ui->edit_execution_parameters->setText(m_emulator.execution_parameters.c_str());
}

Entities::Emulator EmulatorEditDialog::resultEmulator()
{
    auto result = m_emulator;
    result.name = ui->edit_name->text().toStdString();
    result.platform_id = p_platform_list_model->platform(ui->combobox_platform->currentIndex()).id;
    result.emulator_path = ui->edit_emulator_path->text().toStdString();
    result.execution_parameters = ui->edit_execution_parameters->text().toStdString();
    return result;
}

void EmulatorEditDialog::pathSelectDialog()
{
    QString path = QFileDialog::getOpenFileName();
    if (path != "")
    {
        ui->edit_emulator_path->setText(path);
    }
}

