#include "graphics/font.h"

Graphics::Font::Font(const char* ttf_path, int font_size)
{
    FT_Library ft;
    FT_Face face;

    if (FT_Init_FreeType(&ft))
        throw "FreeType Init fail";

    if (FT_New_Face(ft, ttf_path, 0, &face))
        throw "Font Facing fail";

    FT_Set_Pixel_Sizes(face, 0, font_size);

    for (GLubyte c = 0; c < 128; c++)
    {
        // Load character glyph
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            throw "Failed to load glyph";
            continue;
        }
        // Now store character for later use
        Character character = {
            new uchar[face->glyph->bitmap.width * face->glyph->bitmap.rows],
            0,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            face->glyph->bitmap_left,
            face->glyph->bitmap_top,
            static_cast<GLuint>(face->glyph->advance.x)
        };
        memcpy(character.glyph, face->glyph->bitmap.buffer, sizeof(uchar) * face->glyph->bitmap.width * face->glyph->bitmap.rows);
        // TODO: memory free
        chars.insert(std::pair<GLchar, Character>(c, character));
        // Characters[c] = character;
    }

    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}

Graphics::Font::~Font()
{
    
}

Graphics::Font::Character& Graphics::Font::character(GLubyte ch)
{
    return chars[ch];
}
