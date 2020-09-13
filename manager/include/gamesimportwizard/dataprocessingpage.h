#pragma once

#include <QWizardPage>

#include "gamesimportwizard/pages.h"
#include "gamesimportwizard/shareddata.h"
#include "ui_dataprocessingpage.h"

#include "scraper/functions.h"
#include "scraper/findgamesinformation.h"
#include "scraper/scanfolder.h"

namespace Ui{
class DataProcessingPage;
}

namespace GamesImportWizard
{
    class DataProcessingPage : public QWizardPage
    {
        Q_OBJECT

    private:
        Ui::DataProcessingPage *ui;

    protected:
        Scraper::ScanFolder* p_scan_folder;
        Scraper::FindGamesInformation* p_find_games_information;

        std::vector<long>& game_ids;
        std::vector<std::vector<long>>& scraper_game_ids;
        bool& need_user_choice;

        bool m_is_complete;

    public:
       explicit DataProcessingPage(QWidget *parent = nullptr);
       ~DataProcessingPage();

        void initializePage();
        bool isComplete() const;

    public slots:
        void findGamesInformation();
        void finalize();

    protected:
       int nextId() const;
    };
}

