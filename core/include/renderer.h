#pragma once

#include <QOpenGLWidget>

#include <QOpenGLFunctions>

#pragma comment (lib, "opengl32.lib")

/**
 * @brief Rendering controller
 */
class Renderer : public QOpenGLWidget
{
private:
    QOpenGLFunctions* open_gl_functions;

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
};