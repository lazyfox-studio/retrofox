#include "gamesimportwizard/pathselectpage.h"
#include "ui_pathselectpage.h"

namespace GamesImportWizard
{

    PathSelectPage::PathSelectPage(QWidget *parent)
        : QWizardPage(parent), ui(new Ui::PathSelectPage)
    {
        ui->setupUi(this);
        ui->edit_path->setReadOnly(true);
        registerField("path", ui->edit_path);
        connect(ui->button_explore, &QPushButton::clicked, this, &PathSelectPage::openDialog);
        //connect(ui->edit_path, &QLineEdit::textChanged, this, &PathSelectPage::completeChanged);
    }

    PathSelectPage::~PathSelectPage()
    {
        delete ui;
    }

    int PathSelectPage::nextId() const
    {
        return Pages::DataProcessing;
    }

    bool PathSelectPage::isComplete() const
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
        emit completeChanged();
    }
}
