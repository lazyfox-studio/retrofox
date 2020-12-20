#include "manager/gamesimportwizard/finalpage.h"
#include "ui_finalpage.h"

namespace GamesImportWizard
{
    FinalPage::FinalPage(QWidget *parent) : QWizardPage(parent), ui(new Ui::FinalPage)
    {
        ui->setupUi(this);
    }

    FinalPage::~FinalPage()
    {
        delete ui;
    }
}
