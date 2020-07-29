#include <QApplication>

#include "window.h"
#include "graphics/texturebuffer.h"
#include "graphics/font.h"
#include "renderer.h"

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
    
    window.showFullScreen();

    Graphics::Font font("../../core/data/arial.ttf", 50);
    renderer.visualizeText(font, "TESt");
    renderer.paintGL();

    return app.exec();
}
