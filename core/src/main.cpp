#include <QApplication>

#include "window.h"
#include "interface/widget.h"


int main(int argc, char *argv[])
{
    Interface::Widget widget;
    QApplication app(argc, argv);
    Window window;
    window.showFullScreen();
    return app.exec();
}
