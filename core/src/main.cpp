#include <QtWidgets/QApplication>

#include "window.h"
#include "interface/widget.h"

int main(int argc, char *argv[])
{
    Interface::Widget;
    QApplication app(argc, argv);
    Window window;
    window.showFullScreen();
    return app.exec();
}
