#pragma once

#include <QOpenGLWidget>

#include <QOpenGLFunctions>

#pragma comment (lib, "opengl32.lib")

class Renderer : public QOpenGLWidget
{
private:
    QOpenGLFunctions* open_gl_functions;

public:
    Renderer(QWidget* parent = nullptr);

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
};