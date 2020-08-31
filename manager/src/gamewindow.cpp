#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(std::string path, std::string name) : QWidget(), ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    ui->path->setText(path.c_str());
    ui->name->setText(name.c_str());
}

GameWindow::~GameWindow()
{
    delete ui;
}
