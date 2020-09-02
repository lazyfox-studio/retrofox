#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::setLanguage(const QString &locale)
{
    translator.load(QString("manager_") + locale, ":/ts");
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup games table
    games_table_model = new GamesTableModel();
    ui->games_table->setModel(games_table_model);
    ui->games_table->horizontalHeader()->setStretchLastSection(true);
    ui->games_table->verticalHeader()->setVisible(false);
    ui->games_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->games_table, &QTableView::doubleClicked, this, &MainWindow::editGame);
    connect(ui->action_english, &QAction::triggered, this, &MainWindow::setLanguageEnglish);
    connect(ui->action_russian, &QAction::triggered, this, &MainWindow::setLanguageRussian);
    translator.load("manager_en_US", ":/ts");
    qApp->installTranslator(&translator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::editGame(const QModelIndex &index)
{
    auto dialog = new GameEditDialog();
    auto game = games_table_model->game(index);
    dialog->loadGameData(game);
    dialog->exec();

    if (dialog->result() == QDialog::Accepted)
    {
        auto result_game = dialog->resultGameData();
        games_table_model->updateGame(result_game);
        games_table_model->updateRow(index);
    }
}

void MainWindow::setLanguageEnglish()
{
    setLanguage("en_US");
}

void MainWindow::setLanguageRussian()
{
    setLanguage("ru_RU");
}

