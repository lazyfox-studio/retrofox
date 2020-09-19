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
    ui->edit_genres->setReadOnly(true);
}

GameEditDialog::~GameEditDialog()
{
    delete ui;
}

void GameEditDialog::load(Entities::Game game,
                          std::vector<Entities::Developer> developers,
                          std::vector<Entities::Publisher> publishers,
                          std::vector<Entities::Genre> genres
                          )
{
    m_game = game;
    ui->edit_name->setText(game.name.c_str());
    ui->edit_path->setText(game.path.c_str());
    ui->combobox_platform->setCurrentIndex(p_platform_list_model->findPlatformIndex(game.platform_id));
    ui->plaintextedit_description->setPlainText(game.description.c_str());

    //Setup developers
    QString result_developers = "";
    for (auto developer : developers)
    {
        result_developers += developer.name.c_str();
        result_developers += "; ";
    }
    ui->edit_developers->setText(result_developers.trimmed());

    //Setup publishers
    QString result_publishers = "";
    for (auto publisher : publishers)
    {
        result_publishers += publisher.name.c_str();
        result_publishers += "; ";
    }
    ui->edit_publishers->setText(result_publishers.trimmed());

    //Setup genres
    QString result_genres = "";
    for (auto genre : genres)
    {
        result_genres += genre.name.c_str();
        result_genres += "; ";
    }
    ui->edit_genres->setText(result_genres.trimmed());
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
