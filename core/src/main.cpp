#include <QtWidgets/QApplication>

#include "window.h"


int main(int argc, char *argv[])
{
    Interface::Widget widget;
    QApplication app(argc, argv);
    Window window;
    window.showFullScreen();
    return app.exec();
}
