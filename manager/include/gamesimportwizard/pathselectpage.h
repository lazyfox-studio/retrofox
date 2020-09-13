#pragma once

#include <QWizardPage>

#include <QDir>
#include <QFileDialog>

#include "gamesimportwizard/pages.h"

namespace Ui {
class PathSelectPage;
}

namespace GamesImportWizard
{
    class PathSelectPage : public QWizardPage
    {
        Q_OBJECT

    private:
        Ui::PathSelectPage *ui;

    public:
        explicit PathSelectPage(QWidget *parent = nullptr);
        ~PathSelectPage();

    protected:
        int nextId() const;
        bool isComplete() const;

    public slots:
        void openDialog();
    };
}
