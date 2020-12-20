#include "core/graphics/text.h"

namespace Graphics
{
    void Text::update()
    {
        p_texture = p_font->renderText(p_renderer, m_text, m_color);
    }

    Text::Text(SDL_Renderer* renderer, std::shared_ptr<Font> font, int x, int y, const std::string& text, SDL_Color color)
        : p_font(font), m_text(text), m_color(color)
    {
        p_renderer = renderer;
        p_texture = p_font->renderText(p_renderer, m_text, m_color);
        m_geometry = { x, y, p_texture->width(), p_texture->height() };
    }

    Text::~Text()
    {

    }

    std::shared_ptr<Graphics::Font> Text::font() const
    {
        return p_font;
    }

    const std::string& Text::text() const
    {
        return m_text;
    }

    SDL_Color Text::color() const
    {
        return m_color;
    }

    void Text::render()
    {
        SDL_Rect text_part = { 0, 0, m_geometry.w, m_geometry.h };
        SDL_RenderCopy(p_renderer, p_texture->texture(), &text_part, &m_geometry);
    }

    void Text::resetSize()
    {
        m_geometry.w = p_texture->width();
        m_geometry.h = p_texture->height();
    }
    
    void Text::setText(const std::string& text)
    {
        m_text = text;
        update();
    }

    void Text::setFontSize(int font_size)
    {
        p_font = Graphics::FontBuffer::instance().load(p_font->path(), font_size);
        update();
    }
}
