#include "renderer.h"

Renderer::Renderer(QWidget* parent) : QOpenGLWidget(parent)
{
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setVersion(2, 1);
    format.setProfile(QSurfaceFormat::CoreProfile);
    setFormat(format);
}

void Renderer::initializeGL()
{
    opengl_functions = QOpenGLContext::currentContext()->functions();
    opengl43_functions = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_4_3_Core>();

    opengl_functions->initializeOpenGLFunctions();
    opengl43_functions->initializeOpenGLFunctions();

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void Renderer::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1.0, 1.0);
    glViewport(0, 0, width, height);
    update();
}

void Renderer::paintGL()
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Graphics::Sprite test_sprite("../../core/data/testsprite.png");
    draw(&test_sprite);

    while (!sprite_queue.empty())
    {
        Graphics::Sprite* sprite = sprite_queue.front();
        sprite_queue.pop();
        visualizeSprite(sprite);
    }
}

void Renderer::draw(Graphics::Sprite* sprite)
{
    sprite_queue.push(sprite);
}

void Renderer::visualizeSprite(Graphics::Sprite* sprite)
{
    GLuint vbo_texture;
    glGenTextures(1, &vbo_texture);

    glBindTexture(GL_TEXTURE_2D, vbo_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sprite->texture()->width(), sprite->texture()->height(), 0, GL_BGRA, GL_UNSIGNED_BYTE,
        sprite->texture()->pixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);

    glColor3f(1.0, 1.0, 1.0);

    glTexCoord2i(0, 0);
    glVertex2i(sprite->x(), sprite->y());

    glTexCoord2i(0, 1);
    glVertex2i(sprite->x(), sprite->y() + sprite->width());

    glTexCoord2i(1, 1);
    glVertex2i(sprite->x() + sprite->height(), sprite->y() + sprite->width());

    glTexCoord2i(1, 0);
    glVertex2i(sprite->x() + sprite->height(), sprite->y());

    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}

QOpenGLFunctions* Renderer::functions()
{
    return opengl_functions;
}

QOpenGLFunctions_4_3_Core* Renderer::functions43()
{
    return opengl43_functions;
}
