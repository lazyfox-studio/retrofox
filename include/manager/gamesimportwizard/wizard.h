#pragma once

#include <QWizard>

#include "gamesimportwizard/pages.h"
#include "gamesimportwizard/welcomepage.h"
#include "gamesimportwizard/pathselectpage.h"
#include "gamesimportwizard/dataprocessingpage.h"
#include "gamesimportwizard/gameselectpage.h"
#include "gamesimportwizard/finalpage.h"

namespace GamesImportWizard
{
    class Wizard : public QWizard
    {
        Q_OBJECT

    public:
        explicit Wizard(QWidget *parent = nullptr);
        ~Wizard();
    };
}
