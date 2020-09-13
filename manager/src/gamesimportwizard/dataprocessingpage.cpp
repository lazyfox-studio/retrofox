#include "gamesimportwizard/dataprocessingpage.h"

namespace GamesImportWizard
{
    DataProcessingPage::DataProcessingPage(QWidget *parent)
        : QWizardPage(parent), ui(new Ui::DataProcessingPage),
          game_ids(SharedData::instance().gameIds()),
          scraper_game_ids(SharedData::instance().scraperGameIds()),
          need_user_choice(SharedData::instance().needUserChoice())
    {
        m_is_complete = false;
        ui->setupUi(this);
    }

    DataProcessingPage::~DataProcessingPage()
    {
        delete ui;
    }

    void DataProcessingPage::initializePage()
    {
        //TODO: Platform selection
        p_scan_folder = new Scraper::ScanFolder(field("path").toString().toStdString(), 10, "../sln/core/testbase.db");
        connect(p_scan_folder, &Scraper::ScanFolder::finished, this, &DataProcessingPage::findGamesInformation);
        PythonThreadController::instance().releaseInterpreter();
        ui->status_label->setText(tr("Scanning folder..."));
        p_scan_folder->start();
    }

    bool DataProcessingPage::isComplete() const
    {
        return m_is_complete;
    }

    int DataProcessingPage::nextId() const
    {
        return Pages::GameSelect;
    }

    void DataProcessingPage::findGamesInformation()
    {
        game_ids = p_scan_folder->result();
        ui->status_label->setText(tr("Cleaning cache..."));
        Scraper::cleanCache("../sln/core/testbase.db");
        p_find_games_information = new Scraper::FindGamesInformation(
                    "445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600",
                    game_ids,
                    "../sln/core/testbase.db");
        connect(p_find_games_information, &Scraper::FindGamesInformation::finished, this, &DataProcessingPage::finalize);
        ui->status_label->setText(tr("Fetching games information from Internet..."));
        p_find_games_information->start();
    }

    void DataProcessingPage::finalize()
    {
        scraper_game_ids = p_find_games_information->result();
        ui->status_label->setText(tr("Updating database..."));
        need_user_choice = false;
        for (std::vector<long>& game : scraper_game_ids)
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
        ui->status_label->setText(tr("Done. Click \"Next\"."));
        ui->progress_bar->setVisible(false);
        m_is_complete = true;
        emit completeChanged();
    }
}
