#pragma once

#include <QWizardPage>

#include <QDir>
#include <QFileDialog>

#include "manager/gamesimportwizard/pages.h"
#include "manager/gamesimportwizard/shareddata.h"
#include "manager/platformlistmodel.h"

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
