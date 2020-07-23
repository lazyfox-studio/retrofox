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
    open_gl_functions = QOpenGLContext::currentContext()->functions();

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Renderer::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1.0, 1.0);
    glViewport(0, 0, width, height);
    update();
}

void Renderer::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Graphic test

    glBegin(GL_QUADS);

    glColor3f(1, 0.5, 0.5);
    glVertex2i(100, 100);
    glVertex2i(300, 600);
    glVertex2i(800, 600);
    glVertex2i(500, 100);

    glEnd();
}