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
    //auto temp = std::make_shared<GameMenu>(5, 5, 400, 700, 80);
    //temp->showGames(renderer, "testbase.db");
    //temp->reset();
    //root_widget = temp;
    auto layout = std::make_shared<Interface::Layout>(5, 5, 500, 500);
    layout->stacking = Interface::Layout::Stacking::Horizontal;
    auto button1 = std::make_shared<Interface::Button>(renderer, "../../core/data/testsprite.bmp", "../../core/data/testsprite.bmp");
    auto button2 = std::make_shared<Interface::Button>(renderer, "../../core/data/testsprite.bmp", "../../core/data/testsprite.bmp");
    layout->pushBack(button1);
    layout->pushBack(button2);
    root_widget = layout;
}
