#include "gamesimportwizard/gameselectpage.h"
#include "ui_gameselectpage.h"

namespace GamesImportWizard
{
    GameSelectPage::GameSelectPage(QWidget *parent) : QWizardPage(parent), ui(new Ui::GameSelectPage)
    {
        ui->setupUi(this);
    }

    GameSelectPage::~GameSelectPage()
    {
        delete ui;
    }

    void GameSelectPage::initializePage()
    {
        //TODO: Platform selection
        Scraper::cleanCache("../sln/core/testbase.db");
        Scraper::scanFloder(field("path").toString().toStdString(), 10, "../sln/core/testbase.db");
    }

    int GameSelectPage::nextId() const
    {
        return Pages::Final;
    }

    bool GameSelectPage::validatePage()
    {
        return true;
    }
}
