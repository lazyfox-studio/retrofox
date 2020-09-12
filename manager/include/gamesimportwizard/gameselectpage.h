#pragma once

#include <memory>

#include <QWizardPage>

#include <api-service.h>

#include "gamesimportwizard/pages.h"
#include "gamesimportwizard/scrapertablemodel.h"

#include "scraper/functions.h"
#include "scraper/findgamesinformation.h"
#include "scraper/scanfolder.h"

namespace Ui {
class GameSelectPage;
}

namespace GamesImportWizard
{
    class GameSelectPage : public QWizardPage
    {
        Q_OBJECT

    public:


    protected:
        Scraper::ScanFolder* p_scan_folder;
        Scraper::FindGamesInformation* p_find_games_information;

        ScraperTableModel* p_scraper_table_model;

        std::vector<long> game_ids;
        std::vector<std::vector<long>> scraper_game_ids;

        size_t showed_game_id;

    private:
      Ui::GameSelectPage *ui;

    public:
        explicit GameSelectPage(QWidget *parent = nullptr);
        ~GameSelectPage();

    protected:
        void initializePage();
        int nextId() const;
        bool validatePage();

        void showGame();

    public slots:
        void findGamesInformation();
        void setupTable();

    signals:
        void runScanFolder();
    };
}
