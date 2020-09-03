#pragma once

#include <QWizardPage>

namespace Ui {
class FinalPage;
}

namespace GamesImportWizard
{
    class FinalPage : public QWizardPage
    {
        Q_OBJECT

    private:
        Ui::FinalPage *ui;


    public:
        explicit FinalPage(QWidget *parent = nullptr);
        ~FinalPage();
    };
}
