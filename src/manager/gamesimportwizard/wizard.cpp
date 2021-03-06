#include "manager/gamesimportwizard/wizard.h"

namespace GamesImportWizard
{
    Wizard::Wizard(QWidget *parent) : QWizard(parent)
    {
        setPage(Pages::Welcome, new WelcomePage);
        setPage(Pages::PathSelect, new PathSelectPage);
        setPage(Pages::DataProcessing, new DataProcessingPage);
        setPage(Pages::GameSelect, new GameSelectPage);
        setPage(Pages::Final, new FinalPage);
    }

    Wizard::~Wizard()
    {

    }
}
