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
    m_game = game;
    ui->edit_name->setText(game.name.c_str());
    ui->edit_path->setText(game.path.c_str());
}

Database::Entities::Game GameEditDialog::resultGameData()
{
    Database::Entities::Game result = m_game;

    result.name = ui->edit_name->text().toStdString();
    result.path = ui->edit_path->text().toStdString();

    return result;
}
