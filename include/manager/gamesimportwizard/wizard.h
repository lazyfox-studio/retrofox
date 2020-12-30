#pragma once

#include <QWizard>

#include "manager/gamesimportwizard/pages.h"
#include "manager/gamesimportwizard/welcomepage.h"
#include "manager/gamesimportwizard/pathselectpage.h"
#include "manager/gamesimportwizard/dataprocessingpage.h"
#include "manager/gamesimportwizard/gameselectpage.h"
#include "manager/gamesimportwizard/finalpage.h"

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
