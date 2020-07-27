#pragma once

#include <QOpenGLWidget>

#include <QOpenGLFunctions>

#include <queue>

#include "graphics/sprite.h"

#pragma comment (lib, "opengl32.lib")

/**
 * @brief Rendering controller
 */
class Renderer : public QOpenGLWidget
{
protected:
    /// Queue of sprites to visualize
    std::queue<Graphics::Sprite*> sprite_queue;

    /// OpenGL functions context pointer
    QOpenGLFunctions* opengl_functions;

    /**
     * @brief Visualizes sprite as GL texture
     * @param sprite Pointer to sprite
     */
    void visualizeSprite(Graphics::Sprite* sprite);

public:
    /**
     * @brief Default constructor
     * @param parent Parent widget if needed
     */
    Renderer(QWidget* parent = nullptr);


    /**
     * @brief Initializes GL context
     */
    void initializeGL();

    /**
     * @brief Resizes GL picture
     * @param width Frame width
     * @param height Frame height
     */
    void resizeGL(int width, int height);

    /**
     * @brief Paints GL picture
     */
    void paintGL();

    /**
     * @brief Render sprite in next frame
     * @param sprite Pointer to sprite
    */
    void draw(Graphics::Sprite* sprite);
};
