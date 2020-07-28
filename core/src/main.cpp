#include <QApplication>

#include "window.h"
#include "graphics/texturebuffer.h"
#include "graphics/font.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;
    
    Renderer renderer(&window);

    renderer.resize(1280, 720);

    /*
    Graphics::Sprite test_sprite("../../core/data/testsprite.png");
    renderer.draw(&test_sprite);
    renderer.paintGL();
    */
    
    /*
    Graphics::Font font(renderer, "../../core/data/arial.ttf");
    font.renderText(renderer, "(C) LearnOpenGL.com", 540.0f, 570.0f, 0.5f, QColor(0.3, 0.7f, 0.9f));
    */

    window.showFullScreen();
    return app.exec();
}
