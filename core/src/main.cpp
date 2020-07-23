#include <QApplication>

#include "window.h"
#include "graphics/texturebuffer.h"


std::map<std::string, QImage*> Graphics::TextureBuffer::buffer;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;
    window.showFullScreen();
    return app.exec();
}
