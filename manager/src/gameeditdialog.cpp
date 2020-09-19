#include "gameeditdialog.h"
#include "ui_gameeditdialog.h"

GameEditDialog::GameEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::GameEditDialog)
{
    ui->setupUi(this);
    p_platform_list_model = new PlatformListModel;
    ui->combobox_platform->setModel(p_platform_list_model);
    connect(ui->button_explore, &QPushButton::clicked, this, &GameEditDialog::pathSelectDialog);
    ui->edit_developers->setReadOnly(true);
    ui->edit_publishers->setReadOnly(true);
}

GameEditDialog::~GameEditDialog()
{
    delete ui;
}

void GameEditDialog::load(Entities::Game game,
                          std::vector<Entities::GameDeveloper> developers,
                          std::vector<Entities::GamePublisher> publishers,
                          std::vector<Entities::GameGenre> genres
                          )
{
    m_game = game;
    ui->edit_name->setText(game.name.c_str());
    ui->edit_path->setText(game.path.c_str());
    ui->combobox_platform->setCurrentIndex(p_platform_list_model->findPlatformIndex(game.platform_id));
    ui->plaintextedit_description->setPlainText(game.description.c_str());
}

Entities::Game GameEditDialog::resultGame()
{
    Entities::Game result = m_game;

    result.name = ui->edit_name->text().toStdString();
    result.path = ui->edit_path->text().toStdString();
    result.platform_id = p_platform_list_model->platform(ui->combobox_platform->currentIndex()).id;

    return result;
}

void GameEditDialog::pathSelectDialog()
{
    QString path = QFileDialog::getOpenFileName();
    if (path != "")
    {
        ui->edit_path->setText(path);
    }
}
