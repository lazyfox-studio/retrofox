#include "manager/gamesimportwizard/gameselectpage.h"
#include "ui_gameselectpage.h"

namespace GamesImportWizard
{
    GameSelectPage::GameSelectPage(QWidget *parent)
        : QWizardPage(parent), ui(new Ui::GameSelectPage),
          game_ids(SharedData::instance().gameIds()),
          scraper_game_ids(SharedData::instance().scraperGameIds()),
          need_user_choice(SharedData::instance().needUserChoice())
    {
        ui->setupUi(this);

        p_scraper_table_model = new ScraperTableModel();
        ui->scraper_table->setModel(p_scraper_table_model);
        ui->scraper_table->horizontalHeader()->setStretchLastSection(true);
        ui->scraper_table->verticalHeader()->setVisible(false);
        ui->scraper_table->setSelectionBehavior(QAbstractItemView::SelectRows);

        connect(ui->scraper_table, &QTableView::clicked, this, &GameSelectPage::selectGame);
        connect(ui->button_select_game, &QPushButton::clicked, this, &GameSelectPage::updateGameAndGoNext);
    }

    GameSelectPage::~GameSelectPage()
    {
        delete ui;
    }

    void GameSelectPage::initializePage()
    {
        if (need_user_choice)
        {
            ui->button_select_game->setEnabled(true);
            showed_game_id = 0;
            while ((showed_game_id < scraper_game_ids.size()) && (scraper_game_ids[showed_game_id].size() <= 1))
            {
                showed_game_id++;
            }
            showGame();
        }
    }

    int GameSelectPage::nextId() const
    {
        return Pages::Final;
    }

    bool GameSelectPage::validatePage()
    {
        return true;
    }

    void GameSelectPage::showGame()
    {
        p_scraper_table_model->load(game_ids[showed_game_id], "../sln/core/testbase.db");
        ui->button_select_game->setDisabled(true);
    }

    bool GameSelectPage::findNextGame()
    {
        showed_game_id++;
        while ((showed_game_id < scraper_game_ids.size()) && (scraper_game_ids[showed_game_id].size() <= 1))
        {
            showed_game_id++;
        }
        return (showed_game_id != scraper_game_ids.size());
    }

    void GameSelectPage::selectGame(const QModelIndex& index)
    {
        m_selected_scraper_game_id = p_scraper_table_model->game(index).id;
        ui->button_select_game->setEnabled(true);
    }

    void GameSelectPage::updateGameAndGoNext()
    {
        Scraper::updateGameFromScraper(m_selected_scraper_game_id,  "../sln/core/testbase.db");
        if (findNextGame())
        {
            showGame();
        }
        else
        {
            disconnect(ui->scraper_table, &QTableView::clicked, this, &GameSelectPage::selectGame);
        }
        ui->button_select_game->setDisabled(true);
    }
}
