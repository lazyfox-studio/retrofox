#include "core/mainwindow.h"

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
    auto layout = std::make_shared<Interface::Layout>(0, 0, geometry.h, geometry.w);
    layout->stacking = Interface::Layout::Stacking::Horizontal;

    auto gamemenu = std::make_shared<GameMenu>(5, 5, 400, 700, 80);
    gamemenu->showGames(renderer, "testbase.db");
    gamemenu->reset();
    layout->pushBack(gamemenu);
    gamemenu->reset();

    root_widget = layout;
}
