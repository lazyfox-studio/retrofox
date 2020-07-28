#include "graphics/font.h"

Graphics::Font::Font(Renderer& renderer, const char* ttfPath, int fontSize)
{
    auto F = renderer.functions43();
    //auto F = this;
    //initializeOpenGLFunctions();
    if (FT_Init_FreeType(&ft))
        throw "FreeType Init fail";

    if (FT_New_Face(ft, ttfPath, 0, &face))
        throw "Font Facing fail";

    FT_Set_Pixel_Sizes(face, 0, fontSize);

    F->glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Disable byte-alignment restriction

    for (GLubyte c = 0; c < 128; c++)
    {
        // Load character glyph
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            qDebug() << "Failed to load glyph";
            continue;
        }
        // Generate texture
        GLuint texture;
        F->glGenTextures(1, &texture);
        F->glBindTexture(GL_TEXTURE_2D, texture);
        F->glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );
        // Set texture options
        F->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        F->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        F->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        F->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // Now store character for later use
        Character character = {
            texture,
            static_cast<int>(face->glyph->bitmap.width), 
            static_cast<int>(face->glyph->bitmap.rows),
            face->glyph->bitmap_left,
            face->glyph->bitmap_top,
            static_cast<GLuint>(face->glyph->advance.x)
        };
        chars.insert(std::pair<GLchar, Character>(c, character));
        // Characters[c] = character;
    }

    // Enable blending
    F->glEnable(GL_BLEND);
    F->glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    F->glGenVertexArrays(1, &VAO);
    F->glGenBuffers(1, &VBO);
    F->glBindVertexArray(VAO);
    F->glBindBuffer(GL_ARRAY_BUFFER, VBO);
    F->glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    F->glEnableVertexAttribArray(0);
    F->glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
    F->glBindBuffer(GL_ARRAY_BUFFER, 0);
    F->glBindVertexArray(0);

    QOpenGLShader vert(QOpenGLShader::Vertex);
    vert.compileSourceFile("../../core/glsl/fontvert.glsl");
    QOpenGLShader frag(QOpenGLShader::Fragment);
    frag.compileSourceFile("../../core/glsl/fontfrag.glsl");
    program.addShader(&vert);
    program.addShader(&frag);
    if (!program.link())
    {
        qDebug() << "Error while linking\n";
        return;
    }

}

Graphics::Font::~Font()
{
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}

void Graphics::Font::setUpRenderer(Renderer& renderer)
{
}

void Graphics::Font::renderText(Renderer& renderer, const std::string& text, GLfloat x, GLfloat y, GLfloat scale, QColor color)
{
    QMatrix4x4 projection;
    projection.setToIdentity();
    projection.ortho(0, 800, 0, 600, -1, 1);

    auto F = renderer.functions43();
    //F->initializeOpenGLFunctions();

    //auto F = this;

    program.bind();
    program.setUniformValue("textColor", color);
    program.setUniformValue("projection", projection);
    F->glActiveTexture(GL_TEXTURE0);
    F->glBindVertexArray(VAO);

    // Iterate through all characters
    for (auto c : text)
    {
        Character ch = chars[c];

        GLfloat xpos = x + ch.bearing_x * scale;
        GLfloat ypos = y - (ch.size_y - ch.bearing_y) * scale;

        GLfloat w = ch.size_x * scale;
        GLfloat h = ch.size_y * scale;
        // Update VBO for each character
        GLfloat vertices[6][4] = {
            { xpos, ypos + h, 0.0, 0.0 },
            { xpos, ypos, 0.0, 1.0 },
            { xpos + w, ypos, 1.0, 1.0 },
            { xpos, ypos + h, 0.0, 0.0 },
            { xpos + w, ypos, 1.0, 1.0 },
            { xpos + w, ypos + h, 1.0, 0.0 }
        };
        // Render glyph texture over quad
        F->glBindTexture(GL_TEXTURE_2D, ch.texture_name);
        // Update content of VBO memory
        F->glBindBuffer(GL_ARRAY_BUFFER, VBO);
        F->glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        F->glBindBuffer(GL_ARRAY_BUFFER, 0);
        // Render quad
        F->glDrawArrays(GL_TRIANGLES, 0, 6);
        // Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        x += (ch.advance >> 6)* scale; // Bitshift by 6 to get value in pixels (2^6 = 64)
    }
    F->glBindVertexArray(0);
    F->glBindTexture(GL_TEXTURE_2D, 0);

    program.release();
}
