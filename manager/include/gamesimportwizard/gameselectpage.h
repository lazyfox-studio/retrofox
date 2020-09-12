#pragma once

#include <memory>

#include <QWizardPage>

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
        std::vector<long> game_ids;

    protected:
        Scraper::ScanFolder* p_scan_folder;
        Scraper::FindGamesInformation* p_find_games_information;

        ScraperTableModel* p_scraper_table_model;

    private:
      Ui::GameSelectPage *ui;

    public:
        explicit GameSelectPage(QWidget *parent = nullptr);
        ~GameSelectPage();

    protected:
        void initializePage();
        int nextId() const;
        bool validatePage();

    public slots:
        void findGamesInformation();
        void setupTable();

    signals:
        void runScanFolder();
    };
}
