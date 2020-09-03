#include "gamesimportwizard/pathselectpage.h"
#include "ui_pathselectpage.h"

namespace GamesImportWizard
{

    PathSelectPage::PathSelectPage(QWidget *parent) : QWizardPage(parent), ui(new Ui::PathSelectPage)
    {
        ui->setupUi(this);
        connect(ui->button_explore, &QPushButton::clicked, this, &PathSelectPage::openDialog);
    }

    PathSelectPage::~PathSelectPage()
    {
        delete ui;
    }

    int PathSelectPage::nextId() const
    {
        return Pages::Final;
    }

    bool PathSelectPage::validatePage()
    {
        if (ui->edit_path->text() == "")
        {
            return false;
        }
        QDir directory(ui->edit_path->text());
        return directory.exists();
    }

    void PathSelectPage::openDialog()
    {
        QString path = QFileDialog::getExistingDirectory();
        if (path != "")
        {
            ui->edit_path->setText(path);
        }
    }
}
