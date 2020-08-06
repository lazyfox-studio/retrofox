#include "graphics/text.h"

namespace Graphics
{
    Text::Text(SDL_Renderer* renderer, FontPtr font, const std::string& text, SDL_Color color)
        : p_font(font), m_color(color)
    {
        p_renderer = renderer;
        p_texture = p_font->renderText(p_renderer, text, m_color);
        m_geometry = { 0, 0, p_texture->width(), p_texture->height() };
    }

    Text::~Text()
    {

    }

    void Text::render()
    {
        SDL_Rect text_part = { 0, 0, m_geometry.w, m_geometry.h };
        SDL_RenderCopy(p_renderer, p_texture->texture(), &text_part, &m_geometry);
    }

    void Text::resetSize()
    {
        m_geometry = { 0, 0, p_texture->width(), p_texture->height() };
    }
    
    void Text::setText(const std::string& text)
    {
        p_texture = p_font->renderText(p_renderer, text, m_color);
    }

    void Text::setFontSize(int font_size)
    {
        p_font = Graphics::FontBuffer::instance().load(p_font->path(), font_size);
        update();
    }
}
