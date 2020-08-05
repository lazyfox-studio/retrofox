#include "graphics/label.h"

namespace Graphics
{
    void Label::update()
    {
        p_texture = p_font->renderText(p_renderer, m_text, m_color);
    }

    Label::Label(SDL_Renderer* renderer, Graphics::Font* font, const std::string& text, SDL_Color color)
        : m_text(text), p_font(font), m_color(color)
    {
        p_renderer = renderer;
        p_texture = p_font->renderText(p_renderer, m_text, m_color);
        m_geometry = { 0, 0, p_texture->width(), p_texture->height() };
    }

    Label::~Label()
    {

    }
    
    void Label::setText(const std::string& text)
    {
        m_text = text;
        update();
    }
}
