#include "mainwindow.h"
#include "..\include\interface\window.h"

MainWindow::MainWindow(std::string title, int x, int y, int width, int height) :
    Interface::Window(title, x, y, width, height)
{
    initialize();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initialize()
{
    auto temp = std::make_shared<GameMenu>(5, 5, 500, 700, 80);
    temp.get()->showGames(renderer, "testbase.db");
    temp.get()->reset();
    root_widget = temp;
}