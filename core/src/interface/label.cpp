#include "interface/label.h"

namespace Interface
{
    Label::Label(SDL_Renderer* renderer, Graphics::Font* font, int x, int y, unsigned height, const std::string& text)
        : m_text(renderer, font, text)
    {
        geometry.x = x;
        geometry.y = y;
        geometry.height = m_text.height();
        geometry.width = m_text.width();
        setHeight(height);
    }

    Label::~Label()
    {

    }

    void Label::setHeight(unsigned height)
    {
        double coef = (double) height / (double) geometry.height;
        m_text.setHeight(height);
        m_text.setWidth(geometry.width * coef);
        geometry.height = height;
    }

    void Label::setWidth(unsigned width)
    {
        if (width < geometry.width)
        {
            double coef = (double) width / (double) geometry.height;
            m_text.setWidth(width);
            m_text.setWidth(geometry.height * coef);
        }
        geometry.width = width;
    }

    void Label::render()
    {
        m_text.render();
    }
}