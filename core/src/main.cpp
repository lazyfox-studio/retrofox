#include <QtWidgets/QApplication>

#include "Window.h"
#include "interface/Widget.h"

int main(int argc, char *argv[])
{
    Interface::Widget;
    QApplication app(argc, argv);
    Window window;
    window.showFullScreen();
    return app.exec();
}
