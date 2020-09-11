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
        qDebug() << "First";
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
        qDebug() << "Second";
        Scraper::cleanCache("../sln/core/testbase.db");
        game_ids = p_scan_folder->result();
        for (long id : game_ids)
        {
            PythonFunctions::findGame("445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600", id,
                                      "../sln/core/testbase.db");
        }
    }

    /*void GameSelectPage::setupTable()
    {
        Scraper::cleanCache("../sln/core/testbase.db");
        game_ids = p_scan_folder->result();
        i_game_ids = game_ids.begin();
        if (i_game_ids != game_ids.end())
        {
            findNextGameInformation();
        }
    }

    void GameSelectPage::findNextGameInformation()
    {
        Scraper::cleanCache("../sln/core/testbase.db");
        PythonFunctions::findGame("445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600", *i_game_ids, "../sln/core/testbase.db");
        p_scraper_table_model->load(*i_game_ids, "../sln/core/testbase.db");
        i_game_ids++;
        if (i_game_ids == game_ids.end())
        {
            ui->button_next_game->setDisabled(true);
        }
    }*/
}
