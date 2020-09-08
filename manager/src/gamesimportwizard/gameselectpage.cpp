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
        p_scan_folder = new Scraper::ScanFolder(field("path").toString().toStdString(), 10, "../sln/core/testbase.db");
        connect(p_scan_folder, &Scraper::ScanFolder::finished, this, &GameSelectPage::findGamesInformation);
        p_scan_folder->run();
    }

    int GameSelectPage::nextId() const
    {
        return Pages::Final;
    }

    bool GameSelectPage::validatePage()
    {
        return true;
    }

    void GameSelectPage::findGamesInformation()
    {
        Scraper::cleanCache("../sln/core/testbase.db");
    }
}
