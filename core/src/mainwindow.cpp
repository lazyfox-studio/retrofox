#include "mainwindow.h"

MainWindow::MainWindow(const std::string& title, int x, int y, int width, int height) 
    : Interface::Window(title, x, y, width, height)
{
    initialize();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initialize()
{
    auto temp = std::make_shared<GameMenu>(5, 5, 500, 700, 80);
    temp->showGames(renderer, "testbase.db");
    temp->reset();
    root_widget = temp;
}
