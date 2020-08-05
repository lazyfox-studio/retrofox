#include "graphics/text.h"

namespace Graphics
{
    void Text::update()
    {
        p_texture = p_font->renderText(p_renderer, m_text, m_color);
    }

    Text::Text(SDL_Renderer* renderer, std::shared_ptr<Graphics::Font> font, const std::string& text, SDL_Color color)
        : m_text(text), p_font(font), m_color(color)
    {
        p_renderer = renderer;
        p_texture = p_font->renderText(p_renderer, m_text, m_color);
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
    
    void Text::setText(const std::string& text)
    {
        m_text = text;
        update();
    }

    void Text::setTextHeight(int height)
    {
        p_font = Graphics::FontBuffer::instance().load(p_font->path(), height);
        update();
    }
}
