#include "gamesimportwizard/gameselectpage.h"
#include "ui_gameselectpage.h"

namespace GamesImportWizard
{
    GameSelectPage::GameSelectPage(QWidget *parent) : QWizardPage(parent), ui(new Ui::GameSelectPage)
    {
        ui->setupUi(this);
    }

    GameSelectPage::~GameSelectPage()
    {
        delete ui;
    }

    void GameSelectPage::initializePage()
    {
        //TODO: Platform selection
        //Scraper::cleanCache("../sln/core/testbase.db");
        //Scraper::scanFloder(field("path").toString().toStdString(), 10, "../sln/core/testbase.db");
        Scraper::ScanFolder scan_folder(field("path").toString().toStdString(), 10, "../sln/core/testbase.db");
        scan_folder.run();
        //TODO: Get games id from python script
        /*auto base = Database::Connection("../sln/core/testbase.db");
        auto query = base.query("SELECT `id` FROM `games`");
        while (auto row = query.fetchRow())
        {
            auto games = Scraper::findGameInformation(row.column<long>("id"), "../sln/core/testbase.db");
            if (games.size() > 1)
            {
                //Send to table
            }
        }*/

    }

    int GameSelectPage::nextId() const
    {
        return Pages::Final;
    }

    bool GameSelectPage::validatePage()
    {
        return true;
    }
}
