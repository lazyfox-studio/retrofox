#pragma once

#include <QWizard>

namespace GamesImportWizard
{
    class Wizard : QWizard
    {
        Q_OBJECT

    public:
        explicit Wizard(QWidget *parent = nullptr);
        ~Wizard();
    };
}
