#pragma once

#include <QWizardPage>

#include "gamesimportwizard/pages.h"
#undef slots
#include "scraper/scanfolder.h"
#define slots

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

    public:
        explicit GameSelectPage(QWidget *parent = nullptr);
        ~GameSelectPage();

    protected:
        void initializePage();
        int nextId() const;
        bool validatePage();
    };
}
