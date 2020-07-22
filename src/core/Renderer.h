#pragma once

#include <QOpenGLWidget>

class Renderer : public QOpenGLWidget
{
public:
    Renderer(QWidget* parent = nullptr);

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
};