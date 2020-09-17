#include "gameeditdialog.h"
#include "ui_gameeditdialog.h"

GameEditDialog::GameEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::GameEditDialog)
{
    ui->setupUi(this);
    p_platform_list_model = new PlatformListModel;
    ui->combobox_platform->setModel(p_platform_list_model);
}

GameEditDialog::~GameEditDialog()
{
    delete ui;
}

void GameEditDialog::load(Database::Entities::Game game)
{
    m_game = game;
    ui->edit_name->setText(game.name.c_str());
    ui->edit_path->setText(game.path.c_str());
    ui->combobox_platform->setCurrentIndex(p_platform_list_model->findPlatformIndex(game.platform_id));
}

Database::Entities::Game GameEditDialog::resultGame()
{
    Database::Entities::Game result = m_game;

    result.name = ui->edit_name->text().toStdString();
    result.path = ui->edit_path->text().toStdString();
    result.platform_id = p_platform_list_model->platform(ui->combobox_platform->currentIndex()).id;

    return result;
}
