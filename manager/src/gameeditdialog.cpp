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

void GameEditDialog::loadGameData(Database::Entities::Game game)
{
    ui->edit_name->setText(game.name.c_str());
    ui->edit_path->setText(game.path.c_str());
}
