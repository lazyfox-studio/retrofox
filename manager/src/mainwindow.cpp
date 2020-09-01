#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto table_model = new GamesTableModel();
    ui->games_table->setModel(table_model);
    ui->games_table->horizontalHeader()->setStretchLastSection(true);
    ui->games_table->verticalHeader()->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

