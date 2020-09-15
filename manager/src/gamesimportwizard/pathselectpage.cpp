#include "gamesimportwizard/pathselectpage.h"
#include "ui_pathselectpage.h"

namespace GamesImportWizard
{

    PathSelectPage::PathSelectPage(QWidget *parent)
        : QWizardPage(parent), ui(new Ui::PathSelectPage)
    {
        ui->setupUi(this);

        p_platform_list_model = new PlatformListModel();
        ui->combobox_platform->setModel(p_platform_list_model);
        connect(ui->combobox_platform, SIGNAL(currentIndexChanged(int)), this, SLOT(selectPlatform(int)));

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

    void PathSelectPage::selectPlatform(int index)
    {
        SharedData::instance().m_platform_id = p_platform_list_model->platform(index).id;
    }
}
