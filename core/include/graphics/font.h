#pragma once

#include "renderer.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <QMatrix4x4>
#include <QColor>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QOpenGLShaderProgram>
#include <QOpenGLFunctions_4_3_Core>

#include <map>

namespace Graphics
{
    class Font : protected QOpenGLFunctions_4_3_Core
    {
    protected:
        FT_Library ft;

        FT_Face face;

        QOpenGLShaderProgram program;

        struct Character
        {
            GLuint texture_name;
            int size_x, size_y;
            int bearing_x, bearing_y;
            GLuint advance;
        };
        std::map<GLchar, Character> chars;

        GLuint VAO, VBO;

    public:
        Font() = delete;
        explicit Font(Renderer& renderer, const char* ttfPath, int fontSize = 48);
        ~Font();

        void setUpRenderer(Renderer& renderer);

        void renderText(Renderer& renderer, const std::string& text, GLfloat x, GLfloat y, GLfloat scale, QColor color);

    };
}
