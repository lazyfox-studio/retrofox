#pragma once

#include <QWizardPage>

#include "gamesimportwizard/pages.h"

namespace Ui{
class WelcomePage;
}

namespace GamesImportWizard
{
    class WelcomePage : public QWizardPage
    {
        Q_OBJECT

    private:
        Ui::WelcomePage *ui;

    public:
       explicit WelcomePage(QWidget *parent = nullptr);
       ~WelcomePage();

    protected:
       int nextId() const;
       bool validatePage();
    };
}

