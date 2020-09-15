#pragma once

#include <QWizardPage>

#include <QDir>
#include <QFileDialog>

#include "gamesimportwizard/pages.h"
#include "gamesimportwizard/shareddata.h"
#include "platformlistmodel.h"

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

    protected:
        PlatformListModel* p_platform_list_model;

    public:
        explicit PathSelectPage(QWidget *parent = nullptr);
        ~PathSelectPage();

    protected:
        int nextId() const;
        bool isComplete() const;

    public slots:
        void openDialog();
        void selectPlatform(int index);
    };
}
