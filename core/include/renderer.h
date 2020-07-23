#pragma once

#include <QOpenGLWidget>

#include <QOpenGLFunctions>

#include <queue>

#include "graphics/sprite.h"

#pragma comment (lib, "opengl32.lib")

class Renderer : public QOpenGLWidget
{
private:
    std::queue<Graphics::Sprite*> sprite_queue;

    QOpenGLFunctions* opengl_functions;

public:
    Renderer(QWidget* parent = nullptr);

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    /**
     * @brief Render sprite in next frame
     * @param sprite Pointer to sprite
    */
    void draw(Graphics::Sprite* sprite);
};