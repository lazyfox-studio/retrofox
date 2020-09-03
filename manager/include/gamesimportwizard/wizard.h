#pragma once

#include <QWizard>

#include "gamesimportwizard/pages.h"
#include "gamesimportwizard/welcomepage.h"

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
