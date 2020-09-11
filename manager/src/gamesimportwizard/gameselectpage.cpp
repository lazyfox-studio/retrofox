#include "gamesimportwizard/gameselectpage.h"
#include "ui_gameselectpage.h"

namespace GamesImportWizard
{
    GameSelectPage::GameSelectPage(QWidget *parent) : QWizardPage(parent), ui(new Ui::GameSelectPage)
    {
        ui->setupUi(this);

        p_scraper_table_model = new ScraperTableModel();
        ui->scraper_table->setModel(p_scraper_table_model);
        ui->scraper_table->horizontalHeader()->setStretchLastSection(true);
        ui->scraper_table->verticalHeader()->setVisible(false);
        ui->scraper_table->setSelectionBehavior(QAbstractItemView::SelectRows);
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
        p_scan_folder->start();
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
        p_find_games_information = new Scraper::FindGamesInformation(
                    "445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600", p_scan_folder->result(),
                    "../sln/core/testbase.db");
        connect(p_find_games_information, &Scraper::FindGamesInformation::finished, this, &GameSelectPage::setupTable);
        p_find_games_information->start();
    }

    void GameSelectPage::setupTable()
    {
        return;
    }
}
