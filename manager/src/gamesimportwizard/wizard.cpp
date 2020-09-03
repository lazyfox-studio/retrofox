#include "gamesimportwizard/wizard.h"

namespace GamesImportWizard
{
    Wizard::Wizard(QWidget *parent) : QWizard(parent)
    {
        setPage(Pages::Welcome, new WelcomePage);
    }

    Wizard::~Wizard()
    {

    }
}
