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
        PythonThreadController::instance().releaseInterpreter();
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
        game_ids = p_scan_folder->result();
        Scraper::cleanCache("../sln/core/testbase.db");
        p_find_games_information = new Scraper::FindGamesInformation(
                    "445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600", game_ids,
                    "../sln/core/testbase.db");
        connect(p_find_games_information, &Scraper::FindGamesInformation::finished, this, &GameSelectPage::setupTable);
        p_find_games_information->start();
    }

    void GameSelectPage::setupTable()
    {
        bool need_user_choice = false;
        scraper_game_ids = p_find_games_information->result();
        for (std::vector<long> game : scraper_game_ids)
        {
            if (game.size() == 1)
            {
                Scraper::updateGameFromScraper(game[0], "../sln/core/testbase.db");
            }
            else if (game.size() > 1)
            {
                need_user_choice = true;
            }
        }
        if (need_user_choice)
        {
            ui->button_next_game->setEnabled(true);
            i_game_ids = game_ids.begin();
            i_scraper_game_ids = scraper_game_ids.begin();
            showGame();
        }
    }

    void GameSelectPage::showGame()
    {
        p_scraper_table_model->load(*i_game_ids, "../sln/core/testbase.db");
        ui->button_next_game->setDisabled(true);
    }
}
