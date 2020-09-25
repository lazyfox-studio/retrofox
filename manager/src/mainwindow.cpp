#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::setLanguage(const QLocale& locale)
{
    if (!translator.load(locale, "manager", "_", ":/translations"))
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

    // Toolbar
    connect (ui->action_delete, &QAction::triggered, this, &MainWindow::removeRecords);
    connect (ui->action_edit, &QAction::triggered, this, &MainWindow::editRecord);
    connect (ui->action_new, &QAction::triggered, this, &MainWindow::insertRecord);

    // Games table
    p_games_table_model = new GamesTableModel();
    ui->table_games->setModel(p_games_table_model);
    ui->table_games->horizontalHeader()->setStretchLastSection(true);
    ui->table_games->verticalHeader()->setVisible(false);
    ui->table_games->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_games->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(ui->table_games, &QTableView::doubleClicked, this, &MainWindow::editGame);

    // Setup platforms table
    p_platforms_table_model = new PlatformsTableModel();
    ui->table_platforms->setModel(p_platforms_table_model);
    ui->table_platforms->horizontalHeader()->setStretchLastSection(true);
    ui->table_platforms->verticalHeader()->setVisible(false);
    ui->table_platforms->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_platforms->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(ui->table_platforms, &QTableView::doubleClicked, this, &MainWindow::editPlatform);

    // Emulators table
    p_emulators_table_model = new EmulatorsTableModel();
    ui->table_emulators->setModel(p_emulators_table_model);
    ui->table_emulators->horizontalHeader()->setStretchLastSection(true);
    ui->table_emulators->verticalHeader()->setVisible(false);
    ui->table_emulators->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_emulators->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(ui->table_emulators, &QTableView::doubleClicked, this, &MainWindow::editEmulator);

    // User system language
    if (!setLanguage(QLocale::system()))
    {
        setLanguage(QLocale("en_US"));
    }

    // Menu slots
    connect(ui->action_import_games, &QAction::triggered, this, &MainWindow::importGames);

    connect(ui->action_english, &QAction::triggered, this, &MainWindow::setLanguageEnglish);
    connect(ui->action_russian, &QAction::triggered, this, &MainWindow::setLanguageRussian);

    connect(ui->action_about, &QAction::triggered, this, &MainWindow::showAboutDialog);
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
    dialog->load(game, p_games_table_model->developers(index), p_games_table_model->publishers(index),
                 p_games_table_model->genres(index));
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

void MainWindow::insertRecord()
{
    switch (ui->tab_viewer->currentIndex())
    {
        case TableIndex::Games:
        {
            auto dialog = new GameEditDialog;
            dialog->exec();
            if (dialog->result() == QDialog::Accepted)
            {
                p_games_table_model->insertRow(dialog->resultGame());
            }
            break;
        }
        case TableIndex::Platforms:
        {
            auto dialog = new PlatformEditDialog;
            dialog->exec();
            if (dialog->result() == QDialog::Accepted)
            {
                p_platforms_table_model->insertRow(dialog->resultPlatform());
                p_platforms_table_model->updateExtensions(dialog->resultExtensions(), dialog->resultPlatform().id);
            }
            break;
        }
        case TableIndex::Emulators:
        {
            auto dialog = new EmulatorEditDialog;
            dialog->exec();
            if (dialog->result() == QDialog::Accepted)
            {
                p_emulators_table_model->insertRow(dialog->resultEmulator());
            }
            break;
        }

    }
}

void MainWindow::editRecord()
{
    switch (ui->tab_viewer->currentIndex())
    {
        case TableIndex::Games:
            if (!ui->table_games->selectionModel()->hasSelection())
            {
                return;
            }
            editGame(ui->table_games->selectionModel()->selectedIndexes().first());
            break;
        case TableIndex::Platforms:
            if (!ui->table_platforms->selectionModel()->hasSelection())
            {
                return;
            }
            editPlatform(ui->table_platforms->selectionModel()->selectedIndexes().first());
            break;
        case TableIndex::Emulators:
            if (!ui->table_emulators->selectionModel()->hasSelection())
            {
                return;
            }
            editEmulator(ui->table_emulators->selectionModel()->selectedIndexes().first());
            break;
    }
}

void MainWindow::removeRecords()
{
    switch (ui->tab_viewer->currentIndex())
    {
        case TableIndex::Games:
            if (!ui->table_games->selectionModel()->hasSelection())
            {
                return;
            }
            p_games_table_model->removeRows(ui->table_games->selectionModel()->selectedRows().first().row(), 1);
            break;
        case TableIndex::Platforms:
            if (!ui->table_platforms->selectionModel()->hasSelection())
            {
                return;
            }
            p_platforms_table_model->removeRows(ui->table_platforms->selectionModel()->selectedRows().first().row(), 1);
            break;
        case TableIndex::Emulators:
            if (!ui->table_emulators->selectionModel()->hasSelection())
            {
                return;
            }
            p_emulators_table_model->removeRows(ui->table_emulators->selectionModel()->selectedRows().first().row(), 1);
            break;
    }
}

void MainWindow::showAboutDialog()
{
    AboutDialog dialog;
    dialog.exec();
}

void MainWindow::setLanguageEnglish()
{
    setLanguage(QLocale("en_US"));
}

void MainWindow::setLanguageRussian()
{
    setLanguage(QLocale("ru_RU"));
}

