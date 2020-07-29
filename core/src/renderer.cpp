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
    opengl_functions = QOpenGLContext::currentContext()->functions();
    opengl43_functions = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_4_3_Core>();

    //opengl_functions->initializeOpenGLFunctions();
    opengl43_functions->initializeOpenGLFunctions();

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void Renderer::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1.0, 1.0);
    glViewport(0, 0, width, height);
    update();
}

void Renderer::paintGL()
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Graphics::Sprite test_sprite("../../core/data/testsprite.png");
    //draw(&test_sprite);

    while (!sprite_queue.empty())
    {
        Graphics::Sprite* sprite = sprite_queue.front();
        sprite_queue.pop();
        visualizeSprite(sprite);
    }
}

void Renderer::draw(Graphics::Sprite* sprite)
{
    sprite_queue.push(sprite);
}


void Renderer::visualizeSprite(Graphics::Sprite* sprite)
{
    GLuint vbo_texture;
    glGenTextures(1, &vbo_texture);

    glBindTexture(GL_TEXTURE_2D, vbo_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sprite->texture()->width(), sprite->texture()->height(), 0, GL_BGRA, GL_UNSIGNED_BYTE,
        sprite->texture()->pixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);

    glColor3f(1.0, 1.0, 1.0);

    glTexCoord2i(0, 0);
    glVertex2i(sprite->x(), sprite->y());

    glTexCoord2i(0, 1);
    glVertex2i(sprite->x(), sprite->y() + sprite->width());

    glTexCoord2i(1, 1);
    glVertex2i(sprite->x() + sprite->height(), sprite->y() + sprite->width());

    glTexCoord2i(1, 0);
    glVertex2i(sprite->x() + sprite->height(), sprite->y());

    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Renderer::texturizeFont(Graphics::Font& font)
{
    for (GLubyte c = 0; c < 128; c++)
    {
        auto& ch = font.character(c);
        glGenTextures(1, &(ch.texture_name));
        glBindTexture(GL_TEXTURE_2D, ch.texture_name);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ch.width, ch.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, ch.glyph);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

void Renderer::visualizeText(Graphics::Font& font, const std::string& text)
{
    //glEnable(GL_BLEND); // ???
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //for (auto c : text) 
    {
        auto& ch = font.character('T'); // test
        if (ch.texture_name == 0) // analogue in texturizeFont
        {
            glGenTextures(1, &(ch.texture_name));
            glBindTexture(GL_TEXTURE_2D, ch.texture_name);
            //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ch.width, ch.height, 0, GL_ALPHA8, GL_UNSIGNED_BYTE, ch.glyph);
            //glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, ch.width, ch.height, 0, GL_RED, GL_UNSIGNED_BYTE, ch.glyph);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ch.width, ch.height, 0, GL_RED, GL_UNSIGNED_BYTE, ch.glyph);
            // maybe problem in formats (GL_RGBA / GL_ALPHA8 / GL_RED)? glyph is stored in 8 bit grayscale (or alpha)
        }
        else
            glBindTexture(GL_TEXTURE_2D, ch.texture_name);

        //QImage image(ch.glyph, ch.width, ch.height, QImage::Format::Format_Alpha8);
        //image.save("./Tglyph.png");

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //glEnable(GL_TEXTURE_2D);

        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glTexCoord2i(0, 0);
        glVertex2i(0, 1);
        glTexCoord2i(0, 1);
        glVertex2i(0, 1 + ch.width);
        glTexCoord2i(1, 1);
        glVertex2i(0 + ch.height, 1 + ch.width);
        glTexCoord2i(1, 0);
        glVertex2i(0 + ch.height, 1);
        glEnd();
        //glBindTexture(GL_TEXTURE_2D, 0);
    }

    //glDisable(GL_BLEND);
}

QOpenGLFunctions* Renderer::functions()
{
    return opengl_functions;
}

QOpenGLFunctions_4_3_Core* Renderer::functions43()
{
    return opengl43_functions;
}
