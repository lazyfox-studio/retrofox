#pragma once

#include <memory>

#include <QWizardPage>

#include <api-service/api-service.h>

#include "manager/gamesimportwizard/pages.h"
#include "manager/gamesimportwizard/scrapertablemodel.h"
#include "manager/gamesimportwizard/shareddata.h"

#include "manager/scraper/functions.h"
#include "manager/scraper/findgamesinformation.h"
#include "manager/scraper/scanfolder.h"

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

        long m_selected_scraper_game_id;

    public:
        explicit GameSelectPage(QWidget *parent = nullptr);
        ~GameSelectPage();

    protected:
        void initializePage();
        int nextId() const;
        bool validatePage();

        void showGame();
        bool findNextGame();

    protected slots:
        void selectGame(const QModelIndex& index);
        void updateGameAndGoNext();
    };
}
