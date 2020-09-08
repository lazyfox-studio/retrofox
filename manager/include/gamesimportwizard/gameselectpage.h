#pragma once

#include <memory>

#include <QWizardPage>

#include "gamesimportwizard/pages.h"
#undef slots
#include "scraper/scanfolder.h"
#include "scraper/findgameinformation.h"
#define slots
#include "scraper/functions.h"

namespace Ui {
class GameSelectPage;
}

namespace GamesImportWizard
{
    class GameSelectPage : public QWizardPage
    {
        Q_OBJECT
    protected:
        Scraper::ScanFolder* p_scan_folder;

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
    };
}
