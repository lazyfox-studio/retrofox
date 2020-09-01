#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup games table
    auto table_model = new GamesTableModel();
    ui->games_table->setModel(table_model);
    ui->games_table->horizontalHeader()->setStretchLastSection(true);
    ui->games_table->verticalHeader()->setVisible(false);
    ui->games_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->games_table, &QTableView::doubleClicked, this, &MainWindow::editGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::editGame(const QModelIndex &index)
{
    auto dialog = new GameEditDialog();
    dialog->exec();
}

