#pragma once

#include <memory>

#include <QWizardPage>

#include <api-service.h>

#include "gamesimportwizard/pages.h"
#include "gamesimportwizard/scrapertablemodel.h"
#include "gamesimportwizard/shareddata.h"

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

    private:
      Ui::GameSelectPage *ui;

    protected:
        ScraperTableModel* p_scraper_table_model;

        std::vector<long>& game_ids;
        std::vector<std::vector<long>>& scraper_game_ids;
        bool& need_user_choice;

        size_t showed_game_id;

    public:
        explicit GameSelectPage(QWidget *parent = nullptr);
        ~GameSelectPage();

    protected:
        void initializePage();
        int nextId() const;
        bool validatePage();

        void showGame();
    };
}
