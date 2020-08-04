#include "interface/label.h"

namespace Interface
{
    void Label::updateSprite(SDL_Renderer* renderer)
    {
        if (renderer == nullptr)
            renderer = m_sprite.renderer();
        p_texture = p_font->renderText(renderer, m_text, m_color);
        m_sprite = { renderer, p_texture.get() };
    }

    Label::Label(SDL_Renderer* renderer, Graphics::Font* font, const std::string& text, SDL_Color color)
        : m_text(text), p_font(font), m_color(color)
    {
        p_texture = p_font->renderText(renderer, m_text, m_color);
        m_sprite = { renderer, p_texture.get() };
    }

    void Label::setX(int x)
    {
        m_sprite.setX(x);
        geometry.x = x;
    }

    void Label::setY(int y)
    {
        m_sprite.setY(y);
        geometry.y = y;
    }

    void Label::setHeight(unsigned height)
    {
        m_sprite.setHeight(height);
        geometry.height = height;
    }

    void Label::setWidth(unsigned width)
    {
        m_sprite.setWidth(width);
        geometry.width = width;
    }

    void Label::render()
    {
        m_sprite.render();
    }
    
    void Label::setText(const std::string& text)
    {
        m_text = text;
        updateSprite();
    }
}
