#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::setLanguage(const QLocale& locale)
{
    QTranslator translator;
    if (!translator.load(locale, "manager", "_", "../manager/translations"))
    {
        return false;
    }
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);
    return true;
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup toolbar
    connect (ui->action_delete, &QAction::triggered, this, &MainWindow::removeRecords);
    connect (ui->action_new, &QAction::triggered, this, &MainWindow::insertRecords);

    //Setup games table
    p_games_table_model = new GamesTableModel();
    ui->table_games->setModel(p_games_table_model);
    ui->table_games->horizontalHeader()->setStretchLastSection(true);
    ui->table_games->verticalHeader()->setVisible(false);
    ui->table_games->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->table_games, &QTableView::doubleClicked, this, &MainWindow::editGame);

    //Setup platforms table
    p_platforms_table_model = new PlatformsTableModel();
    ui->table_platforms->setModel(p_platforms_table_model);
    ui->table_platforms->horizontalHeader()->setStretchLastSection(true);
    ui->table_platforms->verticalHeader()->setVisible(false);
    ui->table_platforms->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->table_platforms, &QTableView::doubleClicked, this, &MainWindow::editPlatform);

    //Setup emulators table
    p_emulators_table_model = new EmulatorsTableModel();
    ui->table_emulators->setModel(p_emulators_table_model);
    ui->table_emulators->horizontalHeader()->setStretchLastSection(true);
    ui->table_emulators->verticalHeader()->setVisible(false);
    ui->table_platforms->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->table_emulators, &QTableView::doubleClicked, this, &MainWindow::editEmulator);

    //Setup user system language
    if (!setLanguage(QLocale::system()))
    {
        setLanguage(QLocale("en_US"));
    }

    //Setup menu slots
    connect(ui->action_import_games, &QAction::triggered, this, &MainWindow::importGames);

    connect(ui->action_english, &QAction::triggered, this, &MainWindow::setLanguageEnglish);
    connect(ui->action_russian, &QAction::triggered, this, &MainWindow::setLanguageRussian);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::importGames()
{
    wizard = std::make_shared<GamesImportWizard::Wizard>();
    wizard->setModal(true);
    wizard->show();

}

void MainWindow::editGame(const QModelIndex &index)
{
    auto dialog = new GameEditDialog();
    auto game = p_games_table_model->game(index);
    dialog->load(game);
    dialog->exec();

    if (dialog->result() == QDialog::Accepted)
    {
        auto result_game = dialog->resultGame();
        p_games_table_model->updateGame(result_game);
        p_games_table_model->updateRow(index);
    }
}

void MainWindow::editPlatform(const QModelIndex &index)
{
    auto dialog = new PlatformEditDialog();
    dialog->load(p_platforms_table_model->platform(index), p_platforms_table_model->extensions(index));
    dialog->exec();

    if (dialog->result() == QDialog::Accepted)
    {
        p_platforms_table_model->updatePlatform(dialog->resultPlatform());
        p_platforms_table_model->updateExtensions(dialog->resultExtensions(), dialog->resultPlatform().id);
        p_platforms_table_model->updateRow(index);
    }
}

void MainWindow::editEmulator(const QModelIndex &index)
{
    auto dialog = new EmulatorEditDialog();
    dialog->load(p_emulators_table_model->emulator(index));
    dialog->exec();

    if (dialog->result() == QDialog::Accepted)
    {
        p_emulators_table_model->updateEmulator(dialog->resultEmulator());
        p_emulators_table_model->updateRow(index);
    }
}

void MainWindow::insertRecords()
{
    int table_index = ui->tab_viewer->currentIndex();
    switch (table_index)
    {
        case 0: ///< Games table
            auto dialog = new GameEditDialog;
            dialog->exec();
            if (dialog->result() == QDialog::Accepted)
            {
                p_games_table_model->insertRow(dialog->resultGame());
            }
    }
}

void MainWindow::removeRecords()
{
    int table_index = ui->tab_viewer->currentIndex();
    switch (table_index)
    {
        case 0: ///< Games table
            if (!ui->table_games->selectionModel()->hasSelection())
            {
                return;
            }
            p_games_table_model->removeRows(ui->table_games->selectionModel()->selectedRows().first().row(), 1);
            break;
        case 1: ///< Platforms table
            if (!ui->table_platforms->selectionModel()->hasSelection())
            {
                return;
            }
            p_platforms_table_model->removeRows(ui->table_platforms->selectionModel()->selectedRows().first().row(), 1);
            break;
        case 2: ///< Emulators table
            if (!ui->table_emulators->selectionModel()->hasSelection())
            {
                return;
            }
            p_emulators_table_model->removeRows(ui->table_emulators->selectionModel()->selectedRows().first().row(), 1);
            break;
    }
}

void MainWindow::setLanguageEnglish()
{
    setLanguage(QLocale("en_US"));
}

void MainWindow::setLanguageRussian()
{
    setLanguage(QLocale("ru_RU"));
}

