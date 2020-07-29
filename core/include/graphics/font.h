#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include <QOpenGLFunctions>

#include <map>

namespace Graphics
{
    class Font
    {
    public:
        struct Character
        {
            uchar* glyph;
            GLuint texture_name;
            unsigned width, height;
            int bearing_x, bearing_y;
            GLuint advance;
        };

    protected:
        std::map<GLchar, Character> chars;

    public:
        Font() = delete;
        explicit Font(const char* ttf_path, int font_size = 48);
        ~Font();

        Character& character(GLubyte ch);
    };
}
