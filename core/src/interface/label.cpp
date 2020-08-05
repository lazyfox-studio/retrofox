#include "interface/label.h"

namespace Interface
{
    Label::Label(SDL_Renderer* renderer, std::shared_ptr<Graphics::Font> font, int x, int y, const std::string& text)
        : m_text(renderer, font, text)
    {
        geometry.x = x;
        geometry.y = y;
        geometry.height = m_text.height();
        geometry.width = m_text.width();
    }

    Label::~Label()
    {

    }

    void Label::setHeight(unsigned height)
    {
        m_text.setTextHeight(height);
        m_text.setHeight(height);
        geometry.height = height;
    }

    void Label::setWidth(unsigned width)
    {
        geometry.width = width;
        m_text.setWidth(width);
    }

    void Label::render()
    {
        m_text.render();
    }
}