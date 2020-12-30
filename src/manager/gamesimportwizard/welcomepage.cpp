#include "manager/gamesimportwizard/welcomepage.h"
#include "ui_welcomepage.h"

namespace GamesImportWizard
{
    WelcomePage::WelcomePage(QWidget *parent) : QWizardPage(parent), ui(new Ui::WelcomePage)
    {
      ui->setupUi(this);
    }

    WelcomePage::~WelcomePage()
    {
        delete ui;
    }

    int WelcomePage::nextId() const
    {
        return Pages::PathSelect;
    }
}
